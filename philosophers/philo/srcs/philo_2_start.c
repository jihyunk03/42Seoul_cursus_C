/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_2_start.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 03:32:07 by jihykim2          #+#    #+#             */
/*   Updated: 2023/08/18 17:37:56 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void	*start_routine(void *ph);
static void	*_one_philo_routine(t_philo *philo, t_data *data);

int	start_philo(t_philo *philo, t_data *data)
{
	int	i;

	i = 0;
	data->start_t = current_time();
	while (i < data->philosophers)
	{
		if (pthread_create(&philo[i].tid, NULL, start_routine, &philo[i]))
			return (error_exit(philo, data, PHILO_ERR));
		i++;
	}
	free_philo(philo, data->philosophers);
	free_data(data);
	return (EXIT_SUCCESS);
}

static void	*start_routine(void *ph)
{
	t_philo	*philo;
	t_data	*data;

	philo = (t_philo *)ph;
	data = philo->data;
	philo->last_eat = data->start_t;
	if (data->philosophers == 1)
		return (_one_philo_routine(philo, data));
	if (philo->id % 2 == 0)
		usleep(sleep_even_philo(data));
	while (TRUE)
	{
		if (ph_eat(philo, data) == END)
			break ;
		if (ph_sleep_and_think(philo, data) == END)
			break ;
		usleep(200);
	}
	return (NULL);
}

static void	*_one_philo_routine(t_philo *philo, t_data *data)
{
	pthread_mutex_lock(&data->forks[philo->left]);
	data->fork_state[philo->left] = USING;
	print_message(philo, FORK);
	pthread_mutex_unlock(&data->forks[philo->left]);
	while (current_time() - data->start_t < data->die_t)
		usleep(500);
	print_dead(philo, data);
	pthread_mutex_lock(&data->forks[philo->left]);
	data->fork_state[philo->left] = AVAILABLE;
	pthread_mutex_unlock(&data->forks[philo->left]);
	return (NULL);
}

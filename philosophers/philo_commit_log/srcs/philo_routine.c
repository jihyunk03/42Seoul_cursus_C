/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 08:52:17 by jihykim2          #+#    #+#             */
/*   Updated: 2023/08/14 21:18:45 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	_ph_eat(t_philo *philo, t_data *data);
static int	_ph_pick_fork(t_philo *philo, t_data *data);
static int	_ph_is_eating(t_philo *philo, t_data *data, long long eat_start);
static int	_ph_sleep_and_think(t_philo *philo, t_data *data);

void	*start_routine(void *ph)
{
	t_philo	*philo;
	t_data	*data;

	philo = (t_philo *)ph;
	data = philo->data;
	philo->last_eat = current_time();
	while (TRUE)
	{
		if (_ph_eat(philo, data) == END)
			break ;
		if (data->must_eat > -1 && philo->eat_cnt == data->must_eat)
			break ;
		if (_ph_sleep_and_think(philo, data) == END)
			break ;
	}
	return (NULL);
}

static int	_ph_eat(t_philo *philo, t_data *data)
{
	// if (data->philosophers == 1)
	// {
	// 	pthread_mutex_lock(&data->f_state[philo->left]);
	// 	print_message(philo, FORK);
	// 	pthread_mutex_unlock(&data->f_state[philo->right]);
	// 	while (philo_dead(philo, data) == FALSE)
	// 		;
	// 	return (END);
	// }
	if (_ph_pick_fork(philo, data) == END)
		return (END);
	if (_ph_is_eating(philo, data, current_time()) == END)
		return (END);
	pthread_mutex_lock(&data->f_state[philo->right]);
	data->forks[philo->right] = FALSE;
	pthread_mutex_unlock(&data->f_state[philo->right]);
	pthread_mutex_lock(&data->f_state[philo->left]);
	data->forks[philo->left] = FALSE;
	pthread_mutex_unlock(&data->f_state[philo->left]);
	usleep(10);
	return (CONTINUE);
}

static int	_ph_pick_fork(t_philo *philo, t_data *data)
{
	while (check_dead(philo, data) == FALSE)
	{
		pthread_mutex_lock(&data->f_state[philo->left]);
		if (data->forks[philo->left] == TRUE)
		{
			pthread_mutex_unlock(&data->f_state[philo->left]);
			continue ;
		}
		data->forks[philo->left] = TRUE;
		pthread_mutex_unlock(&data->f_state[philo->left]);

		pthread_mutex_lock(&data->f_state[philo->right]);
		if (data->forks[philo->right] == FALSE)
		{
			data->forks[philo->right] = TRUE;
			pthread_mutex_unlock(&data->f_state[philo->right]);
			print_message(philo, FORK);
			print_message(philo, FORK);
			return (CONTINUE);
		}
		pthread_mutex_unlock(&data->f_state[philo->right]);
		pthread_mutex_lock(&data->f_state[philo->left]);
		data->forks[philo->left] = FALSE;
		pthread_mutex_unlock(&data->f_state[philo->left]);
	}
	return (END);
}

static int	_ph_is_eating(t_philo *philo, t_data *data, long long eat_start)
{
	print_message(philo, EAT);
	++philo->eat_cnt;
	while (current_time() - eat_start < data->eat_t)
	{
		if (check_dead(philo, data) == TRUE)
		{
			pthread_mutex_lock(&data->f_state[philo->left]);
			data->forks[philo->left] = FALSE;
			pthread_mutex_unlock(&data->f_state[philo->left]);
			pthread_mutex_lock(&data->f_state[philo->right]);
			data->forks[philo->right] = FALSE;
			pthread_mutex_unlock(&data->f_state[philo->right]);
			return (END);
		}
		usleep(200);
	}
	philo->last_eat = current_time();
	return (CONTINUE);
}

static int	_ph_sleep_and_think(t_philo *philo, t_data *data)
{
	print_message(philo, SLEEP);
	while (current_time() - philo->last_eat < data->sleep_t) {
		if (check_dead(philo, data) == TRUE)
			return (END);
		usleep(100);
	}
	print_message(philo, THINK);
	if (check_dead(philo, data) == TRUE)
		return (END);
	return (CONTINUE);
}

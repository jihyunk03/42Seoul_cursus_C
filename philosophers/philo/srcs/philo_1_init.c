/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_1_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 16:04:10 by jihykim2          #+#    #+#             */
/*   Updated: 2023/08/18 19:46:46 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	_check_is_digit(int ac, char **arg);
static int	_init_mutex(t_data *data);

int	init_data(t_data *data, int ac, char **av)
{
	memset(data, 0, sizeof(t_data));
	if (_check_is_digit(ac, av) == FALSE)
		return (ARG_ERR);
	data->philosophers = ft_atoi(av[1]);
	data->die_t = ft_atoi(av[2]);
	data->eat_t = ft_atoi(av[3]);
	data->sleep_t = ft_atoi(av[4]);
	data->must_eat = -1;
	if (ac == 6)
		data->must_eat = ft_atoi(av[5]);
	if (data->philosophers < 1 || data->die_t < 0 || data->eat_t < 0 \
	|| data->sleep_t < 0 || (ac == 6 && data->must_eat < 0))
		return (ARG_ERR);
	data->fork_state = ft_calloc(data->philosophers, sizeof(int));
	if (data->fork_state == NULL)
		return (ALLOC_FAIL);
	return (_init_mutex(data));
}

static int	_check_is_digit(int ac, char **arg)
{
	int	i;
	int	j;

	i = 0;
	while (++i < ac)
	{
		j = 0;
		while (arg[i][j])
			if (ft_isdigit(arg[i][j++]) == FALSE)
				return (FALSE);
	}
	return (TRUE);
}

static int	_init_mutex(t_data *data)
{
	int	i;

	data->forks = malloc(sizeof(pthread_mutex_t) * data->philosophers);
	if (data->forks == NULL)
		return (ALLOC_FAIL);
	i = 0;
	while (i < data->philosophers)
		if (pthread_mutex_init(&data->forks[i++], NULL) != 0)
			return (MUTEX_ERR);
	if (pthread_mutex_init(&data->dead, NULL) != 0 \
	|| pthread_mutex_init(&data->print, NULL) != 0)
		return (MUTEX_ERR);
	return (SUCCESS);
}

t_philo	*init_philo(t_data *data)
{
	t_philo	*philo;
	int		i;

	philo = malloc(sizeof(t_philo) * data->philosophers);
	if (philo == NULL)
		return (NULL);
	i = 0;
	while (i < data->philosophers)
	{
		philo[i].data = data;
		philo[i].id = i + 1;
		philo[i].left = i;
		philo[i].right = (i + 1) % data->philosophers;
		philo[i].eat_cnt = 0;
		i++;
	}
	return (philo);
}

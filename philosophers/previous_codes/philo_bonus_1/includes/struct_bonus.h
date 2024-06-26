/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 20:07:47 by jihykim2          #+#    #+#             */
/*   Updated: 2023/08/19 17:20:23 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_BONUS_H
# define STRUCT_BONUS_H

# include "./header_bonus.h"

typedef struct s_data	// [NO shared memory]
{
	int			philosophers;
	int			die_t;
	int			eat_t;
	int			sleep_t;
	int			must_eat;
	long long	start_t;
	sem_t		*forks;
	int			fork_count;
	sem_t		*dead;
	int			someone_dead;
	sem_t		*print;
	int			no_print;		// for check dead for stop printing
}	t_data;

typedef struct s_philo
{
	struct s_data	*data;
	pid_t			pid;
	int				id;
	int				eat_cnt;
	long long		last_eat;
	pthread_t		monitor;	// monitoring thread 있어야 함
}	t_philo;

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 18:08:40 by jihykim2          #+#    #+#             */
/*   Updated: 2023/08/20 21:55:29 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include "./struct_bonus.h"
# include "./define_bonus.h"
# include "./header_bonus.h"

/* philo_1_init */
t_philo		*init_philo(int ac, char **av);

/* philo_2_child_process */
void		child_routine(t_philo *philo);

/* philo_2_parent_process */
void		wait_and_check_child(t_philo *philo);

/* message_print */
void		print_message(t_philo *philo, char *message);

/* get_time_utils */
long long	current_time(void);
int			sleep_even_philo(int die_time, int eat_time);

/* libft_utils */
void		ft_putstr_fd(char *s, int fd);
int			ft_isdigit(int c);
void		*ft_calloc(size_t count, size_t size);
void		ft_bzero(void *s, size_t n);
int			ft_atoi(const char *str);
char		*ft_itoa(int n);

/* free_and_exit */
int			error_exit(t_philo *philo, int errno);
void		free_philo(t_philo *philo);

#endif

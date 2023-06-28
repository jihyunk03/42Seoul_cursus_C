/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 04:53:02 by jihykim2          #+#    #+#             */
/*   Updated: 2023/06/28 22:25:31 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	error_exit(char *s, int true)
{
	if (true)
	{
		perror(s);
		return (errno);
	}
	ft_putchar_fd(s, STDERR_FILENO);
	return (EXIT_FAILURE);
}

int	error_no_command(t_pipe *p)
{
	ft_putstr_fd("pipex: ", STDERR_FILENO);
	ft_putstr_fd(p->cmd_args[0], STDERR_FILENO);
	ft_putstr_fd(": command not found\n", STDERR_FILENO);
	free_arr_args(p->cmd_args);
	return (127);
}

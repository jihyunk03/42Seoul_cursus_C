/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 07:35:15 by jihykim2          #+#    #+#             */
/*   Updated: 2023/09/02 20:49:59 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_pipex/pipex.h"

static void	_begin_child_process(t_pipe *p, char *infile);
static void	_mid_child_process(t_pipe *p);
static void	_end_child_process(t_pipe *p, char *outfile);

void	parent_process(t_pipe *p)
{
	close(p->pipe[P_WRITE]);
	if (dup2(p->pipe[P_READ], STDIN_FILENO) == -1)
		perror("dup2(stdin)");
	close(p->pipe[P_READ]);
}

void	child_process(t_pipe *p, int idx, int ac, char **av)
{
	close(p->pipe[P_READ]);
	if (idx == 2 || (p->here_doc && idx == 3))
		_begin_child_process(p, av[1]);
	else if (idx < ac - 2)
		_mid_child_process(p);
	else
		_end_child_process(p, av[ac - 1]);
	exec_command(p);
}

static void	_begin_child_process(t_pipe *p, char *infile)
{
	error_check_file_fds(p->in_fd, infile);
	if (dup2(p->in_fd, STDIN_FILENO) == -1)
		perror("dup2(infile)");
	close(p->in_fd);
	if (dup2(p->pipe[P_WRITE], STDOUT_FILENO) == -1)
		perror("dup2(pipe_write)");
	close(p->pipe[P_WRITE]);
}

static void	_mid_child_process(t_pipe *p)
{
	if (dup2(p->pipe[P_WRITE], STDOUT_FILENO) == -1)
		perror("dup2(pipe_write)");
	close(p->pipe[P_WRITE]);
}

static void	_end_child_process(t_pipe *p, char *outfile)
{
	close(p->pipe[P_WRITE]);
	error_check_file_fds(p->out_fd, outfile);
	if (dup2(p->out_fd, STDOUT_FILENO) == -1)
		perror("dup2(stdout)");
	close(p->out_fd);
}

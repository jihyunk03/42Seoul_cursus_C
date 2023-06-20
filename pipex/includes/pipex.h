/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 15:52:12 by jihykim2          #+#    #+#             */
/*   Updated: 2023/06/19 17:45:45 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

/* includes for my_libft */
# include "../my_libft/libft.h"
# include "../my_libft/ft_printf.h"
# include "../my_libft/get_next_line.h"

/* includes of structs and defines */
# include "./struct.h"

/* includes of functions */
# include <unistd.h>	// open, read, write, close, access, unlink, fork, dup, dup2, pipe, execve
# include <sys/wait.h>	// wait, waitpid
# include <stdlib.h>	// malloc, free, exit
# include <fcntl.h>		// macro for functions(open, unlink)
# include <stdio.h>		// perror
# include <string.h>	// strerror

/* functions */
t_pipe	*init_pipe(int ac, char **av, char **env);

#endif
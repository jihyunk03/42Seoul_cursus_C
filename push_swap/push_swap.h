/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 17:05:43 by jihykim2          #+#    #+#             */
/*   Updated: 2023/02/13 01:37:51 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./my_libft/libft.h"
# include "./my_libft/ft_printf.h"
# include "struct_info.h"
# include "define_enum.h"

// push_swap.c
void	sort_to_b(t_stack * a_stack, t_stack *b_stack);
void	sort_to_a(t_stack * a_stack, t_stack *b_stack);
void	a_to_b(t_stack *a_stack, t_stack *b_stack, int num, int chunk);

// stack_init.c
t_stack	*stack_init(char **data);
t_stack	*new_stack(void);
t_dll	*new_dll(int data, int flag);

// stack_init_utils.c
int		push_to_stack(t_stack *new, char *data);
int		is_integer(char *s);
int		push_swap_atoi(const char *str, int *flag);
int		dll_add_back(t_stack *new, t_dll *lst);
void	index_init(t_stack *stack);

// free_all.c
void	*free_stack(t_stack *stack);
int		free_dll(t_dll *lst);
int		free_arr(char **arr);

// check_sort.c
int		check_sort(t_stack *stack, int size);

// [ 모래시계 ]
// a_sort_to_b.c
void	sort_to_b(t_stack *a_stack, t_stack *b_stack);
void	a_to_b(t_stack *a_stack, t_stack *b_stack, int num, int chunk);
int		init_chunck(int size);
int		is_in_stack(t_stack *stack, int num);

// b_sort_to_a.c
void	sort_to_a(t_stack *a_stack, t_stack *b_stack);
int		find_value(t_stack *stack, int value);
void	rotate_for_push(t_stack *b_stack, int cnt);

// operator.c
void	swap(t_stack *stack, char *op);
void	swap_both(t_stack *a_stack, t_stack *b_stack, char *op);
void	do_swap(t_stack *stack);
void	push(t_stack *from, t_stack *to, char *op);
void	do_push(t_stack *from, t_stack *to);
void	rotate(t_stack *stack, char *op);
void	rotate_both(t_stack *a_stack, t_stack *b_stack, char *op);
void	do_rotate(t_stack *stack);
void	rv_rotate(t_stack *stack, char *op);
void	rv_rotate_both(t_stack *a_stack, t_stack *b_stack, char *op);
void	do_rv_rotate(t_stack *stack);

// libft prototypes for test & check leaks => must remove!!
void 	check_leak(void);
void	check_operator_result(t_stack *stack, char *op);
void	check_stack_idx(t_stack *stack);

#endif

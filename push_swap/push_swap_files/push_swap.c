/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 13:23:41 by jihykim2          #+#    #+#             */
/*   Updated: 2023/03/18 13:29:34 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	check_leaks(void);

int	main(int ac, char **av)
{
	t_stack	*a_stack;
	t_stack	*b_stack;

	if (ac < 2)
		return (EXIT_SUCCESS);
	a_stack = stack_init(av);
	b_stack = new_stack();
	if (a_stack == NULL || b_stack == NULL)
		return (free_for_exit(a_stack, b_stack, FALSE));
	if (check_sort(a_stack, a_stack->size) == FALSE)
	{
		if (a_stack->size <= 5)
			short_sort(a_stack, b_stack);
		else
		{
			a_sort_to_b(a_stack, b_stack);
			b_sort_to_a(a_stack, b_stack);
		}
	}
	return (free_for_exit(a_stack, b_stack, TRUE));
}

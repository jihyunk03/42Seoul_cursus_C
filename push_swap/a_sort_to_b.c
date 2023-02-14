/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_sort_to_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 01:15:43 by jihykim2          #+#    #+#             */
/*   Updated: 2023/02/14 13:52:10 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*decide_command(t_stack *stack, int num, int chunk);
static int	init_chunck(int size);

void	sort_to_b(t_stack *a_stack, t_stack *b_stack)
{
	int		num;
	int		chunk;
	char	*cmd;

	num = 0;
	chunk = init_chunck(a_stack->size);
	while (a_stack->size > 0)
	{
		cmd = decide_command(a_stack, num, chunk);
		while (a_stack->head->idx > num + chunk)
			rotate(a_stack, cmd);
		if (a_stack->head->idx <= num)
			push(a_stack, b_stack, PB);
		else
		{
			push(a_stack, b_stack, PB);
			rotate(b_stack, RB);
		}
		num++;
	}
}

static char	*decide_command(t_stack *stack, int num, int chunk)
{
	t_dll	*node;
	int		cnt;

	node = stack->head;
	cnt = 0;
	while (node->idx > num + chunk && node)
	{
		node = node->next;
		cnt++;
	}
	if (cnt <= stack->size / 2)
		return (RA);
	else
		return (RRA);
}

static int	init_chunck(int size)
{
	int	chunk;

	if (size < 10)
		chunk = 3;
	else if (size < 30)
		chunk = 5;
	else
		chunk = (int)(0.000000053 * size * size + 0.03 * size + 14.5);
	// ft_printf("[ chunk: %d ]\n", chunk);
	return (chunk);
}

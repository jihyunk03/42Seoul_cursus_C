/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 14:24:30 by jihykim2          #+#    #+#             */
/*   Updated: 2022/12/01 21:51:23 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_chr(int c, int *len)
{
	unsigned char	ch;

	ch = (unsigned char)c;
	*len += write(1, &ch, 1);
}

void	print_str(char *str, int *len)
{
	if (str == NULL)
	{
		*len += write(1, "(null)", 6);
		return ;
	}
	while (*str)
	{
		*len += write(1, str, 1);
		str++;
	}
}

void	print_nbr(unsigned int num, int *len)
{
	char	c;

	if (num >= 10)
	{
		print_nbr(num / 10, len);
		print_nbr(num % 10, len);
	}
	else
	{
		c = num % 10 + '0';
		*len += write(1, &c, 1);
	}
}

void	put_nbr(int num, int *len)
{
	unsigned int	un;

	un = (unsigned int)num;
	if (num < 0)
	{
		un *= -1;
		*len += write(1, "-", 1);
	}
	print_nbr(un, len);
}

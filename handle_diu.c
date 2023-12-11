/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_diu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhild <mhild@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 19:10:46 by mhild             #+#    #+#             */
/*   Updated: 2023/01/26 12:36:40 by mhild            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_dig(int num, int *count)
{	
	char	c;

	if (num == -2147483648)
	{
		write (1, "-2147483648", 11);
		*count = 11;
		return ;
	}
	if (num < 0)
	{
		write (1, "-", 1);
		num = -num;
		(*count)++;
	}
	if (num >= 10)
	{
		print_dig(num / 10, count);
		print_dig(num % 10, count);
	}
	if (num < 10)
	{
		c = num + '0';
		write (1, &c, 1);
		(*count)++;
	}
}

static void	print_unsigned(unsigned int num, int *count)
{	
	char	c;

	if (num >= 10)
	{
		print_dig(num / 10, count);
		print_dig(num % 10, count);
	}
	if (num < 10)
	{
		c = num + '0';
		write (1, &c, 1);
		(*count)++;
	}
}

int	handle_diu(va_list args, char c)
{
	int				j;
	unsigned int	u;
	int				count;

	count = 0;
	if (c == 'i' || c == 'd')
	{
		j = va_arg(args, int);
		print_dig(j, &count);
	}
	else if (c == 'u')
	{
		u = va_arg(args, unsigned int);
		print_unsigned(u, &count);
	}
	return (count - 2);
}

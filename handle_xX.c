/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_xX.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhild <mhild@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 17:09:30 by mhild             #+#    #+#             */
/*   Updated: 2023/01/26 12:01:09 by mhild            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_base(unsigned int temp, int toggle, int *count)
{
	char	c;

	if (temp >= 10 && toggle)
	{
		c = 'a' + (temp - 10);
		write (1, &c, 1);
		(*count)++;
	}
	else if (temp >= 10 && !toggle)
	{
		c = 'A' + (temp - 10);
		write (1, &c, 1);
		(*count)++;
	}
	else
	{
		c = '0' + temp;
		write (1, &c, 1);
		(*count)++;
	}
}

static int	hex_conversion(unsigned int num, int *count, int toggle)
{	
	if (num >= 16)
	{
		hex_conversion(num / 16, count, toggle);
		hex_conversion(num % 16, count, toggle);
	}
	if (num < 16)
		print_base(num, toggle, count);
	return (*count);
}

int	handle_xx(va_list args, const char c)
{
	int				count;
	unsigned int	num;

	count = 0;
	if (c == 'x')
	{
		num = va_arg(args, unsigned int);
		hex_conversion(num, &count, 1);
	}
	else if (c == 'X')
	{
		num = va_arg(args, unsigned int);
		hex_conversion(num, &count, 0);
	}
	return (count - 2);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhild <mhild@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 19:27:34 by mhild             #+#    #+#             */
/*   Updated: 2023/02/01 13:09:20 by mhild            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_base(unsigned long long int temp, int toggle, int *count)
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

static int	hex_conversion(unsigned long long int num, int *count, int toggle)
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

int	handle_p(va_list args)
{
	int						count;
	unsigned long long int	num_ptr;	

	count = 0;
	num_ptr = va_arg(args, unsigned long long);
	write (1, "0x", 2);
	count = hex_conversion(num_ptr, &count, 1);
	return (count);
}

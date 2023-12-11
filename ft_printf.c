/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhild <mhild@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 22:03:55 by mhild             #+#    #+#             */
/*   Updated: 2023/02/02 14:14:19 by mhild            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_printf(const char *string, ...)
{
	va_list	args;
	int		written;

	written = 0;
	if (string)
	{
		va_start (args, string);
		written = scan_str(args, string, written);
		va_end (args);		
	}
	return (written);
}

int	main(void)
{
	
	printf ("\001\002\007\v\010\f\r\n");
	return 0;
}
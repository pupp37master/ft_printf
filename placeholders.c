/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placeholders.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhild <mhild@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 10:38:05 by mhild             #+#    #+#             */
/*   Updated: 2023/01/25 11:13:32 by mhild            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	placeholders(va_list args, const char *s, int count)
{
	if (*s == 'c')
		count = count + handle_c(args);
	else if (*s == 's')
		count = count + handle_s(args);
	else if (*s == 'p')
		count = count + handle_p(args);
	else if (*s == 'd')
		count = count + handle_diu(args, 'd');
	else if (*s == 'i')
		count = count + handle_diu(args, 'i');
	else if (*s == 'u')
		count = count + handle_diu(args, 'u');
	else if (*s == 'x')
		count = count + handle_xx(args, 'x');
	else if (*s == 'X')
		count = count + handle_xx(args, 'X');
	else if (*s == '%')
		count = count + handle_percent((s));
	return (count);
}

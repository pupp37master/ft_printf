/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhild <mhild@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 16:26:30 by mhild             #+#    #+#             */
/*   Updated: 2023/01/26 12:01:36 by mhild            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	scan_str(va_list args, const char *s, unsigned int i)
{
	int	count;

	count = 0;
	while (*(s + i))
	{
		if (*(s + i) == '%')
		{
			i++;
			count = placeholders(args, (s + i), count);
			i++;
		}
		else
		{
			write (1, (s + i), 1);
			i++;
		}
	}
	return (count + i);
}

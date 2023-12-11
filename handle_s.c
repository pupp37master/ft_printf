/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhild <mhild@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 17:15:25 by mhild             #+#    #+#             */
/*   Updated: 2023/02/01 16:22:05 by mhild            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_s(va_list args)
{
	char	*str;
	int		j;

	str = va_arg(args, char *);
	if (!str)
	{
		write (1, "(null)", 6);
		return (4);
	}
	j = 0;
	while (*(str + j))
	{
		write (1, (str + j), 1);
		j++;
	}
	return (j - 2);
}

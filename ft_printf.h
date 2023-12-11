/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhild <mhild@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 12:53:39 by mhild             #+#    #+#             */
/*   Updated: 2023/01/26 12:37:34 by mhild            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *string, ...);
int		handle_diu(va_list args, char c);
int		handle_c(va_list args);
int		handle_s(va_list args);
int		handle_p(va_list args);
int		handle_percent(const char *s);
int		handle_xx(va_list args, const char c);
int		scan_str(va_list args, const char *s, unsigned int i);
int		placeholders(va_list args, const char *s, int count);

#endif
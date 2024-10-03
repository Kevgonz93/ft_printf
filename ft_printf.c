/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kegonzal <kegonzal@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 14:10:39 by kegonzal          #+#    #+#             */
/*   Updated: 2024/10/03 14:10:44 by kegonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdio.h>
#include <stdarg.h>

int	ft_select(char c, va_list args)
{
	if (c == 'c')
		return (ft_printer_char(args));
	else if (c == 's')
		return (ft_printer_str(args));
	else if (c == 'p')
		return (ft_printer_pointer(args));
	else if (c == 'd')
		return (ft_printer_int(args));
	// else if (c == 'i')
	// 	return (ft_printer_float(args));
	// else if (c == 'u')
	// 	return (ft_printer_unsig(args));
	// else if (c == 'x')
	// 	return (ft_printer_hexa_low(args));
	// else if (c == 'X')
	// 	return (ft_printer_hexa_up(args));
	else if (c == '%')
		return (ft_iputchar_fd('%', 1));
	return (0);
}

int	ft_printf(char const *text, ...)
{
	int		printed;
	int		i;
	va_list	args;

	printed = 0;
	i = 0;
	va_start(args, text);
	while (text[i] != '\0')
	{
		if (text[i] == '%' && text[i + 1] != '\0')
		{
			i++;
			printed += ft_select(text[i], args);
		}
		else if (text[i] == '\\')
			printed += ft_iputchar_fd(text[i], 1);
		else
			printed += ft_iputchar_fd(text[i], 1);
		i++;
	}
	va_end(args);
	return (printed);
}

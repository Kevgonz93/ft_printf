/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kegonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 20:36:28 by kegonzal          #+#    #+#             */
/*   Updated: 2024/10/21 20:36:30 by kegonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_selector(char format, va_list *args)
{
	if (format == 'c')
		return (ft_printer_char(args));
	else if (format == 's')
		return (ft_printer_str(args));
	else if (format == 'p')
		return (ft_printer_pointer(args, "0123456789abcdef"));
	else if (format == 'd' || format == 'i')
		return (ft_printer_int(args, 0));
	else if (format == 'u')
		return (ft_printer_int(args, 1));
	else if (format == 'f')
		return (ft_printer_float(args));
	else if (format == 'x')
		return (ft_printer_hexa(args, "0123456789abcdef"));
	else if (format == 'X')
		return (ft_printer_hexa(args, "0123456789ABCDEF"));
	else if (format == '%')
		return (ft_iputchar_fd('%', 1));
	return (0);
}

int	ft_printf(char const *format, ...)
{
	int		printed;
	int		i;
	va_list	args;

	printed = 0;
	i = 0;
	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%' && format[i + 1] != '\0')
		{
			i++;
			printed += ft_selector(format[i], &args);
		}
		else
			printed += ft_iputchar_fd(format[i], 1);
		i++;
	}
	va_end(args);
	return (printed);
}

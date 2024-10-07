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

#include "ft_printf.h"

int	ft_error(char *format)
{
	char	error[100];
	int		count;
	size_t	len;
	char	*ptr;

	ptr = error;
	len = ft_strlen("Error: Invalid argument for '");
	ft_memcpy(ptr, "Error: Invalid argument for '", len);
	ptr += len;
	len = ft_strlen(format);
	ft_memcpy(ptr, format, len);
	ptr += len;
	len = ft_strlen("'\n");
	ft_memcpy(ptr, "'\n", len);
	ptr += len;
	*ptr = '\0';
	count = ft_iputstr_fd(error, 1);
	return (count);
}

int	ft_selector(char format, va_list args)
{
	if (format == 'c')
		return (ft_printer_char(format, args));
	else if (format == 's')
		return (ft_printer_str(format, args));
	else if (format == 'p')
		return (ft_printer_pointer(args));
	else if (format == 'd')
		return (ft_printer_int(format, args));
	else if (format == 'i')
		return (ft_printer_int(format, args));
	else if (format == 'u')
		return (ft_printer_int(format, args));
	else if (format == 'x')
		return (ft_printer_hexa(args, 'l'));
	else if (format == 'X')
		return (ft_printer_hexa(args, 'u'));
	else if (format == '%')
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
			printed += ft_selector(text[i], args);
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

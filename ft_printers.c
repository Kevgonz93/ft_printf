/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kegonzal <kegonzal@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 17:33:20 by kegonzal          #+#    #+#             */
/*   Updated: 2024/10/03 17:33:21 by kegonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printer_char(char format, va_list args)
{
	char	cha;

	cha = (char)va_arg(args, int);
	if (cha == NULL)
		ft_error(format, args);
	return (ft_iputchar_fd(cha, 1));
}

int	ft_printer_int(char format, va_list args)
{
	int	in;

	in = (int)va_arg(args, int);
	if (in == NULL)
		ft_error(format, args);
	return (ft_iputnbr_fd(in, 1));
}

int	ft_printer_str(char format, va_list args)
{
	char	*str;

	str = (char *)va_arg(args, char *);
	if (str == NULL)
		ft_error(format, args);
	return (ft_iputstr_fd(str, 1));
}

int	ft_printer_pointer(char format, va_list args)
{
	char		*ptr;
	int			count;
	void		*fake;

	fake = va_arg(args, void *);
	ptr = ft_ptr_to_hexa(fake);
	if (fake == NULL)
	{
		write(1, "0x0", 3);
		return (0);
	}
	count = ft_iputstr_fd(ptr, 1);
	free(ptr);
	return (count);
}

int	ft_printer_hexa(char format, va_list args, char c)
{
	char	*ptr;
	int		fake;
	int		count;

	fake = va_arg(args, int);
	ptr = ft_int_to_hexa(fake, c);
	if (ptr == NULL)
		return (-1);
	count = ft_iputstr_fd(ptr, 1);
	free(ptr);
	return (count);
}

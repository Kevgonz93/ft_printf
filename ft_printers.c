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

int	ft_printer_char(char format, va_list *args)
{
	char	cha;
	(void)format;

	cha = (char)va_arg(*args, int);
	return (ft_iputchar_fd(cha, 1));
}

int	ft_printer_str(char format, va_list *args)
{
	char	*str;
	(void)format;

	str = (char *)va_arg(*args, char *);
	if (str == NULL)
		return (ft_iputstr_fd("(null)", 1));
	return (ft_iputstr_fd(str, 1));
}

int	ft_printer_int(char format, va_list *args)
{
	unsigned int	in;
	(void)format;

	in = (unsigned int)va_arg(*args, int);
	return (ft_iputnbr_fd(in, 0, 1));
}

int ft_printer_uns(char format, va_list *args)
{
    (void)format;
    unsigned int	n;

	n = va_arg(*args, unsigned int);
	return ft_iputnbr_fd(n, 1, 1);
}

int	ft_printer_pointer(va_list *args, const char *hexa)
{
	char		*ptr;
	int			count;
	void		*fake;

	fake = va_arg(*args, void *);
	if (fake == NULL)
		return (ft_iputstr_fd("0x0", 1));
	ptr = ft_ptr_to_hexa((uintptr_t)fake, hexa);
	if (ptr == NULL)
		return (-1);
	count = ft_iputstr_fd(ptr, 1);
	free(ptr);
	return (count);
}

int	ft_printer_hexa(va_list *args, char *hexa)
{
	char			*result;
	unsigned int	fake;
	int				count;

	fake = va_arg(*args, unsigned int);
	result = ft_int_to_hexa(fake, hexa);
	if (result == NULL)
		return (-1);
	count = ft_iputstr_fd(result, 1);
	free(result);
	return (count);
}

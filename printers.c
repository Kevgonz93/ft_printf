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

#include "printf.h"
#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdint.h>
#include <stdlib.h>

int	ft_printer_char(va_list args)
{
	char	cha;

	cha = (char)va_arg(args, int);
	return (ft_iputchar_fd(cha, 1));
}

int	ft_printer_int(va_list args)
{
	int	in;

	in = (int)va_arg(args, int);
	return (ft_iputnbr_fd(in, 1));
}

int	ft_printer_str(va_list args)
{
	char	*str;

	str = (char *)va_arg(args, char *);
	return (ft_iputstr_fd(str, 1));
}

int	ft_printer_pointer(va_list args)
{
	char		*ptr;
	int			count;
	void		*fake;

	fake = va_arg(args, void *);
	ptr = ft_tohexa(fake);
	if (ptr == NULL)
		return (-1);
	count = ft_iputstr_fd(ptr, 1);
	free(ptr);
	return (count);
}

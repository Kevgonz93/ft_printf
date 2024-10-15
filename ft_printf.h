/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kegonzal <kegonzal@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 14:10:27 by kegonzal          #+#    #+#             */
/*   Updated: 2024/10/03 14:10:31 by kegonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdint.h>

int		ft_printf(char const *text, ...);
int		ft_selector(char c, va_list *args);
int		ft_error(char *format);

//	printers

int		ft_printer_char(char format, va_list *args);
int		ft_printer_str(char format, va_list *args);
int		ft_printer_int(char format, va_list *args);
int     ft_printer_uns(char format, va_list *args);
int		ft_printer_pointer(va_list *args, const char *hexa);
int		ft_printer_hexa(va_list *args, char *hexa);

//	utils

int		ft_iputchar_fd(char c, int fd);
int		ft_iputstr_fd(char *s, int fd);
int		ft_iputnbr_fd(unsigned int n, int is_unsigned, int fd);
char	*ft_ptr_to_hexa(uintptr_t ptr, const char *hexa);
char	*ft_int_to_hexa(unsigned int n, char *hexa);

#endif

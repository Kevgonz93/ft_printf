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


#ifndef PRINTF_H
# define PRINTF_H

#include <stdarg.h>

int			ft_printf(char const *text, ...);

//	printers

int			ft_printer_char(va_list args);
int			ft_printer_str(va_list args);
int			ft_printer_int(va_list args);
int			ft_printer_pointer(va_list args, char c);
int			ft_printer_hexa(va_list args, char c);

//	utils

int			ft_iputchar_fd(char c, int fd);
int			ft_iputstr_fd(char *s, int fd);
int			ft_iputnbr_fd(int n, int fd);
char		*ft_tohexa(void *ptr, char c);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kegonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 15:30:42 by kegonzal          #+#    #+#             */
/*   Updated: 2024/10/07 15:30:43 by kegonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	ft_printf("with c \t\t\t: \t%c\n", 'h');
	printf("should be\t\t: \t%c\n", 'h');
	ft_printf("with more of one c \t: \t%c %c %c %c %c\n", 'h','e','l','l','o');
	printf("should be:\t\t: \t%c %c %c %c %c\n", 'h','e','l','l','o');
	ft_printf("with d \t\t\t: \t%d\n", 42);
	printf("should be\t\t: \t%d\n", 42);
	ft_printf("with s\t\t\t: \t%s\n", "Hola mundo");
	printf("should be\t\t: \t%s\n", "Hola mundo");
	ft_printf("with i\t\t\t: \t%i\n", 42);
	printf("should be\t\t: \t%i\n", 42);

	int num = 42;
    int *ptr = &num;

	ft_printf("with p\t\t\t: \t%p\n", (void *)ptr);
	printf("should be\t\t: \t%p\n", (void *)ptr);
	ft_printf("with x\t\t\t: \t%x\n", 255);
	printf("should be \t\t: \t%x\n", 255);
	ft_printf("with X\t\t\t: \t%X\n", 255);
	printf("should be \t\t: \t%X\n", 255);
	ft_printf("with '%%' \t\t: \t%%\n");
	printf("should be \t\t: \t%%\n");
	return (0);
}

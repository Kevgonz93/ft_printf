/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kegonzal <kegonzal@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 16:49:44 by kegonzal          #+#    #+#             */
/*   Updated: 2024/10/03 16:49:45 by kegonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdint.h>

int	ft_iputchar_fd(char c, int fd)
{
	write(fd, &c, 1);
	return (1);
}

int	ft_iputstr_fd(char *s, int fd)
{
	int	count;

	count = 0;
	while (s[count] != 0)
	{
		count += ft_iputchar_fd(s[count], fd);
	}
	return (count);
}

int	ft_iputnbr_fd(int n, int fd)
{
	int	count;

	count = 0;
	if (n == -2147483648)
	{
		count += ft_iputstr_fd("-2147483648", fd);
		return (count);
	}
	if (n < 0)
	{
		count += ft_iputchar_fd('-', fd);
		n *= -1;
	}
	if (n >= 10)
		count += ft_iputnbr_fd(n / 10, fd);
	count += ft_iputchar_fd((n % 10 + '0'), fd);
	return (count);
}

char	*ft_tohexa(void *ptr)
{
	char		*temp;
	char		*hexa;
	uintptr_t	fake;
	int			i;

	temp = malloc(19 * sizeof(char));
	if (temp == NULL)
		return (NULL);
	temp[0] = '0';
	temp[1] = 'x';
	hexa = "0123456789Abcdef";
	fake = (uintptr_t)ptr;
	i = 0;
	while (i < 16)
	{
		temp[17 - i] = hexa[fake % 16];
		fake /= 16;
		i++;
	}
	temp[18] = 0;
	return (temp);
}

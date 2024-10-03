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
		count += ft_iputchar_fd(s[count], fd);
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

char	*ft_tohexa(void *ptr, char c)
{
	char		*temp;
	char		*hexa;
	uintptr_t	fake;

	if (c == 'u')
		hexa = "0123456789abcdef";
	else if (c == 't')
		hexa = "0123456789ABCDEF";
	fake = (uintptr_t)ptr;
	temp = malloc(19 * sizeof(char));
	temp = ft_fill_hexa(temp, fake, c);
	return (temp);
}

char *ft_fill_hexa(char *temp, uintptr_t fake, char c)
{
	int			i;
	int			start;

	temp[0] = '0';
	temp[1] = 'x';
	i = 0;
	while (i++ < 16)
	{
		temp[17 - i] = hexa[fake % 16];
		fake /= 16;
	}
	start = 2;
	while (temp[start] == '0' && start < 17)
		start++;
	i = 0;
	while (start <= 17)
		temp[i++ + 2] = temp[start++];
	temp[i + 2] = '\0';
}

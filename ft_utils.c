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

#include "ft_printf.h"

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

char	*ft_ptr_to_hexa(void *ptr)
{
	char		*temp;
	char		*hexa;
	uintptr_t	fake;
	int			i;
	int			start;

	hexa = "0123456789abcdef";
	fake = (uintptr_t)ptr;
	temp = malloc(19 * sizeof(char));
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
	temp[0] = '0';
	temp[1] = 'x';
	temp[i + 2] = '\0';
	return (temp);
}

char	*ft_int_to_hexa(int n, char c)
{
	char	temp[11];
	char	*hexa;
	int		i;

	i = 0;
	if (c == 'l')
		hexa = "0123456789abcdef";
	else
		hexa = "0123456789ABCDEF";
	temp[10] = '\0';
	while (n != 0 && i < 10)
	{
		temp[9 - i] = hexa[n % 16];
		i++;
		n /= 16;
	}
	return (ft_strtrim(&temp[10 - i], "0"));
}

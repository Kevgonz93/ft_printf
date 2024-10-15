
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

int	ft_iputnbr_fd(unsigned int n, int is_unsigned, int fd)
{
	int	count;
	int	un;

	count = 0;
	un = 0;
	if (!is_unsigned)
	{
		un = (int)n;
		if (un == -2147483648)
			return (count += ft_iputstr_fd("-2147483648", fd));
		if (un < 0)
		{
			count += ft_iputchar_fd('-', fd);
			un = -un;
		}
		if (un >= 10)
			count += ft_iputnbr_fd((un / 10), 0, fd);
		count += ft_iputchar_fd((un % 10) + '0', fd);
	}
	else
	{
		if (n >= 10)
			count += ft_iputnbr_fd((n / 10), 1, fd);
		count += ft_iputchar_fd((n % 10) + '0', fd);
	}
	return (count);
}

char	*ft_ptr_to_hexa(uintptr_t ptr, const char *hexa)
{
	char	*temp;
	int		i;

	temp = malloc(15 * sizeof(char));
	if (temp == NULL)
		return (NULL);
	temp[14] = '\0';
	i = 13;
	while (ptr != 0)
	{
		temp[i--] = hexa[ptr % 16];
		ptr /= 16;
	}
	while (i >= 2)
		temp[i--] = '0';
	temp[0] = '0';
	temp[1] = 'x';
	return (temp);
}

char	*ft_int_to_hexa(unsigned int n, char *hexa)
{
	char	temp[11];
	int		i;

	if (n == 0)
		return (ft_strdup("0"));
	i = 0;
	temp[10] = '\0';
	while (n != 0 && i < 10)
	{
		temp[9 - i] = hexa[n % 16];
		i++;
		n /= 16;
	}
	return (ft_strdup(&temp[10 - i]));
}

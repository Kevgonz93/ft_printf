
#include "ft_printf.h"

int	ft_selector(char format, va_list *args)
{
	if (format == 'c')
		return (ft_printer_char(args));
	else if (format == 's')
		return (ft_printer_str(args));
	else if (format == 'p')
		return (ft_printer_pointer(args, "0123456789abcdef"));
	else if (format == 'd' || format == 'i')
		return (ft_printer_int(args, 0));
	else if (format == 'u')
		return (ft_printer_int(args, 1));
	else if (format == 'x')
		return (ft_printer_hexa(args, "0123456789abcdef"));
	else if (format == 'X')
		return (ft_printer_hexa(args, "0123456789ABCDEF"));
	else if (format == '%')
		return (ft_iputchar_fd('%', 1));
	return (0);
}

int	ft_printf(char const *format, ...)
{
	int		printed;
	int		i;
	int		res;
	va_list	args;

	printed = 0;
	i = 0;
	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%' && format[i + 1] != '\0')
		{
			i++;
			res = ft_selector(format[i], &args);
			if (res == -1)
				return (-1);
			printed += res;
		}
		else if (format[i] == '\\')
			printed += ft_iputchar_fd(format[i], 1);
		else
			printed += ft_iputchar_fd(format[i], 1);
		i++;
	}
	va_end(args);
	return (printed);
}

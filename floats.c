#include "ft_printf.h"

static int	print_decimals(double flo)
{
	int	n;
	int	count;

	count = 0;
	n = flo * 10;
	while (n % 10 != 0)
		n *= 10;
	count = ft_iputnbr_fd(n, 0, 1);
	return (count);
}

int	ft_printer_float(va_list *args)
{
	double		flo;
	int			count;

	count = 0;
	flo = va_arg(*args, double);
	if (flo < 0)
	{
		count += ft_iputchar_fd('-', 1);
		flo = -flo;
	}
	count += ft_iputnbr_fd((int)flo, 0, 1);
	count += ft_iputchar_fd('.', 1);
	count += print_decimals(flo - (int)flo);
	return (count);
}

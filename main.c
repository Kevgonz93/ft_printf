#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	// DIFERENTES DATOS

	ft_printf("%d \n", -2147483648);
	printf("%ld \n", -2147483648);
	ft_printf("%u \n", 4294967295); // unsigned
	printf("%lu \n", 4294967295); // unsigned
	ft_printf("%p \n", (void *)0xDEADBEEF); // pointers
	printf("%p \n", (void *)0xDEADBEEF); // pointers

	ft_printf("%s \n", ""); // empty str
	printf("%s \n", ""); // empty str
	ft_printf("%p \n", NULL); // NULL
	printf("%p \n", NULL); // NULL

	printf("ft_printf: %d\n", ft_printf("%d", 42));
	printf("printf: %d\n", printf("%d", 42));
}

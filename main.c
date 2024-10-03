#include "printf.h"
#include <stdio.h>

int	main(void)
{
	ft_printf("the char\t: \t%c\n", 'h');
	ft_printf("the int\t\t: \t%d\n", 42);
	ft_printf("the str\t\t: \t%s\n", "Hola mundo");

	int num = 42;
    int *ptr = &num;

	ft_printf("the ptr\t\t: \t%p\n", (void *)ptr);
	printf("should be: %p\n", (void *)ptr);
	return (0);
}

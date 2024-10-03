#include "printf.h"
#include <stdio.h>

int	main(void)
{
	ft_printf("with c \t\t: \t%c\n", 'h');
	printf("should be\t: \t%c\n", 'h');
	ft_printf("with d \t\t: \t%d\n", 42);
	printf("should be\t: \t%d\n", 42);
	ft_printf("with s\t\t: \t%s\n", "Hola mundo");
	printf("should be\t: \t%s\n", "Hola mundo");
	ft_printf("with i\t\t: \t%i\n", 42);
	printf("should be\t: \t%i\n", 42);

	int num = 42;
    int *ptr = &num;

	ft_printf("with p\t\t: \t%p\n", (void *)ptr);
	printf("should be\t: \t%p\n", (void *)ptr);
	ft_printf("with x\t\t: \t%x\n", 255);
	printf("should be \t: \t%x\n", 255);
	ft_printf("with X\t\t: \t%X\n", 255);
	printf("should be \t: \t%X\n", 255);

	return (0);
}

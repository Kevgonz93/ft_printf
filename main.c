#include "ft_printf.h"

int main(void)
{
    int a = 42;
    int *ptr_a = &a;
    char *null_ptr = NULL;
    int *negative_ptr = (int *)(-14523);

    printf("original: %p\n", (void *)ptr_a);
    ft_printf("fake: %p\n", (void *)ptr_a);

    printf("original: %p\n", (void *)null_ptr);
    ft_printf("fake: %p\n", (void *)null_ptr);


    printf("original: %p\n", (void *)negative_ptr);
    ft_printf("fake: %p\n", (void *)negative_ptr);
    return 0;
}

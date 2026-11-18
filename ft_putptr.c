#include "ft_printf.h"

static int ft_puthex_ptr(unsigned long n, char *base)
{
    char c;

    if (n >= 16)
        ft_puthex_ptr(n / 16, base);
    c = base[n % 16];
    write (1, &c, 1);
    return (n);
}

int	ft_putptr(void *ptr)
{
    char c;

    if (ptr ==  NULL)
    {
        write (1, "(nil)", 5);
        return (5);
    }
    else
    {
        write (1, "0x", 2);
        c = ft_puthex_ptr((unsigned long)ptr, "0123456789abcdef");
    }
    return (2 + c);
}


int main(void)
{
    int x;

    ft_putptr(&x);
    write (1, "\n", 1);
    return (0);
}
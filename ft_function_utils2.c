#include "ft_printf.h"

int	ft_puthex(unsigned int n, char *base)
{
    char c;

    if (n >= 16)
        ft_puthex(n / 16, base);
    c = base[n % 16];
    write (1, &c, 1);
    return (1);
}

static int ft_puthex_ptr(unsigned long n, char *base)
{
    char c;

    if (n >= 16)
        ft_puthex_ptr(n / 16, base);
    c = base[n % 16];
    write (1, &c, 1);
    return (n);
}

int	ft_putptr(char format, void *ptr)
{
    char c;

    if (ptr ==  NULL)
    {
        write (1, "(nil)", 5);
        return (5);
    }
    else if (format == 'x')
    {
        write (1, "0x", 2);
        c = ft_puthex_ptr((unsigned long)ptr, "0123456789abcdef");
    }
    else if (format == 'X')
    {
        write (1, "0X", 2);
        c = ft_puthex_ptr((unsigned long)ptr, "0123456789ABCDEF");
    }
    return (2 + c);
}


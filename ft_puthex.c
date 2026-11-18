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

int main(void)
{
    ft_puthex(123, "0123456789ABCDEF");
    return (0);
}
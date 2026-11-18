#include "ft_printf.h"

int	ft_puthex(unsigned int n, char *base)
{
    long nb;
    char c;

    nb = n;
    if (nb < 0)
        nb = -nb;
    if (nb > 16)
        ft_puthex(n, &base[n / 16]);
    c = '0' + (&base[n % 16]);
    write (1, &base, 1);
}

int main(void)
{
    ft_puthex(123, "0123456789ABCDE");
    return (0);
}
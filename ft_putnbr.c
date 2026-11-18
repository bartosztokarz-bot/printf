#include "ft_printf.h"

int	count_len(long nb)
{
    int compteur;

    compteur = 0;
    if (nb < 0)
    {
        compteur++;
        nb = -nb;
    }
    while (nb > 9)
    {
        compteur++;
        nb = nb / 10;
    }
    compteur++;
    return (compteur);
}

int	ft_putnbr(int n)
{
    long nb;
    long len;
    char c;

    nb = n;
    len = n;
    if (nb < 0)
    {
        write (1, "-", 1);
        nb = -nb;
    }
    if (nb > 9)
        ft_putnbr(nb / 10);
    c = '0' + (nb % 10);
    write (1, &c, 1);
    return (count_len(len));
}

int main(void)
{
    int i;
    int c = 1111111;

    i = ft_putnbr(c);
    printf("%d\n", i);
    return (0);
}
#include "ft_printf.h"

int count_len(long nb)
{
    int compteur;

    compteur = 0;
    while (nb > 9)
    {
        compteur++;
        nb = nb / 10;
    }
    compteur++;
    return (compteur);
}

int	ft_putunbr(unsigned int n)
{
    long nb;
    char c;

    nb = n;
    if (nb > 9)
        ft_putunbr(nb / 10);
    c = '0' + (nb % 10);
    write (1, &c, 1);
    return (count_len(nb));
}

int main(void)
{
//    int i = 2345678;
    int c = -123;

    ft_putunbr(c);
    write (1, "\n", 1);
    return (0);
}
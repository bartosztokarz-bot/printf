#include "ft_printf.h"

size_t	ft_strlen(const char *s)
{
    size_t i;

    i = 0;
    while (s[i])
        i++;
    return (i);
}

int	ft_putchar(char c)
{
    write (1, &c, 1);
    return (1);
}

int	ft_putstr(char *s)
{
    int i;

    if (!s)
    {
        write(1, "(null)", 6);
        return (6);
    }
    i = 0;
    while (s[i])
    {
        write (1, &s[i], 1);
        i++;
    }
    return (i);
}
int	ft_putnbr(int n)
{
	long	nb;
	int		compteur;
    long    ar;
	char	c;

	nb = n;
	compteur = 0;
	if (nb < 0)
	{
		compteur++;
		write(1, "-", 1);
		nb = -nb;
	}
    if (nb > 9)
        ft_putnbr(nb / 10);
    ar = nb;
    while (ar > 0)
    {
        ar = ar / 10;
        compteur++;
    }
	c = '0' + (nb % 10);
	write(1, &c, 1);
	return (compteur);
}

int	ft_putunbr(unsigned int n)
{
    long nb;
    long ar;
    int compteur;
    char c;

    nb = n;
    ar = nb;
    if (nb > 9)
        ft_putunbr(nb / 10);
    while (ar > 0)
    {
        ar = ar / 10;
        compteur++;
    }
    c = '0' + (nb % 10);
    write (1, &c, 1);
    return (compteur);
}

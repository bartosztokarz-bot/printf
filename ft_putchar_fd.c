#include "ft_printf.h"

int	ft_putchar(char c, int fd)
{
    int compteur;

    compteur = 0;
    write (fd, &c, 1);
    compteur++;
}

/*int main(void)
{
    ft_putchar('c', 1);
    return (0);
}*/
#include <stdio.h>
#include <unistd.h>

int	ft_puthex(unsigned int n, char *base)
{
    char c;
    long nb;

    c = nb / base;
    write (1, &c, 1);
    c = nb % base;
    write (1, &c, 1);
    return (1);
}

int main(void)
{
    unsigned int i;

    i = 12345;
    ft_puthex(i, "0123456789ABCDE");
    return (0);
}
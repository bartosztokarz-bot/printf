#include "ft_printf.h"

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

int main(void)
{
    char str[] = "";
    int d;

    d = ft_putstr(str);
    write (1, "\n", 1);
    printf("%d\n", d);
    return (0);
}

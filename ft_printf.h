#ifndef PRINTF_H
# define PRINTF_H

# include <unistd.h>
# include <stdarg.h>

size_t	ft_strlen(const char *s);
int	ft_putchar(char c);
int	ft_putstr(char *s);
int	ft_putnbr(int n);
int	ft_putunbr(unsigned int n);
int ft_puthex_ptr(unsigned long n, char *base);
static int ft_puthex_ptr(unsigned long n, char *base);
int	ft_putptr(void *ptr);

#endif
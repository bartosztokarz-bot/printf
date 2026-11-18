#ifndef PRINTF_H
# define PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>

size_t	ft_strlen(const char *s);
int	ft_putstr(char *s);
int	ft_putchar(char c, int fd);

#endif
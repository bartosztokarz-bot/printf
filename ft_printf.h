/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: batokarz <batokarz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 11:12:39 by batokarz          #+#    #+#             */
/*   Updated: 2026/11/23 11:17:46 by batokarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

size_t	ft_strlen(const char *s);
int		ft_putstr(char *s);
int		ft_putchar(char c);
int		ft_putnbr(int n);
int		ft_putunbr(unsigned int n);
int		ft_puthex(unsigned int n, char *base);
int		ft_putptr(void *ptr);
int		ft_convert(char format, va_list *args);
int		ft_printf(const char *format, ...);

#endif
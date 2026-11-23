/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base_printf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: batokarz <batokarz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 11:13:31 by batokarz          #+#    #+#             */
/*   Updated: 2026/11/23 11:14:50 by batokarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_convert(char format, va_list *args)
{
	if (format == 'd')
		return (ft_putnbr(va_arg(*args, int)));
	if (format == 'c')
		return (ft_putchar(va_arg(*args, int)));
	if (format == 's')
		return (ft_putstr(va_arg(*args, char *)));
	if (format == 'p')
		return (ft_putptr(va_arg(*args, void *)));
	if (format == 'i')
		return (ft_putnbr(va_arg(*args, int)));
	if (format == 'u')
		return (ft_putunbr(va_arg(*args, unsigned int)));
	if (format == 'x')
		return (ft_puthex(va_arg(*args, unsigned int), "0123456789abcdef"));
	if (format == 'X')
		return (ft_puthex(va_arg(*args, unsigned int), "0123456789ABCDEF"));
	if (format == '%')
		return (ft_putchar('%'));
	return (1);
}

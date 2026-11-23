/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_function_utils2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: batokarz <batokarz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 11:12:20 by batokarz          #+#    #+#             */
/*   Updated: 2026/11/23 11:12:21 by batokarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned int n, char *base)
{
	char	c;
	int		count;

	count = 0;
	if (n >= 16)
		count += ft_puthex(n / 16, base);
	c = base[n % 16];
	write(1, &c, 1);
	count++;
	return (count);
}

static int	ft_puthex_ptr(unsigned long n, char *base)
{
	char	c;
	int		count;

	count = 0;
	if (n >= 16)
		count += ft_puthex_ptr(n / 16, base);
	c = base[n % 16];
	write(1, &c, 1);
	count++;
	return (count);
}

int	ft_putptr(void *ptr)
{
	char	c;

	if (ptr == NULL)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	else
	{
		write(1, "0x", 2);
		c = ft_puthex_ptr((unsigned long)ptr, "0123456789abcdef");
	}
	return (2 + c);
}

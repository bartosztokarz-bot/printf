/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_function_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: batokarz <batokarz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 11:12:17 by batokarz          #+#    #+#             */
/*   Updated: 2026/11/24 10:55:15 by batokarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	i;

	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

int	ft_putnbr(int n)
{
	long	nb;
	int		compteur;
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
		compteur += ft_putnbr(nb / 10);
	c = '0' + (nb % 10);
	write(1, &c, 1);
	compteur++;
	return (compteur);
}

int	ft_putunbr(unsigned int n)
{
	long	nb;
	char	c;
	int		compteur;

	nb = n;
	compteur = 0;
	if (nb > 9)
		compteur += ft_putunbr(nb / 10);
	c = '0' + (nb % 10);
	write(1, &c, 1);
	compteur++;
	return (compteur);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevy <ldevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 21:38:44 by ldevy             #+#    #+#             */
/*   Updated: 2021/12/20 21:39:11 by ldevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

void	ft_putnbr(int nb, int *res)
{
	char		c;
	long		nbr;

	nbr = nb;
	if (nbr < 0)
	{
		write(1, "-", 1);
		*res += 1;
		nbr = -nbr;
	}
	if (nbr > 9)
	{
		ft_putnbr(nbr / 10, res);
		nbr %= 10;
	}
	c = nbr % 10 + 48;
	*res += 1;
	write(1, &c, 1);
}

void	ft_putnbr_u(int nb, int *res)
{
	char			c;
	unsigned int	nbr;

	nbr = nb;
	if (nbr > 9)
	{
		ft_putnbr(nbr / 10, res);
		nbr %= 10;
	}
	c = nbr % 10 + 48;
	*res += 1;
	write(1, &c, 1);
}

void	ft_putstr(char *s, int *res)
{
	size_t	i;

	if (!s)
	{
		write(1, "(null)", 6);
		*res = 6;
		return ;
	}
	i = 0;
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
		*res += 1;
	}
}

void	to_hex(unsigned long nb, int up, int p, int *res)
{
	char		*lexicon;
	char		c;

	lexicon = "0123456789abcdef";
	if (!p && *res == 0)
		nb = (unsigned int) nb;
	if (p && *res == 0)
	{
		write(1, "0x", 2);
		*res += 2;
		p = 0;
	}
	if (nb > 15)
	{
		to_hex(nb / 16, up, p, res);
		nb %= 16;
	}
	c = lexicon[nb];
	if (up && c >= 'a' && c <= 'z')
		c -= 32;
	*res += 1;
	write(1, &c, 1);
}

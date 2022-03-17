/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevy <ldevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 16:55:59 by ldevy             #+#    #+#             */
/*   Updated: 2021/12/13 16:44:47 by ldevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	len_nb(int nb)
{
	int		size;
	long	n;

	n = nb;
	if (n < 0)
		n = -n;
	size = 0;
	while (n >= 10)
	{
		n /= 10;
		size++;
	}
	return (size + 1);
}

static	char	*ft_strrev(char *s)
{
	size_t	n;
	size_t	i;
	size_t	j;
	char	temp;

	i = 0;
	j = ft_strlen(s) - 1;
	n = ft_strlen(s);
	while (i < (n / 2))
	{
		temp = s[i];
		s[i] = s[j];
		s[j] = temp;
		i++;
		j--;
	}
	return (s);
}

static	char	*ft_helper(int signe, long ln, char *nb)
{
	int		i;

	i = 0;
	if (ln == 0)
	{
		nb[0] = '0';
		nb[1] = '\0';
		return (nb);
	}
	while (ln > 0)
	{
		nb[i] = (ln % 10) + 48;
		ln /= 10;
		i++;
	}
	if (signe)
		nb[i] = '-';
	nb[i + signe] = '\0';
	return (ft_strrev(nb));
}

char	*ft_itoa(int n)
{
	long	ln;
	int		signe;
	char	*nb;

	ln = n;
	signe = 0;
	if (ln < 0)
	{
		signe = 1;
		ln = -ln;
	}
	nb = malloc((len_nb(ln) + signe + 1) * sizeof(*nb));
	if (!nb)
		return (NULL);
	return (ft_helper(signe, ln, nb));
}

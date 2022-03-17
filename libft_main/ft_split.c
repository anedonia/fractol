/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevy <ldevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 13:17:48 by ldevy             #+#    #+#             */
/*   Updated: 2021/12/13 20:58:53 by ldevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_issep(char origine, char c)
{
	if (origine == c)
		return (1);
	return (0);
}

static	int	nb_word(char const *s, char c, long unsigned int *index)
{
	size_t	nb;
	size_t	i;

	nb = 0;
	i = 0;
	while (s[i])
	{
		if (!ft_issep(s[i], c))
		{
			nb++;
			while (!ft_issep(s[i], c) && s[i])
				i++;
		}
		if (s[i])
			i++;
	}
	*index = 0;
	return (nb);
}

static	void	del_time(char **tab, size_t word)
{
	long	index;

	index = word;
	while (index > 0)
	{
		free(tab[index]);
		index--;
	}
	free(tab);
}

static	int	make_word(char const *s, char **tab, size_t *index, size_t length)
{
	size_t	i;

	tab[*index] = malloc((length + 1) * sizeof(**tab));
	if (!tab[*index])
	{
		del_time(tab, *index);
		return (0);
	}
	i = 0;
	while (i < length)
	{
		tab[*index][i] = s[i];
		i++;
	}
	tab[*index][i] = '\0';
	*index += 1;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	size_t	i;
	size_t	j;
	size_t	word;

	if (!s)
		return (NULL);
	tab = malloc((nb_word(s, c, &word) + 1) * sizeof(*tab));
	i = 0;
	while (s[i])
	{
		j = 0;
		if (!ft_issep(s[i], c))
		{
			while (!ft_issep(s[i + j], c) && s[i + j])
				j++;
			if (!tab || !make_word(&s[i], tab, &word, j))
				return (NULL);
		}
		i = i + j;
		if (s[i])
			i++;
	}
	tab[word] = NULL;
	return (tab);
}

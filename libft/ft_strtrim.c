/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevy <ldevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 12:55:41 by ldevy             #+#    #+#             */
/*   Updated: 2021/12/07 15:17:20 by ldevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_isset(char c, const char *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static	size_t	ft_msize(const char *s1, const char *set)
{
	size_t	i;
	size_t	size;
	size_t	trash;

	trash = 0;
	i = 0;
	while (ft_isset(s1[i], set))
	{
		trash++;
		i++;
	}
	i = ft_strlen(s1) - 1;
	while (ft_isset(s1[i], set))
	{
		trash++;
		if (i > 0)
			i--;
		else
			return (1);
	}
	size = 1 + ft_strlen(s1) - trash;
	return (size);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*new;
	size_t	i;
	size_t	j;
	size_t	msize;

	if (!s1 || !set)
		return (NULL);
	msize = ft_msize(s1, set);
	new = malloc(msize * sizeof(*s1));
	if (!new)
		return (NULL);
	i = 0;
	j = 0;
	while (ft_isset(s1[i], set))
		i++;
	while (j < msize - 1)
	{
		new[j] = s1[i];
		j++;
		i++;
	}
	new[j] = '\0';
	return (new);
}

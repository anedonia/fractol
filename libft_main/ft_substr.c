/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevy <ldevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 20:13:29 by ldevy             #+#    #+#             */
/*   Updated: 2021/12/13 20:14:00 by ldevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*new;
	size_t		i;
	size_t		size;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		size = 1;
	else if (len > ft_strlen(s) - start + 1)
		size = ft_strlen(s) - start + 1;
	else
		size = len + 1;
	new = malloc(size * sizeof(*new));
	if (!new)
		return (NULL);
	i = 0;
	while (i < len && start < ft_strlen(s))
	{
		new[i] = s[start];
		i++;
		start++;
	}
	new[i] = '\0';
	return (new);
}

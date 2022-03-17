/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevy <ldevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 13:15:56 by ldevy             #+#    #+#             */
/*   Updated: 2021/12/06 14:54:10 by ldevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	temp_len;

	i = 0;
	if (!little[i])
		return ((char *) big);
	while (big[i] && len > 0)
	{
		j = 0;
		temp_len = len;
		while (big[i + j] == little[j] && temp_len > 0)
		{
			j++;
			temp_len--;
			if (!little[j])
				return ((char *) big + i);
		}
		len--;
		i++;
	}
	return (NULL);
}

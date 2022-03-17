/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevy <ldevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 15:19:53 by ldevy             #+#    #+#             */
/*   Updated: 2021/12/06 14:51:58 by ldevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (!dest && !src)
		return (0);
	i = 0;
	if ((size_t)dest < (size_t)src)
	{
		while (n > 0)
		{
			((char *)dest)[i] = ((char *)src)[i];
			n--;
			i++;
		}
	}
	else
	{
		i = n - 1;
		while (n > 0)
		{
			((char *)dest)[i] = ((char *)src)[i];
			n--;
			i--;
		}
	}
	return (dest);
}

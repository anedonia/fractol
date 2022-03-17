/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevy <ldevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 14:32:38 by ldevy             #+#    #+#             */
/*   Updated: 2021/12/07 15:44:49 by ldevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	size_t	i;
	size_t	size;

	if (!s || !fd)
		return ;
	i = 0;
	while (s[i])
	{
		size = sizeof(s[i]);
		write (fd, &s[i], size);
		i++;
	}
	write (fd, "\n", 1);
}

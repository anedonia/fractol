/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevy <ldevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 16:29:06 by ldevy             #+#    #+#             */
/*   Updated: 2022/03/25 17:16:27 by ldevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	ft_color_int(float ite)
{
	float r;
	float g;
	float b;
	
	r = 255 * ((1 - cos(ite / log(2))) / 2);
	g = 255 * ((1 - cos(ite * (1 / ((3 * sqrt(2)) / log(2))))) / 2);
	b = 255 * ((1 - cos(ite * (1 / ((7 * pow(3, 1/8)) / log(2))))) / 2);
	return (create_trgb(0, r, g, b));
}


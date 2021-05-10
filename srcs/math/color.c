/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deulee <deulee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 20:48:28 by deulee            #+#    #+#             */
/*   Updated: 2021/05/10 17:15:40 by deulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		color_product(int color, double coef)
{
	int	r;
	int	g;
	int	b;
	int	mask;

	mask = 255;
	r = coef * ((color & (mask << 16)) >> 16);
	g = coef * ((color & (mask << 8)) >> 16);
	b = coef * (color & mask);
	r = r < 255 ? r : 255;
	g = g < 255 ? g : 255;
	b = b < 255 ? b : 255;
	r = r << 16;
	g = g << 8;
	return (r | g | b);
}

int		color_add(int x, int y)
{
	int	mask;
	int	r;
	int	g;
	int	b;

	mask = 255;
	r = ((x & (mask << 16)) + (y & (mask << 16))) & (mask << 16);
	g = ((x & (mask << 8)) + (y & (mask << 8))) & (mask << 8);
	b = ((x & mask) + (y & mask)) & mask;
	return (r | g | b);
}

int		color_difference(int x, int y)
{
	int	mask;
	int	r[2];
	int	g[2];
	int	b[2];
	int	distance_power2;

	mask = 255;
	r[0] = (x & (mask << 16)) >> 16;
	r[1] = (y & (mask << 16)) >> 16;
	g[0] = (x & (mask << 8)) >> 8;
	g[1] = (y & (mask << 8)) >> 8;
	b[0] = x & mask;
	b[1] = y & mask;
	distance_power2 = pow((r[1] - r[0]), 2) + pow((g[1] - g[0]), 2) +
		pow((b[1] - b[0]), 2);
	return (distance_power2);
}

int		color_light(int color, t_color rgb)
{
	unsigned int	mask;
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;

	mask = 255;
	r = rgb.x * ((color & (mask << 16)) >> 16);
	g = rgb.y * ((color & (mask << 8)) >> 8);
	b = rgb.z * (color & mask);
	r = r < 255 ? r : 255;
	g = g < 255 ? g : 255;
	b = b < 255 ? b : 255;
	return ((r << 16) | (g << 8) | b);
}

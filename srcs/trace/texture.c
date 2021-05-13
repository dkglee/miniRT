/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deulee <deulee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 20:48:04 by deulee            #+#    #+#             */
/*   Updated: 2021/05/13 23:37:29 by deulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int			checkboard(t_inter *inter)
{
	int		black;
	int		white;
	t_vec	location;
	

	black = 0x000000;
	white = 0xffffff;
	location.x = abs((int)floor(inter->p.x));
	location.y = abs((int)floor(inter->p.x));
	location.z = abs((int)floor(inter->p.x));
	location.x = (int)location.x % 2;
	location.y = (int)location.y % 2;
	location.z = (int)location.z % 2;
	return ((((int)location.x ^ (int)location.y) ^ (int)location.z)
			? black : white);

}

t_vec		wave(t_inter *inter, t_object *list)
{
	double	sine;

	sine = sin(inter->p.z * list->wavelength) + sin(inter->p.y *
			list->wavelength);
	return (rotation_y(inter->norm, sine));
}

void		apply_color(double r, double g, double b, double color[3])
{
	color[0] = r;
	color[1] = g;
	color[2] = b;
}

int			rainbow(double y)
{
	double	color[3];
	double	mask;
	double	w;

	mask = 255;
	w = 540 - (y * 160);
	if (w >= 380 && w < 440)
		apply_color(-(w - 440) / (440 - 380), 0.0, 1.0, color);
	else if (w >= 440 && w < 490)
		apply_color(0.0, (w - 440) / (490 - 440), 1.0, color);
	else if (w >= 490 && w < 510)
		apply_color(0.0, 1.0, -(w - 510) / (510 - 490), color);
	else if (w >= 510 && w < 580)
		apply_color((w - 510) / (580 - 510), 1.0, 0.0, color);
	else if (w >= 580 && w < 645)
		apply_color(1.0, -(w - 645) / (645 - 580), 0.0, color);
	else if (w >= 645 && w < 780)
		apply_color(1.0, 0.0, 0.0, color);
	else
		apply_color(0.0, 0.0, 0.0, color);
	color[0] *= mask;
	color[1] *= mask;
	color[2] *= mask;
	return (((int)color[0] << 16) | ((int)color[1] << 8) | (int)color[2]);
}

void		get_texture(int	texture, t_inter *inter, t_object *list)
{
	if (texture == 1)
		inter->color = checkboard(inter);
	else if (texture == 2)
		inter->norm = wave(inter, list);
	else if (texture== 3)
		inter->color = rainbow(inter->norm.y);
}

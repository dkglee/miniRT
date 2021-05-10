/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ssaa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deulee <deulee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 15:48:15 by deulee            #+#    #+#             */
/*   Updated: 2021/05/10 18:45:38 by deulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"


int		ssaa_zero(int *color, int c_col, t_tmp tmp, t_render *render)
{
	t_tmp	tmp_r;
	int		*subtable;
	int		c;

	subtable = (int *)malloc(sizeof(int) * 4);
	if (subtable == NULL)
		error("Malloc Error", NULL, NULL);
	subtable[0] = color[0];
	subtable[1] = calc_ray(1, tmp, render);
	subtable[2] = calc_ray(3, tmp, render);
	subtable[3] = c_col;
	tmp_r.limit = tmp.limit - 1;
	tmp_r.i = tmp.i * 2 - 1;
	tmp_r.j = tmp.j * 2 - 1;
	tmp_r.x_res = tmp.y_res * 2;
	tmp_r.y_res = tmp.y_res * 2;
	c = super_sample(subtable, tmp_r, render);
	return (c);
}

int		ssaa_one(int *color, int c_col, t_tmp tmp, t_render *render)
{
	t_tmp	tmp_r;
	int		*subtable;
	int		c;

	subtable = (int *)malloc(sizeof(int) * 4);
	if (subtable == NULL)
		error("Malloc Error", NULL, NULL);
	subtable[0] = calc_ray(3, tmp, render);
	subtable[1] = color[1];
	subtable[2] = c_col;
	subtable[3] = calc_ray(5, tmp, render);
	tmp_r.limit = tmp.limit - 1;
	tmp_r.i = tmp.i * 2 - 1;
	tmp_r.j = tmp.j * 2 - 1;
	tmp_r.x_res = tmp.y_res * 2;
	tmp_r.y_res = tmp.y_res * 2;
	c = super_sample(subtable, tmp_r, render);
	return (c);
}

int		ssaa_two(int *color, int c_col, t_tmp tmp, t_render *render)
{
	t_tmp	tmp_r;
	int		*subtable;
	int		c;

	subtable = (int *)malloc(sizeof(int) * 4);
	if (subtable == NULL)
		error("Malloc Error", NULL, NULL);
	subtable[0] = calc_ray(3, tmp, render);
	subtable[1] = c_col;
	subtable[2] = color[2];
	subtable[3] = calc_ray(7, tmp, render);
	tmp_r.limit = tmp.limit - 1;
	tmp_r.i = tmp.i * 2 - 1;
	tmp_r.j = tmp.j * 2 - 1;
	tmp_r.x_res = tmp.y_res * 2;
	tmp_r.y_res = tmp.y_res * 2;
	c = super_sample(subtable, tmp_r, render);
	return (c);
}

int		ssaa_three(int *color, int c_col, t_tmp tmp, t_render *render)
{
	t_tmp	tmp_r;
	int		*subtable;
	int		c;

	subtable = (int *)malloc(sizeof(int) * 4);
	if (subtable == NULL)
		error("Malloc Error", NULL, NULL);
	subtable[0] = c_col;
	subtable[1] = calc_ray(5, tmp, render);
	subtable[2] = calc_ray(7, tmp, render);
	subtable[3] = color[3];
	tmp_r.limit = tmp.limit - 1;
	tmp_r.i = tmp.i * 2 - 1;
	tmp_r.j = tmp.j * 2 - 1;
	tmp_r.x_res = tmp.y_res * 2;
	tmp_r.y_res = tmp.y_res * 2;
	c = super_sample(subtable, tmp_r, render);
	return (c);
}

int		super_sample(int *color, t_tmp tmp, t_render *render)
{
	int		c_color;
	int		i;

	c_color = calc_ray(4, tmp, render);
	i = 0;
	while (i < 4)
	{
		if (!color_difference(color[i], c_color) || tmp.limit == 0)
			color[i] = calc_avg_simple_color(color[i], c_color);
		else
		{
			if (i == 0)
				color[0] = ssaa_zero(color, c_color, tmp, render);
			else if (i == 1)
				color[1] = ssaa_one(color, c_color, tmp, render);
			else if (i == 2)
				color[2] = ssaa_two(color, c_color, tmp, render);
			else
				color[3] = ssaa_three(color, c_color, tmp, render);
		}
		i++;
	}
	return (calc_avg_ssaa_color(color));
}

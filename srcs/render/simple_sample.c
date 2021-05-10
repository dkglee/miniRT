/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sample.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deulee <deulee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 11:25:16 by deulee            #+#    #+#             */
/*   Updated: 2021/05/10 18:39:48 by deulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		*sample_first(int *edge, int last[2], t_tmp tmp, t_render *render)
{
	int		*color;

	color = NULL;
	color = (int *)malloc(sizeof(int) * 4);
	if (color == NULL)
		error("Malloc Error", NULL, NULL);
	if (tmp.j == render->trace.y_res / NUM_THREADS * render->idx)
	{
		color[0] = calc_ray(0, tmp, render);
		color[1] = calc_ray(2, tmp, render);
		color[2] = calc_ray(6, tmp, render);
		color[3] = calc_ray(8, tmp, render);
		last[0] = color[1];
		last[1] = color[3];
		edge[0] = color[2];
	}
	else
	{
		color[0] = edge[0];
		color[1] = edge[1];
		color[2] = calc_ray(6, tmp, render);
		color[3] = calc_ray(8, tmp, render);
		last[0] = color[3];
		edge[0] = color[2];
	}
	return (color);
}

int		*sample_center(int *edge, int last[2], t_tmp tmp, t_render *render)
{
	int		*color;

	color = NULL;
	color = (int *)malloc(sizeof(int) * 4);
	if (color == NULL)
		error("Malloc Error", NULL, NULL);
	if (tmp.j == render->trace.y_res / NUM_THREADS * render->idx)
	{
		color[0] = last[0];
		color[1] = calc_ray(2, tmp, render);
		color[2] = last[1];
		color[3] = calc_ray(8, tmp, render);
		last[0] = color[1];
		last[1] = color[3];
		edge[tmp.i] = color[2];
	}
	else
	{
		color[0] = edge[tmp.i];
		color[1] = edge[tmp.i + 1];
		color[2] = last[0];
		color[3] = calc_ray(3, tmp, render);
		edge[tmp.i] = color[2];
		edge[tmp.i + 1] = color[3];
	}
	return (color);
}

int		*sample_last(int *edge, int last[2], t_tmp tmp, t_render *render)
{
	int		*color;

	color = NULL;
	color = (int *)malloc(sizeof(int) * 4);
	if (color == NULL)
		error("Malloc Error", NULL, NULL);
	if (tmp.j == render->trace.y_res / NUM_THREADS * render->idx)
	{
		color[0] = last[0];
		color[1] = calc_ray(2, tmp, render);
		color[2] = last[1];
		color[3] = calc_ray(8, tmp, render);
		edge[tmp.i] = color[2];
		edge[tmp.i] = color[3];
	}
	else
	{
		color[0] = edge[tmp.i];
		color[1] = edge[tmp.i + 1];
		color[2] = last[0];
		color[3] = calc_ray(3, tmp, render);
		edge[tmp.i] = color[2];
		edge[tmp.i + 1] = color[3];
	}
	return (color);
}

int		*simple_sample(int *edge, int last[2], t_tmp tmp, t_render *render)
{
	int		*color;

	if (tmp.i == 0)
		color = sample_first(edge, last, tmp, render);
	else if (tmp.i == render->trace.x_res - 1)
		color = sample_last(edge, last, tmp, render);
	else
		color = sample_center(edge, last, tmp, render);
	return (color);
}

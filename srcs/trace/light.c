/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deulee <deulee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 17:12:29 by deulee            #+#    #+#             */
/*   Updated: 2021/05/14 21:09:03 by deulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	apply_shading(t_ray ray, t_inter *inter, t_scene trace, t_object *list)
{
	double		rgb[3];
	double		light;
	t_vec		dir;

	light = 0.0;
	ft_memset(rgb, 0, 3 * sizeof(double));
	add_light(&rgb, trace.amb_light, trace.amb_color);
	while (trace.light)
	{
		dir = ft_vec_sub(trace.light->o, inter->p);
		if (valid_bright(inter->p, dir, list) &&
				ft_vec_dot(inter->norm, dir) > 0)
		{
			light = trace.light->br * ft_vec_cos(inter->norm, dir);
			add_light(&rgb, light, trace.light->color);
		}
		if (list->specular)
		{
			light = apply_specular(ray, inter, trace, list);
			add_light(&rgb, light, trace.light->color);
		}
		trace.light = trace.light->next;
	}
	inter->color = color_light(inter->color, rgb);
//	inter->color = inter->color;
}

void	get_norm(t_vec p, t_vec d, t_vec *normal, t_object *list)
{
	if (list->flag == SP)
	{
		*normal = ft_vec_unit(ft_vec_sub(p, list->fig.sp.center));
		if (ft_vec_cos(d, *normal) > 0)
		{
			*normal = ft_vec_product(-1, *normal);
			list->fig.sp.inside = 1;
		}
		else
			list->fig.sp.inside = 0;
	}
	else
	{
		if (ft_vec_cos(d, list->normal) > 0)
			*normal = ft_vec_product(-1, list->normal);
		else
			*normal = list->normal;
	}
}

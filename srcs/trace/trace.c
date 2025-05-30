/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deulee <deulee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 14:24:36 by deulee            #+#    #+#             */
/*   Updated: 2021/05/14 19:38:34 by deulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	find_intersection(t_ray ray, t_object *list,
		t_object *closet_obj, double *closet_dis)
{
	double	dist;

	while (list)
	{
		if (list->flag == SP)
			dist = sphere_intersection_point(ray.origin, ray.dir, list);
		else if (list->flag == PL)
			dist = plane_intersection_point(ray.origin, ray.dir, list);
		else if (list->flag == SQ)
			dist = square_intersection_point(ray.origin, ray.dir, list);
		else if (list->flag == TR)
			dist = triangle_intersection_point(ray.origin, ray.dir, list);
		else if (list->flag == CY)
			dist = cylinder_intersection_point(ray.origin, ray.dir, list);
		else if (list->flag == CU)
			dist = cube_intersection_point(ray.origin, ray.dir, list);
		else if (list->flag == PY)
			dist = pyramid_intersection_point(ray.origin, ray.dir, list);
		if (dist < *closet_dis && dist > EPSILON)
		{
			*closet_dis = dist;
			*closet_obj = *list;
		}
		list = list->next;
	}
}

void	init_information(t_object *cl_obj, double *cl_dis)
{
	cl_obj->flag = -1;
	*cl_dis = INFINITY;
}

int		ray_trace(t_vec origin, t_vec dir, t_render *render, int depth)
{
	t_ray		ray;
	t_object	closet_obj;
	t_inter		inter;
	double		closet_dis;

	init_information(&closet_obj, &closet_dis);
	ray.origin = origin;
	ray.dir = dir;
	find_intersection(ray, render->list, &closet_obj, &closet_dis);
	inter.p = ft_vec_add(origin, ft_vec_product(closet_dis, dir));
	get_norm(inter.p, dir, &(inter.norm), &closet_obj);
	inter.color = closet_obj.flag != -1 ? closet_obj.color : render->trace.bgr;
	get_texture(closet_obj.texture, &inter, render->list);
	apply_shading(ray, &inter, render->trace, render->list);
	closet_obj.refrac = closet_obj.flag != -1 ? closet_obj.refrac : 0;
	closet_obj.reflec = closet_obj.flag != -1 ? closet_obj.reflec : 0;
	if (closet_obj.refrac > 0)
		inter.color = ray_trace(inter.p,
				refraction(dir, inter.norm, &closet_obj), render, depth);
	if (closet_obj.reflec > 0 && depth > 0)
		inter.ref_color = ray_trace(inter.p,
				reflection(ft_vec_product(-1, dir), inter.norm), render, depth - 1);
	return (color_add(color_product(inter.color, 1 - closet_obj.reflec),
				color_product(inter.ref_color, closet_obj.reflec)));
}

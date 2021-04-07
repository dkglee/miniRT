/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deulee <deulee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 14:24:36 by deulee            #+#    #+#             */
/*   Updated: 2021/04/07 16:01:48 by deulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	find_intersection(t_ray ray, t_render *list,
		t_object *closet_obj, double *closet_dis)
{
	double	dis;

	while (list)
	{
		if (lst->flag == SP)
			dist = sphere_intersection_point(ray.origin, ray.dir, list);
		if (lst->flag == PL)
			dist = plane_intersection_point(ray.origin, ray.dir, list);
		if (lst->flag == SQ)
			dist = square_intersection_point(ray.origin, ray.dir, list);
		if (lst->flag == TR)
			dist = triangle_intersection_point(ray.origin, ray.dir, list);
		if (lst->flag == CY)
			dist = cylinder_intersection_point(ray.origin, ray.dir, list);
		if (lst->flag == CU)
			dist = cube_intersection_point(ray.origin, ray.dir, list);
		if (lst->flag == PY)
			dist = pyramid_intersection_point(ray.origin, ray.dir, list);
		if (dist < *closet_dis && dist > EPSILON)
		{
			*closet_dis = dis;
			*closet_obj = *list;
		}
		list = list->next;
	}
}

int		ray_trace(t_vec origin, t_vec dir, t_render *render, int depth)
{
	t_ray		ray;
	t_object	closet_obj;
	t_inter		inter;
	double		closet_dis;
	double		r;

	ray.origin = origin;
	ray.dir = dir;
	closet_dis = INFINITY;
	cl_fig.flag = -1;
	find_intersection(ray, render->list, &closet_obj, &closet_dis);
}

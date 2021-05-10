/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle_intersection.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deulee <deulee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 17:16:54 by deulee            #+#    #+#             */
/*   Updated: 2021/05/10 19:09:30 by deulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool	check_point_inside(t_vec p1, t_vec p2, t_vec p3, t_vec point)
{
	t_vec	v1;
	t_vec	v2;
	t_vec	vp;

	v1 = ft_vec_sub(p2, p1);
	v2 = ft_vec_sub(p3, p1);
	vp = ft_vec_sub(point, p1);
	if (ft_vec_cos(cross(v1, v2), cross(v1, vp)) < 0)
		return (false);
	v1 = ft_vec_sub(p3, p2);
	v2 = ft_vec_sub(p1, p2);
	vp = ft_vec_sub(point, p2);
	if (ft_vec_cos(cross(v1, v2), cross(v1, vp)) < 0)
		return (false);
	v1 = ft_vec_sub(p1, p3);
	v2 = ft_vec_sub(p2, p3);
	vp = ft_vec_sub(point, p3);
	if (ft_vec_cos(cross(v1, v2), cross(v1, vp)) < 0)
		return (false);
	return (true);
}

double	triangle_intersection_point(t_vec origin, t_ved dir, t_object *list)
{
	double	dis;
	t_vec	point;

	dis = intersection_plane(origin, dir, list->fig.tr.p1, list->normal);
	point = ft_vec_add(origin, ft_vec_product(dis, dir));
	if (!check_point_inside(list->fig.tr.p1, list->fig.tr.p2, list->fig.tr.p3, point))
		return (INFINITY);
	return (dis);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square_intersection.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deulee <deulee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 16:49:23 by deulee            #+#    #+#             */
/*   Updated: 2021/05/10 20:51:39 by deulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	square_intersection_point(t_vec origin, t_vec dir, t_object *list)
{
	t_vec	point;
	t_sq	sq_info;
	double	cosin;
	double	limit;
	double	dis;

	dis = intersection_plane(origin, dir, list->fig.sq.center, list->normal);
	point = ft_vec_add(origin, ft_vec_product(dis, dir));
	sq_info.floor = fabs(list->normal.y) == 1 ? ft_vec_set(1, 0, 0) : ft_vec_set(0, 1, 0);
	sq_info.half_size = ft_vec_cross(list->normal, sq_info.floor);
	sq_info.center_to_point = ft_vec_sub(point, list->fig.sq.center);
	cosin = fabs(ft_vec_cos(sq_info.half_size, sq_info.center_to_point));
	if (cosin < sqrt(2) / 2)
		cosin = cos(M_PI_2 - acos(cosin));
	limit = (list->fig.sq.side / 2) / cosin;
	if (ft_vec_size(sq_info.center_to_point) <= limit)
		return (dis);
	return (INFINITY);
}

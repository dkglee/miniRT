/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_intersection.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deulee <deulee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 16:36:59 by deulee            #+#    #+#             */
/*   Updated: 2021/04/07 16:49:16 by deulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double		intersection_plane(t_vec origin, t_vec dir, t_vec point, t_vec nv)
{
	double	dis;
	double	denom;

	denom = ft_vec_dot(nv, d);
	if (denom == 0)
		return (INFINITY);
	x = ft_vec_dot(nv, ft_vec_sub(point, origin)) / denom;
	return (x > 0 ? x : INFINITY);
}

double		plane_intersection_point(t_vec origin, t_vec dir, t_object *list)
{
	return (intersection_plane(origin, dir, list->fig.pl.p, list->normal));
}

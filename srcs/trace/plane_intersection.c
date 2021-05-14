/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_intersection.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deulee <deulee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 16:36:59 by deulee            #+#    #+#             */
/*   Updated: 2021/05/14 14:38:22 by deulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double		intersection_plane(t_vec origin, t_vec dir, t_vec point, t_vec nv)
{
	double	dis;
	double	denom;

	denom = ft_vec_dot(nv, dir);
	if (denom == 0)
		return (INFINITY);
	dis = ft_vec_dot(nv, ft_vec_sub(point, origin)) / denom;
	if (dis > 0)
		return (dis);
	else
		return (INFINITY);
}

double		plane_intersection_point(t_vec origin, t_vec dir, t_object *list)
{
	return (intersection_plane(origin, dir, list->fig.pl.p, list->normal));
}

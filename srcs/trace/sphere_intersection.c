/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_intersection.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deulee <deulee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 16:02:08 by deulee            #+#    #+#             */
/*   Updated: 2021/05/03 17:31:57 by deulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void		intersection_sphere(double dis[2], t_vec origin, t_vec dir, t_object *list)
{
	double	discriminant;
	t_vec	oc;
	double	a;
	double	b;
	double	c;

	oc = ft_vec_sub(o, list->fig.sp.center);
	a = ft_vec_dot(dir, dir);
	b = 2 * ft_vec_dot(dir, oc);
	c = dot(oc, oc) - pow(list->fig.sp.radius, 2);
	discriminant = (b * b) - (4 * a * c);
	if (discriminant < 0)
	{
		dis[0] = INFINITY;
		dis[1] = INFINITY;
		return ;
	}
	dis[0] = (-b + sqrt(discriminant)) / (2 * a);
	dis[1] = (-b - sqrt(discriminant)) / (2 * a);
}

double			sphere_intersection_point(t_vec origin, t_vec dir, t_object *list)
{
	double	closest_distance;
	double	distance[2];
	t_vec	p1;
	t_vec	p2;

	closest_distance = INFINITY;
	intersection_sphere(distance, origin, dir, list);
	if (dis[0] < INFINITY && dis[0] > EPSILON)
		closest_distance = dis[0];
	if (dis[1] < INFINITY && dis[1] > EPSILON)
		closest_distance = dis[1] < dis[0] ? dis[1] : closest_distance;
	if (list->texture != 4)
		return (closest_distance);
	p1 = ft_vec_add(origin, ft_vec_product(dis[0], d));
	p2 = ft_vec_add(origin, ft_vec_product(dis[1], d));
	if (p1.y >= list->fig.sp.center.y && p2.y >= list->fig.sp.center.y)
		return (dis[0] < dis[1] ? dis[0] : dis[1]);
	else if (p2.y >= list->fig.sp.center.y)
		return (dis[1]);
	else if (p1.y >= list->fig.sp.center.y)
		return (dis[0]);
	return (INFINITY);
}

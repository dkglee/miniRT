/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_intersection.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deulee <deulee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 21:38:07 by deulee            #+#    #+#             */
/*   Updated: 2021/05/16 01:12:20 by deulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool		find_distance(double dis[2], t_vec origin, t_vec dir, t_object *list)
{
	t_vec	v;
	t_vec	w;
	double	a;
	double	b;
	double	c;

	v = ft_vec_product(ft_vec_dot(dir, list->fig.cy.nv), list->fig.cy.nv);
	v = ft_vec_sub(dir, v);
	w = ft_vec_product(ft_vec_dot(ft_vec_sub(origin, list->fig.cy.center),
				list->fig.cy.nv), list->fig.cy.nv);
	w = ft_vec_sub(ft_vec_sub(origin, list->fig.cy.center), w);
	a = ft_vec_dot(v, v);
	b = 2 * ft_vec_dot(v, w);
	c = ft_vec_dot(w, w) - pow(list->fig.cy.radius, 2);
	dis[0] = (-b + sqrt(pow(b, 2) - 4 * a * c)) / (2 * a);
	dis[1] = (-b - sqrt(pow(b, 2) - 4 * a * c)) / (2 * a);
	if (((dis[0] < EPSILON) && (dis[1] < EPSILON)) ||
			((dis[0] != dis[0]) && (dis[1] != dis[1])))
	{
		dis[0] = INFINITY;
		dis[1] = INFINITY;
		return (false);
	}
	return (true);
}

t_vec		get_cy_normal(double dis[2], t_vec origin, t_vec dir, t_object *list)
{
	double	dist;
	double	x;

	if ((list->fig.cy.dist1 >= 0 && list->fig.cy.dist1 <= list->fig.cy.height
			&& dis[0] > EPSILON) && (list->fig.cy.dist2 >= 0 &&
			list->fig.cy.dist2 <= list->fig.cy.height && dis[1] > EPSILON))
	{
		dist = dis[0] < dis[1] ? list->fig.cy.dist1 : list->fig.cy.dist2;
		x = dis[0] < dis[1] ? dis[0] : dis[1];
	}
	else if (list->fig.cy.dist1 >= 0 && list->fig.cy.dist1 <=
			list->fig.cy.height && dis[0] > EPSILON)
	{
		dist = list->fig.cy.dist1;
		x = dis[0];
	}
	else
	{
		dist = list->fig.cy.dist2;
		x = dis[1];
	}
	dis[0] = x;
	return (ft_vec_unit(ft_vec_sub(ft_vec_sub(ft_vec_product(x, dir),
			ft_vec_product(dist, list->fig.cy.nv)),
					ft_vec_sub(list->fig.cy.center, origin))));
}

double		intersection_cylinder(t_vec origin, t_vec dir, t_vec *cy_normal, t_object *list)
{
	double	dis[2];
	bool	flag;

	flag = find_distance(dis, origin, dir, list);
	if (flag == false)
		return (INFINITY);
	list->fig.cy.dist1 = ft_vec_dot(list->fig.cy.nv, ft_vec_sub(
				ft_vec_product(dis[0], dir), ft_vec_sub(list->fig.cy.center,
					origin)));
	list->fig.cy.dist2 = ft_vec_dot(list->fig.cy.nv, ft_vec_sub(
				ft_vec_product(dis[1], dir), ft_vec_sub(list->fig.cy.center,
					origin)));
	if (!((list->fig.cy.dist1 >= 0 && list->fig.cy.dist1 <= list->fig.cy.height
					&& dis[0] > EPSILON) || (list->fig.cy.dist2 >= 0 &&
						list->fig.cy.dist2 <= list->fig.cy.height && dis[1] >
						EPSILON)))
		return (INFINITY);
	*cy_normal = get_cy_normal(dis, origin, dir, list);
	return (dis[0]);
}

double		intersection_circle(t_vec origin, t_vec dir, t_object *list)
{
	double	dis[2];
	t_vec	point1;
	t_vec	point2;
	t_vec	circle2;

	circle2 = ft_vec_add(list->fig.cy.center,
			ft_vec_product(list->fig.cy.height, list->fig.cy.nv));
	dis[0] = intersection_plane(origin, dir, list->fig.cy.center, list->fig.cy.nv);
	dis[1] = intersection_plane(origin, dir, circle2, list->fig.cy.nv);
	if (dis[0] < INFINITY || dis[1] < INFINITY)
	{
		point1 = ft_vec_add(origin, ft_vec_product(dis[0], dir));
		point2 = ft_vec_add(origin, ft_vec_product(dis[1], dir));
		if ((dis[0] < INFINITY && ft_vec_dis(point1, list->fig.cy.center) <=
					list->fig.cy.radius) && (dis[1] < INFINITY &&
						ft_vec_dis(point2, circle2) <= list->fig.cy.radius))
			return (dis[0] < dis[1] ? dis[0] : dis[1]);
		else if (dis[0] < INFINITY && ft_vec_dis(point1, list->fig.cy.center) <=
				list->fig.cy.radius)
			return (dis[0]);
		else if (dis[1] < INFINITY && ft_vec_dis(point2, circle2) <=
				list->fig.cy.radius)
			return (dis[1]);
		return (INFINITY);
	}
	return (INFINITY);
}

double		cylinder_intersection_point(t_vec origin, t_vec dir, t_object *list)
{
	double	cylinder_dis;
	double	circle_dis;
	t_vec	cy_normal;

	cylinder_dis = intersection_cylinder(origin, dir, &cy_normal, list);
	if (list->texture == 4)
		circle_dis = INFINITY;
	else
		circle_dis = intersection_circle(origin, dir, list);
	if (cylinder_dis < INFINITY || circle_dis < INFINITY)
	{
		if (cylinder_dis < circle_dis)
		{
			list->normal = cy_normal;
			return (cylinder_dis);
		}
		list->normal = list->fig.cy.nv;
		return (circle_dis);
	}
	return (INFINITY);
}

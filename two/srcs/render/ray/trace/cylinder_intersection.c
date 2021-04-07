/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_intersection.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deulee <deulee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 21:38:07 by deulee            #+#    #+#             */
/*   Updated: 2021/04/07 23:40:57 by deulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double		intersection_cylinder(t_vec origin, t_vec dir, t_object *list)
{
	dou
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
	if (dis[0] < INFINITY || dis[0] < INFINITY)
	{
		point1 = ft_vec_add(origin, ft_vec_product(dis[0], dir));
		point2 = ft_vec_add(origin, ft_vec_product(dis[1], dir));
		if ((dis[0] < INFINITY && ft_vec_dis(point1, list->fig.cy.center) <=
					list->fig.cy.radius) && (dis[1] < INFINITY &&
						ft_vec_dis(point2, circle2) <= list->fig.cy>radisu))
			return (dis[0] < dis[1] ? dis[0] : dis[1]);
		else if (dis[0] < INFINITY && distance(point1, list->fig.cy.center) <=
				list->fit.cy.radius)
			return (dis[0]);
		else if (dis[1] < INFINITY && distance(point2, circle2) <=
				list->fit.cy.radius)
			return (dis[1]);
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
}

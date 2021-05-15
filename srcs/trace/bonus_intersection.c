/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_intersection.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deulee <deulee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 21:30:01 by deulee            #+#    #+#             */
/*   Updated: 2021/05/16 00:42:18 by deulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void		make_cube(t_cube *f, t_object *list)
{
	f->normal[0] = ft_vec_set(1, 0, 0);
	f->normal[1] = ft_vec_set(-1, 0, 0);
	f->normal[2] = ft_vec_set(0, 1, 0);
	f->normal[3] = ft_vec_set(0, -1, 0);
	f->normal[4] = ft_vec_set(0, 0, 1);
	f->normal[5] = ft_vec_set(0, 0, -1);
	f->center = list->fig.sq.center;
	f->sq.fig.sq.side = list->fig.sq.side;
}

double		cube_intersection_point(t_vec o, t_vec d, t_object *list)
{
	t_cube		f;
	t_vec		c_norm;
	double		c_inter;
	double		dis;
	int			i;

	i = 0;
	c_inter = INFINITY;
	make_cube(&f, list);
	while (i < 6)
	{
		f.sq.fig.sq.center = ft_vec_add(f.center,
				ft_vec_product(list->fig.sq.side / 2, f.normal[i]));
		f.sq.normal = f.normal[i];
		dis = square_intersection_point(o, d, &(f.sq));
		if (dis > EPSILON && dis < c_inter)
		{
			c_inter = dis;
			c_norm = f.sq.normal;
		}
		i++;
	}
	list->normal = c_norm;
	return (c_inter);
}

void		make_pyramid(t_pyramid *f, t_object *list)
{
	int		i;
	t_vec	tmp;

	i = 0;
	tmp = ft_vec_set(0, 1, 0);
	f->normal[0] = ft_vec_set(1, 0, 0);
	f->normal[1] = ft_vec_set(0, 0, 1);
	f->normal[2] = ft_vec_set(-1, 0, 0);
	f->normal[3] = ft_vec_set(0, 0, -1);
	f->normal[4] = ft_vec_set(1, 0, 0);
	f->center = ft_vec_add(list->fig.sq.center,
			ft_vec_product(list->fig.sq.side, tmp));
	f->sq.fig.sq.side = list->fig.sq.side;
	f->sq.fig.sq.center = list->fig.sq.center;
	f->sq.normal = ft_vec_set(0, -1, 0);
	while (i < 4)
	{
		f->corner[i] = ft_vec_add(list->fig.sq.center,
				ft_vec_product(list->fig.sq.side / 2, f->normal[i]));
		f->corner[i] = ft_vec_add(f->corner[i],
				ft_vec_product(list->fig.sq.side / 2, f->normal[i + 1]));
		i++;
	}
	f->tr.fig.tr.p3 = f->center;
}

double		pyramid_intersection_point(t_vec o, t_vec d, t_object *list)
{
	t_pyramid	f;
	t_vec		c_norm;
	double		c_inter;
	double		dis;
	int			i;

	i = 0;
	make_pyramid(&f, list);
	c_inter = INFINITY;
	while (i < 4)
	{
		f.tr.fig.tr.p1 = f.corner[i];
		f.tr.fig.tr.p2 = i < 3 ? f.corner[i + 1] : f.corner[0];
		f.tr.normal = ft_vec_cross(ft_vec_sub(f.tr.fig.tr.p3,
					f.tr.fig.tr.p1), ft_vec_sub(f.tr.fig.tr.p2,
						f.tr.fig.tr.p1));
		dis = triangle_intersection_point(o, d, &(f.tr));
		if (dis > EPSILON && dis < c_inter)
		{
			c_inter = dis;
			c_norm = f.tr.normal;
		}
		i++;
	}
	list->normal = c_norm;
	return (c_inter);
}

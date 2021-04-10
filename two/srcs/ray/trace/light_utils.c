/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deulee <deulee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 21:00:20 by deulee            #+#    #+#             */
/*   Updated: 2021/04/10 22:34:55 by deulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	add_light(double (*rgb)[3], double ratio, int color)
{
	unsigned int	mask;

	mask = 255;
	(*rgb)[0] += ratio * ((color & (mask << 16)) >> 16) / 255;
	(*rgb)[1] += ratio * ((color & (mask << 8)) >> 8) / 255;
	(*rgb)[2] += ratio * (color & mask) / 255;
}

t_vec	reflection(t_vec ray, t_vec normal)
{
	t_vec	result;

	result = ft_vec_sub(ft_vec_product(2 * ft_vec_dot(normal, ray),
				normal), ray);
	return (result);
}

t_vec	refraction(t_vec dir, t_vec normal, t_object *list)
{
	double	cosi;
	double	etai;
	double	etat;
	double	eta;
	double	k;

	etai = 1;
	etat = list->refrac;
	cosi = dot(dir, normal);
	if (list->fig.sp.inside == 1)
	{
		k = etai;
		etai = etat;
		etat = k;
	}
	eta = etai / etat;
	k = 1 - eta * eta * (1 - cosi * cosi);
	if (k < 0)
		return (reflection(ft_vec_product(-1, dir), normal));
	return (ft_vec_add(ft_vec_product(eta, dir),
				ft_vec_product(eta * cosi - sqrt(k), normal)));
	
}

double	apply_specular(t_vec ray, t_inter *inter, t_scene trace, t_object *list)
{
	double	light;
	t_vec	vec_to_obj;
	t_vec	vec_to_cam;
	t_vec	reflection;

	vec_to_obj = ft_vec_sub(trace.light->o, inter->p);
	vec_to_cam = ft_vec_sub(ray.origin, inter->p);
	reflec = reflecion(vec_to_obj, inter->normal);
	if (dot(reflec, vec_to_cam) <= 0)
		light = 0;
	else
	{
		light = trace.light->br * 
			pow(ft_vec_cos(reflec, vec_to_cam), list->specular);
	}
	return (light);
}

bool	valid_bright(t_vec o, t_vec d, t_object *list)
{
	double	flag;

	while (list)
	{
		if (list->flag == SP)
			flag = sphere_intersection_point(o, d, list);
		else if (list->flag == PL)
			flag = plane_intersection_point(o, d, list);
		else if (list->flag == TR)
			flag = triangle_intersection_point(o, d, list);
		else if (list->flag == SQ)
			flag = square_intersection_point(o, d, list);
		else if (list->flag == CY)
			flag = cylinder_intersection_point(o, d, list);
		else if (list->flag == CU)
			flag = cube_intersection_point(o, d, list);
		else if (list->flag == PY)
			flag = pyramid_intersection_point(o, d, list);
		if (flag > EPSILON && flag < 1)
			return (false);
		list = list->next;
	}
	return (true);
}

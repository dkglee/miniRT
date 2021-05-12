/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_objects.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deulee <deulee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 21:51:33 by deulee            #+#    #+#             */
/*   Updated: 2021/05/12 18:50:04 by deulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	parse_sphere(t_parse *parse, t_object *list)
{
	t_object	*new;

	new = ft_new_object(list);
	if (count_info(parse->info) != 9)
		error("Sphere Information Number Error", parse_error, parse);
	if (!validation_extraction(parse->info + 1, SP))
		error("Sphere Information Error", parse_error, error);
	new->flag = SP;
	if (!parse_vec(parse->info[1], &new->fig.sp.center) ||
			!parse_double(parse->info[2], &new->fig.sp.radius) ||
			!parse_int(parse->info[3], &new->specular) ||
			!parse_double(parse->info[4], &new->reflec) ||
			!parse_double(parse->info[5], &new->refrac) ||
			!parse_int(parse->info[6], &new->texture) ||
			!parse_double(parse->info[7], &new->wavelength) ||
			!parse_vec_color(parse->info[8], &new->rgb_color) ||
			!validation_sphere(new))
		error("Sphere Parse Error", parse_error, error);
	new->fig.sp.radius /= 2;
	new->color = get_color(new->rgb_color);
}

void	parse_plane(t_parse *parse, t_object *list)
{
	t_object	*new;

	new = ft_new_object(list);
	if (count_info(parse->info) != 9)
		error("Plane Information Number Error", parse_error, parse);
	if (!validation_extraction(parse->info + 1, PL))
		error("Plane Information Error", parse_error, error);
	new->flag = PL;
	if (!parse_vec(parse->info[1], &new->fig.pl.p) ||
			!parse_vec(parse->info[2], &new->normal) ||
			!parse_int(parse->info[3], &new->specular) ||
			!parse_double(parse->info[4], &new->reflec) ||
			!parse_double(parse->info[5], &new->refrac) ||
			!parse_int(parse->info[6], &new->texture) ||
			!parse_double(parse->info[7], &new->wavelength) ||
			!parse_vec_color(parse->info[8], &new->rgb_color) ||
			!validation_plane(new))
		error("Plane Parse Error", parse_error, error);
	new->normal = ft_vec_unit(new->normal);
	new->color = get_color(new->rgb_color);
}

void	parse_square(t_parse *parse, t_object *list)
{
	t_object	*new;

	new = ft_new_object(list);
	if (count_info(parse->info) != 10)
		error("Square Information Number Error", parse_error, parse);
	if (!validation_extraction(parse->info + 1, SQ))
		error("Square Information Error", parse_error, error);
	new->flag = SQ;
	if (!parse_vec(parse->info[1], &new->fig.sq.center) ||
			!parse_vec(parse->info[2], &new->normal) ||
			!parse_double(parse->info[3], &new->fig.sq.side) ||
			!parse_int(parse->info[4], &new->specular) ||
			!parse_double(parse->info[5], &new->reflec) ||
			!parse_double(parse->info[6], &new->refrac) ||
			!parse_int(parse->info[7], &new->texture) ||
			!parse_double(parse->info[8], &new->wavelength) ||
			!parse_vec_color(parse->info[9], &new->rgb_color) ||
			!validation_square(new))
		error("Plane Parse Error", parse_error, error);
	new->normal = ft_vec_unit(new->normal);
	new->color = get_color(new->rgb_color);
}

void	parse_triangle(t_parse *parse, t_object *list)
{
	t_object	*new;

	new = ft_new_object(list);
	if (count_info(parse->info) != 10)
		error("Triangle Information Number Error", parse_error, parse);
	if (!validation_extraction(parse->info + 1, TR))
		error("Triangle Information Error", parse_error, error);
	new->flag = TR;
	if (!parse_vec(parse->info[1], &new->fig.tr.p1) ||
			!parse_vec(parse->info[2], &new->fig.tr.p2) ||
			!parse_vec(parse->info[3], &new->fig.tr.p3) ||
			!parse_int(parse->info[4], &new->specular) ||
			!parse_double(parse->info[5], &new->reflec) ||
			!parse_double(parse->info[6], &new->refrac) ||
			!parse_int(parse->info[7], &new->texture) ||
			!parse_double(parse->info[8], &new->wavelength) ||
			!parse_vec_color(parse->info[9], &new->rgb_color) ||
			!validation_triangle(new))
		error("Triangle Parse Error", parse_error, error);
	new->normal = ft_vec_cross(ft_vec_sub(new->fig.tr.p3, new->fig.tr.p1),
			ft_vec_sub(new->fig.tr.p2, new->fig.tr.p1));
	new->color = get_color(new->rgb_color);
}

void	parse_cylinder(t_parse *parse, t_object *list)
{
	t_object	*new;

	new = ft_new_object(list);
	if (count_info(parse->info) != 11)
		error("Cylinder Information Number Error", parse_error, parse);
	if (!validation_extraction(parse->info + 1, CY))
		error("Cylinder Information Error", parse_error, error);
	new->flag = CY;
	if (!parse_vec(parse->info[1], &new->fig.cy.center) ||
			!parse_vec(parse->info[2], &new->fig.cy.nv) ||
			!parse_double(parse->info[3], &new->fig.cy.radius) ||
			!parse_double(parse->info[4], &new->fig.cy.height) ||
			!parse_int(parse->info[5], &new->specular) ||
			!parse_double(parse->info[6], &new->reflec) ||
			!parse_double(parse->info[7], &new->refrac) ||
			!parse_int(parse->info[8], &new->texture) ||
			!parse_double(parse->info[9], &new->wavelength) ||
			!parse_vec_color(parse->info[10], &new->rgb_color) ||
			!validation_cylinder(new))
		error("Cylinder Parse Error", parse_error, error);
	new->fig.cy.radius /= 2;
	new->fig.cy.nv = ft_vec_unit(new->fig.cy.nv);
	new->color = get_color(new->rgb_color);
}

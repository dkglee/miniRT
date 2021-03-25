/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_object.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deulee <deulee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 13:33:17 by deulee            #+#    #+#             */
/*   Updated: 2021/03/25 20:11:32 by deulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	parse_sphere(t_parse *parse)
{
	t_vec	origin;
	t_vec	color;
	double	diameter;
	
	if (count_info(parse->info++) != 4)
		error("Sphere Information Number Error", parse_error, parse);
	if (!validation_extraction(parse->info))
		error("Sphere Information Error", parse_error, parse);
	if (!parse_vec(parse->info[0], &origin) ||
			!parse_double(parse->info[1], &diameter) ||
			!parse_vec(parse->info[2], &color) ||
			!validation_sphere(diameter, &color))
		error("Sphere Parse Error", parse_error, parse);
	if (!add_object(&parse->render->stuff.object,
				create_sphere(origin, diameter / 2.0, color),
				&parse->render->stuff.sp_toolbox))
		error("Malloc Sphere Error", parse_error, parse);
}

void	parse_plane(t_parse *parse)
{
	t_vec	origin;
	t_vec	orient;
	t_vec	color;

	if (count_info(parse->info++) != 4)
		error("Plane Information Number Error", parse_error, parse);
	if (!validation_extraction(parse->info))
		error("Plane Information Error", parse_error, parse);
	if (!parse_vec(parse->info[0], &origin) ||
			!parse_vec(parse->info[1], &orient) ||
			!parse_vec(parse->info[2], &color) ||
			!validatoin_plane(&orient, &color))
		error("Plane Parse Error", parse_error, parse);
	if (!add_object(&parse->render->stuff.object,
				create_plane(origin, orient, color),
				&parse->render->stuff.pl_toolbox))
		error("Malloc Plane Error", parse_error, parse);
}

void	parse_square(t_parse *parse)
{
	t_vec	origin;
	t_vec	orient;
	t_vec	color;
	double	size;

	if (count_info(parse->info++) != 5)
		error("Square Information Number Error", parse_error, parser);
	if (!validation_extraction(parse->info))
		error("Square Information Error", parse_error, parse);
	if (!parse_vec(parse->info[0], &origin) ||
			!parse_vec(parse->info[1], &orient) ||
			!parse_double(parse->info[2], &size) ||
			!parse_vec(parse->info[3], &color) ||
			!validation_square(&orient, &color, size))
		error("Sqaure Parse Error", parse_error, parse);
	if(!add_object(&parse->render->stuff.object,
				create_square(origin, orient, color, size)
				&parse->render->stuff.sq_toolbox))
		error("Malloc Sqaure Error", parse_error, parse);
}

void	parse_cylinder(t_parse *parse)
{
	t_vec	origin;
	t_vec	orient;
	t_vec	color;
	double	size[2];

	if (count_info(parse->info++) != 6)
		error("Cylinder Information Number Error", parse_error, parse);
	if (!validation_extraction(parse->info))
		error("Cylinder Information Error", parse_error, parse);
	if (!parse_vec(parse->info[0], &origin) ||
			!parse_vec(parse->info[1], &orient) ||
			!parse_double(parse->info[2], &size[0]) ||
			!parse_double(parse->info[3], &size[1]) ||
			!parse_vec(parse->info[4], &color) ||
			!validation_cylinder(&orient, &color, size))
		error("Cylinder Parse Error", parse_error, parse);
	if (!add_object(&parse->render->stuff.object,
				create_cylinder(origin, orient, color, size),
				&parse->render->stuff.cy_toolbox))
		error("Malloc Cylinder Error", parse_error, parse);
}

void	parse_triangle(t_parse *parse)
{
	t_vec	point[3];
	t_vec	color;

	if (count_info(parse->info++) != 5)
		error("Triangle Information Number Error", parse_error, parse);
	if (!validation_extraction(parse->info))
		error("Triangle Information Error", parse_error, parse);
	if (!parse_vec(parse->info[0], point) ||
			!parse_vec(parse->info[1], point + 1) ||
			!parse_vec(parse->info[2], point + 2) ||
			!parse_vec(parse->info[3], &color) ||
			!validation_triangle(&color))
		error("Triangle Parse Error", parse_error, parse);
	if (!add_object(&parse->render->stuff.object,
				create_triangle(point, color),
				&parse->render->stuff.tr_toolbox))
		error("Malloc Triangle Error", parse_error, parse);
}

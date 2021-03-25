/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_object.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deulee <deulee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 13:30:42 by deulee            #+#    #+#             */
/*   Updated: 2021/03/25 20:03:55 by deulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool	validate_sphere(double diameter, t_vec *color)
{
	if (color->x < 0.0f || color->x > 255.0f ||
			color->y < 0.0f || color->y > 255.0f ||
			color->z < 0.0f || color->z > 255.0f ||
			diameter < 0.0f)
		return (false);
	return (true);
}

bool	validation_plane(t_vec *orient, t_vec *color)
{
	if (orient->x < -1.0f || orient->x > 1.0f ||
			orient->y < -1.0f || orient->y > 1.0f ||
			orient->z < -1.0f || orient->z > 1.0f ||
			color->x < 0.0f || color->x > 255.0f ||
			color->y < 0.0f || color->y > 255.0f ||
			color->z < 0.0f || color->z > 255.0f)
		return (false);
	return (true);
}

bool	validation_square(t_vec *orient, t_vec *color, double size)
{
	if (orient->x < -1.0f || orient->x > 1.0f ||
			orient->y < -1.0f || orient->y > 1.0f ||
			orient->z < -1.0f || orient->z > 1.0f ||
			color->x < 0.0f || color->x > 255.0f ||
			color->y < 0.0f || color->y > 255.0f ||
			color->z < 0.0f || color->z > 255.0f ||
			size < 0.0f)
		return (false);
	return (true);
}

bool	validation_cylinder(t_vec *orienti, t_vec *color, double size[2])
{
	if (orient->x < -1.0f || orient->x > 1.0f ||
			orient->y < -1.0f || orient->y > 1.0f ||
			orient->z < -1.0f || orient->z > 1.0f ||
			color->x < 0.0f || color->x > 255.0f ||
			color->y < 0.0f || color->y > 255.0f ||
			color->z < 0.0f || color->z > 255.0f ||
			size[0] < 0.0f || size[1] < 0.0f)
		return (false);
	return (true);
}

bool	validation_triangle(t_vec *color)
{
	if (color->x < 0.0f || color->x > 255.0f ||
			color->y < 0.0f || color->y > 255.0f ||
			color->z < 0.0f || color->z > 255.0f)
		return (false);
	return (true);
}

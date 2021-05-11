/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_world.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deulee <deulee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 13:34:43 by deulee            #+#    #+#             */
/*   Updated: 2021/05/11 17:29:46 by deulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool	validation_resolution(int horiz, int ver)
{
	if (horiz < 0 || ver < 0)
		return (false);
	return (true);
}

bool	validation_amb_light(double ratio, t_color *color)
{
	if (color->x < 0 || color->x > 255 ||
			color->y < 0 || color->y > 255 ||
			color->z < 0 || color->z > 255 ||
			ratio > 1.0f || ratio < 0.0f)
		return (false);
	return (true);
}

bool	validation_cam(t_vec *normal, double fov)
{
	if (normal->x < -1.0f || normal->x > 1.0f ||
			normal->y < -1.0f || normal->y < 1.0f ||
			normal->z < -1.0f || normal->z < 1.0f ||
			fov < 0.0f || fov > 180.0f)
		return (false);
	return (true);
}

bool	validation_light(double ratio, t_color *color)
{
	if (color->x < 0 || color->x > 255 ||
			color->y < 0 || color->y > 255 ||
			color->z < 0 || color->z > 255 ||
			ratio > 1.0f || ratio < 0.0f)
		return (false);
	return (true);
}

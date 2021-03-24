/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_world.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deulee <deulee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 13:34:43 by deulee            #+#    #+#             */
/*   Updated: 2021/03/24 17:23:27 by deulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool	validation_resolution(double horiz, double ver)
{
	if (horiz < 0.0f || y < 0.0f)
		return (false);
	return (true);
}

bool	validation_amb_light(double ratio, t_vec *color)
{
	if (color->x < 0.0f || color->x > 255.0f ||
			color->y < 0.0f || color->y > 255.0f ||
			color->z < 0.0f || color->z > 255.0f ||
			ratio > 1.0f || ratio < 0.0f)
		return (false);
	return (true);
}

bool	validation_cam(t_vec *normal, double fov)
{
	if (normal->x < -1.0f || normal->x > 1.0f ||
			normal->y < -1.0f || normal->y < 1.0f ||
			normal->z < -1.0f || normal->z < 1.0f ||
			degree < 0.0f || degree > 180.0f)
		return (false);
	return (true);
}

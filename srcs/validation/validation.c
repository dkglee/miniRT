/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deulee <deulee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 19:12:54 by deulee            #+#    #+#             */
/*   Updated: 2021/05/12 17:04:22 by deulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool	validation_extraction(char **info, int flag)
{
	if (flag == RS)
		return (extraction_resolution(info));
	else if (flag == AM)
		return (extraction_amb_light(info));
	else if (flag == CM)
		return (extraction_cam(info));
	else if (flag == LI)
		return (extraction_light(info));
	else if (flag == SP)
		return (extraction_sphere(info));
	else if (flag == PL)
		return (extraction_plane(info));
	else if (flag == SQ)
		return (extraction_square(info));
	else if (flag == TR)
		return (extraction_triangle(info));
	else if (flag == CY)
		return (extraction_cylinder(info));
	else if (flag == CU)
		return (extraction_cube(info));
	else if (flag == PY)
		return (extraction_pyramid(info));
	return (false);
}

bool	validation_float(char **info)
{
	bool	flag;
	char	*num;
	int		idx;

	idx = 0;
	flag = true;
	while (info[idx])
	{
		num = info[idx];
		if (*num == '+' || *num == '-')
			num++;
		while (ft_isdigit(*num))
			num++;
		if (*num == '.')
			num++;
		while (ft_isdigit(*num))
			num++;
		if (*num != '\0')
		{
			flag = false;
			break;
		}
		idx++;
	}
	return (flag);
}

bool	validation_range(double num, double min, double max)
{
	if (num < min || num > max)
		return (false);
	return (true);
}

bool	validation_square(t_object *o)
{
	bool	flag;

	flag = validation_range(o->fig.sq.side, 0, INFINITY);
	flag = validation_range(o->specular, 0, INFINITY);
	flag = validation_range(o->reflec, 0, 1);
	flag = validation_range(o->refrac, 0, INFINITY);
	flag = validation_range(o->texture, 0, 5);
	flag = validation_range(o->rgb_color.x, 0, 255);
	flag = validation_range(o->rgb_color.y, 0, 255);
	flag = validation_range(o->rgb_color.z, 0, 255);
	return (flag);
}

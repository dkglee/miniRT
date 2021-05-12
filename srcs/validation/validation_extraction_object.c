/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_extraction_object.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deulee <deulee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 16:55:37 by deulee            #+#    #+#             */
/*   Updated: 2021/05/12 16:56:24 by deulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool	extraction_sphere(char **info)
{
	bool	flag;

	flag = true;
	flag = flag && validate_vector(info[0]);
	flag = flag && validate_double(info[1]);
	flag = flag && validate_int(info[2]);
	flag = flag && validate_double(info[3]);
	flag = flag && validate_double(info[4]);
	flag = flag && validate_int(info[5]);
	flag = flag && validate_double(info[6]);
	flag = flag && validate_color(info[7]);
	return (flag);
}

bool	extraction_plane(char **info)
{
	bool	flag;

	flag = true;
	flag = flag && validate_vector(info[0]);
	flag = flag && validate_vector(info[1]);
	flag = flag && validate_int(info[2]);
	flag = flag && validate_double(info[3]);
	flag = flag && validate_double(info[4]);
	flag = flag && validate_int(info[5]);
	flag = flag && validate_double(info[6]);
	flag = flag && validate_color(info[7]);
	return (flag);
}

bool	extraction_triangle(char **info)
{
	bool	flag;

	flag = true;
	flag = flag && validate_vector(info[0]);
	flag = flag && validate_vector(info[1]);
	flag = flag && validate_vector(info[2]);
	flag = flag && validate_int(info[3]);
	flag = flag && validate_double(info[4]);
	flag = flag && validate_double(info[5]);
	flag = flag && validate_int(info[6]);
	flag = flag && validate_double(info[7]);
	flag = flag && validate_color(info[8]);
	return (flag);
}

bool	extraction_square(char **info)
{
	bool	flag;

	flag = true;
	flag = flag && validate_vector(info[0]);
	flag = flag && validate_vector(info[1]);
	flag = flag && validate_double(info[2]);
	flag = flag && validate_int(info[3]);
	flag = flag && validate_double(info[4]);
	flag = flag && validate_double(info[5]);
	flag = flag && validate_int(info[6]);
	flag = flag && validate_double(info[7]);
	flag = flag && validate_color(info[8]);
	return (flag);
}

bool	extraction_cylinder(char **info)
{
	bool	flag;

	flag = true;
	flag = flag && validate_vector(info[0]);
	flag = flag && validate_vector(info[1]);
	flag = flag && validate_double(info[2]);
	flag = flag && validate_double(info[3]);
	flag = flag && validate_int(info[4]);
	flag = flag && validate_double(info[5]);
	flag = flag && validate_double(info[6]);
	flag = flag && validate_int(info[7]);
	flag = flag && validate_double(info[8]);
	flag = flag && validate_color(info[9]);
	return (flag);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_extraction.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deulee <deulee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 15:19:33 by deulee            #+#    #+#             */
/*   Updated: 2021/05/13 17:49:48 by deulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool	extraction_resolution(char **info)
{
	bool	flag;

	flag = true;
	flag = flag && validate_int(info[0]);
	flag = flag && validate_int(info[0]);
	return (flag);
}

bool	extraction_amb_light(char **info)
{
	bool	flag;

	flag = true;
	flag = flag && validate_double(info[0]);
	flag = flag && validate_color(info[1]);
	return (flag);
}

bool	extraction_cam(char **info)
{
	bool	flag;

	flag = true;
	flag = flag && validate_vector(info[0]);
	flag = flag && validate_vector(info[1]);
	flag = flag && validate_double(info[2]);
	return (flag);
}

bool	extraction_light(char **info)
{
	bool	flag;

	flag = true;
	flag = flag && validate_vector(info[0]);
	flag = flag && validate_double(info[1]);
	flag = flag && validate_color(info[2]);
	return (flag);
}

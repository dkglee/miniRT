/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deulee <deulee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 18:11:05 by deulee            #+#    #+#             */
/*   Updated: 2021/03/26 17:24:50 by deulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec	rotation(t_rot rotation, t_vec u)
{
	t_vec	v;

	v.x = dot_vec(rotation.r1, u);
	v.y = dot_vec(rotation.r2, u);
	v.z = dot_vec(rotation.r3, u);
	return (v);
}

t_vec	rotation_x(t_vec src, double degree)
{
	t_vec	dest;
	double	rad;

	rad = ft_cal_rad(degree);
	dest.x = src.x;
	dest.y = src.y * cos(rad) - src.z * sin(rad);
	dest.z = src.y * sin(rad) + src.z * cos(rad);
	return (dest);
}

t_vec	rotation_y(t_vec src, double degree)
{
	t_vec	dest;
	double	rad;

	rad = ft_cal_rad(degree);
	dest.x = src.x * cos(rad) + src.z * sin(rad);
	dest.y = src.y;
	dest.z = -1.0 * src.x * sin(rad) + src.z * cos(rad);
	return (dest);
}

t_vec	rotation_z(t_vec src, double degree)
{
	t_vec	dest;
	double	rad;

	rad = ft_cal_rad(degree);
	dest.x = src.x * cos(rad) - src.y * sin(rad);
	dest.y = src.x * sin(rad) + src.y * cos(rad);
	dest.z = src.z;
	return (dest);
}

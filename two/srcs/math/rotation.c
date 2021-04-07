/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deulee <deulee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 18:11:05 by deulee            #+#    #+#             */
/*   Updated: 2021/04/06 20:48:15 by deulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	ft_vec_dis(t_vec v, t_vec u)
{
	double	d;

	d = sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y 2) + pow(p2.z - p1.z, 2));
	return (d);
}

t_vec	rotation_x(t_vec v, double degree)
{
	t_vec	row1;
	t_vec	row2;
	t_vec	row3;
	t_vec	rotated;
	double	rad_angle;

	rad_angle = ft_cal_rad(degree);
	row1 = ft_vec_set(1, 0, 0);
	row2 = ft_vec_set(0, cos(rad_angle), -sin(rad_angle));
	row3 = ft_vec_set(0, sin(rad_angle), cos(rad_angle));
	rotated.x = v.x * row1.x + v.y * row1.y + v.z * row1.z;
	rotated.y = v.x * row2.x + v.y * row2.y + v.z * row2.z;
	rotated.z = v.x * row3.x + v.y * row3.y + v.z * row3.z;
	return (rotated);
}

t_vec	rotation_y(t_vec v, double degree)
{
	t_vec	row1;
	t_vec	row2;
	t_vec	row3;
	t_vec	rotated;
	double	rad_angle;

	rad_angle = ft_cal_rad(degree);
	row1 = ft_vec_set(cos(rad_angle), 0, sin(rad_angle));
	row2 = ft_vec_set(0, 1, 0);
	row3 = ft_vec_set(-sin(rad_angle), 0, cos(rad_angle));
	rotated.x = v.x * row1.x + v.y * row1.y + v.z * row1.z;
	rotated.y = v.x * row2.x + v.y * row2.y + v.z * row2.z;
	rotated.z = v.x * row3.x + v.y * row3.y + v.z * row3.z;
	return (rotated);
}

t_vec	rotation_z(t_vec v, double degree)
{
	t_vec	row1;
	t_vec	row2;
	t_vec	row3;
	t_vec	rotated;
	double	rad_angle;

	rad_angle = ft_cal_rad(degree);
	row1 = ft_vec_set(cos(rad_angle), -sin(rad_angle), 0);
	row2 = ft_vec_set(sin(rad_angle), cos(rad_angle), 0);
	row3 = ft_vec_set(0, 0, 1);
	rotated.x = v.x * row1.x + v.y * row1.y + v.z * row1.z;
	rotated.y = v.x * row2.x + v.y * row2.y + v.z * row2.z;
	rotated.z = v.x * row3.x + v.y * row3.y + v.z * row3.z;
	return (rotated);
}

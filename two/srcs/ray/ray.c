/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deulee <deulee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 13:58:09 by deulee            #+#    #+#             */
/*   Updated: 2021/04/07 14:23:57 by deulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec	set_camera(int n, t_tmp tmp, t_mlx mlx)
{
	double	aspect_ratio;
	double	real_fov;
	double	x_offset;
	double	y_offset;
	t_vec	set;

	real_fov = tan(ft_cal_rad(mlx.cam->fov) / 2);
	x_offset = ((n % 3) / 2);
	y_offset = ((n / 3) / 2);
	aspect_ratio = tmp.x_res / tmp.y_res;
	set.x =
		((2 * ((tmp.i + x_offset) / tmp.x_res)) - 1) * aspect_ratio * real_fov;
	set.y = (1 - (2 * ((tmp.j + y_offset) / tmp.y_res))) * real_fov;
	set.x *= -1;
	set.z = 1;
	set = ft_vec_unit(set);
	return (set);
}

t_vec	ft_look_at(t_vec dir, t_vec cam)
{
	t_vec	x_axis;
	t_vec	y_axis;
	t_vec	z_axis;
	t_vec	rdup;
	t_vec	rotation;

	rdup = ft_vec_set(0, 1, 0);
	z_axis = cam;
	if (cam.y == 1 || cam.y == -1)
		x_axis = cam.y == 1 ? ft_vec_set(1, 0, 0) : ft_vec_set(-1, 0, 0);
	else
		x_axis = ft_vec_cross(rdup, z_axis);
	y_axis = ft_vec_cross(z_axis, x_axis);
	rotation.x = dir.x * x_axis.x + dir.y * y_axis.x + dir.z * z_axis.x;
	rotation.y = dir.x * x_axis.y + dir.y * y_axis.y + dir.z * z_axis.y;
	rotation.z = dir.x * x_axis.z + dir.y * y_axis.z + dir.z * z_axis.z;
	return (rotation);
}

int		calc_ray(int n, t_tmp tmp, t_render *render)
{
	int		color;
	t_vec	dir;

	dir = set_camera(n, tmp, render->mlx);
	dir = ft_look_at(dir, render->mlx.cam->nv);
	color = ray_trace(w->mlx.cam->o, dir, render, REFLECTION_LIMIT);
	return (color);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deulee <deulee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 17:28:43 by deulee            #+#    #+#             */
/*   Updated: 2021/03/24 18:20:42 by deulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_cam	*add_cam(t_cam **head, t_vec origin, t_vec orient, double fov)
{
	t_cam	*cam;

	cam = (t_cam *)malloc(sizeof(t_cam));
	if (cam == NULL)
		return (NULL);
	cam->origin = origin;
	cam->fov = fov;
	orient = ft_vec_unit(orient);
	cam->tilt = asin(orient.z);
	cam->pan = acos(orient.y / cos(cam->tilt));
	cam->viewport_ratio = DEFAULT_VIEWPORT_RATIO;
	refresh_cam(cam);
	cam->next = *head;
	*head = cam;
	return (cam);
}

void	refresh_cam(t_cam *cam)
{
	t_rot	rot;

	rot.r1.x = cos(cam->pan);
	rot.r1.y = -sin(cam->pan) * sin(cam->tilt);
	rot.r1.z = -sin(cam->pan) * cos(cam->tilt);
	rot.r2.x = sin(cam->pan);
	rot.r2.y = cos(cam->pan) * sin(cam->tilt);
	rot.r2.z = cos(cam->pan) * cos(cam->tilt);
	rot.r3.x = 0;
	rot.r3.y = -cos(cam->tilt);
	rot.r3.z = sin(cam->tilt);
	cam->x_axis = ft_vec_unit(rotation(rot, ft_vec_set(1, 0, 0)));
	cam->y_axis = ft_vec_unit(rotation(rot, ft_vec_set(0, 1, 0)));
	cam->z_axis = ft_vec_unit(rotation(rot, ft_vec_set(0, 0, 1)));
	cam->viewport_height = 2 * FOCAL_LENGTH * tan(ft_cal_rad(cam->fov));
	cam->viewport_width = cam->viewport_ratio * cam->viewport_height;
}

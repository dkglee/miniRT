/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deulee <deulee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 17:28:43 by deulee            #+#    #+#             */
/*   Updated: 2021/03/24 17:48:58 by deulee           ###   ########.fr       */
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
	
}

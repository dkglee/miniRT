/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deulee <deulee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 17:13:40 by deulee            #+#    #+#             */
/*   Updated: 2021/03/24 17:24:58 by deulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WORLD_H
# define WROLD_H

typedef	struct		s_cam
{
	t_vec			origin;
	t_vec			x_axis;
	t_vec			y_axis;
	t_vec			z_axis;
	double			fov;
	double			viewport_width;
	double			viewport_height;
	double			viewport_ratio;
	double			tilt;
	double			pan;
	struct s_cam	*next;
}					t_cam;

#endif

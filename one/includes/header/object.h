/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deulee <deulee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 18:27:54 by deulee            #+#    #+#             */
/*   Updated: 2021/03/25 20:05:25 by deulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H

typedef	struct		s_object
{
	void			*object;
	t_toolbox		*toolbox;
	int				stretch_mode;
	struct s_object	*next;
}					t_object;

typedef	struct		s_sphere
{
	t_vec			origin;
	t_vec			color;
	double			radius;
}					t_sphere;

typedef	struct		s_plane
{
	t_vec			origin;
	t_vec			orient;
	t_vec			color;
	double			offset;
}					t_plane;

typedef	struct		s_square
{
	t_vec			origin;
	t_vec			orient;
	t_vec			color;
	double			size;
}

typedef	struct		s_cylinder
{
	t_vec			top;
	t_vec			origin;
	t_vec			orient;
	t_vec			color;
	double			radius;
	double			height;
	t_circle		*top_c;
	t_circle		*bot_c;
}					t_cylinder;

typedef	struct		s_circle
{
	t_vec			origin;
	t_vec			orient;
	t_vec			color;
	double			radius;
	double			offset;
}					t_circle;

typedef	struct		s_triangle
{
	t_vec			point[3];
	t_vec			orient;
	t_vec			origin;
	t_vec			color;
	double			size;
	double			offset;
}					t_sqaure;

#endif

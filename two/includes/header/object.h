/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deulee <deulee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 14:40:44 by deulee            #+#    #+#             */
/*   Updated: 2021/04/05 14:48:08 by deulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H

typedef	struct		s_square
{
	t_vec			half_size;
	t_vec			floor;
	t_vec			center;
}					t_sq;

typedef struct		s_cube
{
	t_obj			sq;
	t_vec			center;
	t_vec			normal[6];
}					t_cube;

typedef	struct		s_pyramid
{
	t_obj			sq;
	t_obj			tr;
	t_vec			center;
	t_vec			normal[5];
	t_vec			corner[4];
}					t_pyramid;

typedef	struct		s_sphere
{
	t_vec			center;
	double			radius;
	int				inside;
}					t_sphere;

typedef	struct		s_plane
{
	t_vec			p;
}					t_plane;

typedef	struct		s_square
{
	t_vec			center;
	double			side;
}					t_square;

typedef	struct		s_cylinder
{
	t_vec			center;
	t_vec			nv;
	double			radius;
	double			height;
	double			dist1;
	double			dist2;
}					t_cylinder;

typedef	struct		s_triangle
{
	t_vec			p1;
	t_vec			p2;
	t_vec			p3;
}					t_triangle;

typedef	struct		s_figures
{
	t_sphere		sp;
	t_plane			pl;
	t_square		sq;
	t_cylinder		cy;
	t_triangle		tr;
}					t_figures;

#endif

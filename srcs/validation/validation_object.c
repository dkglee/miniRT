/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_object.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deulee <deulee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 23:20:04 by deulee            #+#    #+#             */
/*   Updated: 2021/04/06 16:41:19 by deulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool	validation_sphere(t_object *o)
{
	bool	flag;

	flag = validation_range(o->fig.sp.radius, 0, INFINITY);
	flag = validation_range(o->specular, 0, INFINITY);
	flag = validation_range(o->reflec, 0, 1);
	flag = validation_range(o->refrac, 0, INFINITY);
	flag = validation_range(o->texture, 0, 5);
	flag = validation_range(o->rgb_color.x, 0, 255);
	flag = validation_range(o->rgb_color.y, 0, 255);
	flag = validation_range(o->rgb_color.z, 0, 255);
	return (flag);
}

bool	validation_plane(t_object *o)
{
	bool	flag;

	flag = validation_range(o->specular, 0, INFINITY);
	flag = validation_range(o->reflec, 0, 1);
	flag = validation_range(o->refrac, 0, INFINITY);
	flag = validation_range(o->texture, 0, 5);
	flag = validation_range(o->rgb_color.x, 0, 255);
	flag = validation_range(o->rgb_color.y, 0, 255);
	flag = validation_range(o->rgb_color.z, 0, 255);
	return (flag);
}

bool	validation_sqaure(t_object *o)
{
	bool	flag;

	flag = validation_range(o->fig.sq.side, 0, INFINITY);
	flag = validation_range(o->specular, 0, INFINITY);
	flag = validation_range(o->reflec, 0, 1);
	flag = validation_range(o->refrac, 0, INFINITY);
	flag = validation_range(o->texture, 0, 5);
	flag = validation_range(o->rgb_color.x, 0, 255);
	flag = validation_range(o->rgb_color.y, 0, 255);
	flag = validation_range(o->rgb_color.z, 0, 255);
	return (flag);
}

bool	validation_triangle(t_object *o)
{
	bool	flag;

	flag = validation_range(o->specular, 0, INFINITY);
	flag = validation_range(o->reflec, 0, 1);
	flag = validation_range(o->refrac, 0, INFINITY);
	flag = validation_range(o->texture, 0, 5);
	flag = validation_range(o->rgb_color.x, 0, 255);
	flag = validation_range(o->rgb_color.y, 0, 255);
	flag = validation_range(o->rgb_color.z, 0, 255);
	return (flag);
}

bool	validation_cylinder(t_object *o)
{
	bool	flag;

	flag = validation_range(o->fig.cy.radius, 0, INFINITY);
	flag = validation_range(o->fig.cy.height, 0, INFINITY);
	flag = validation_range(o->specular, 0, INFINITY);
	flag = validation_range(o->reflec, 0, 1);
	flag = validation_range(o->refrac, 0, INFINITY);
	flag = validation_range(o->texture, 0, 5);
	flag = validation_range(o->rgb_color.x, 0, 255);
	flag = validation_range(o->rgb_color.y, 0, 255);
	flag = validation_range(o->rgb_color.z, 0, 255);
	return (flag);
}

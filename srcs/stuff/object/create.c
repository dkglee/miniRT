/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deulee <deulee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 18:33:35 by deulee            #+#    #+#             */
/*   Updated: 2021/03/25 20:18:48 by deulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_sphere	*create_sphere(t_vec origin, double radius, t_vec color)
{
	t_sphere	*new;

	if (NULL == (new = (t_sphere *)malloc(sizeof(t_sphere))))
		return (NULL);
	new->origin = origin;
	new->radius = radius;
	new->color = ft_vec_product(color, 1 / 255.0f);
	return (new);
}

t_plane		*create_plane(t_vec origin, t_vec orient, t_vec color)
{
	t_plane		*new;

	if (NULL == (new = (t_plane *)malloc(sizeof(t_plane))))
		return (NULL);
	new->origin = origin;
	new->orient = ft_vec_unit(orient);
	new->color = ft_vec_product(color, 1 / 255.0f);
	new->offset = dot_vec(new->center, new->orient);
	return (new);
}

t_square	*create_square(t_vec origin, t_vec orient, t_vec color, double size)
{
	t_square	*new;

	if (NULL == (new = (t_square *)malloc(sizeof(t_square))))
		return (NULL);
	new->origin = origin;
	new->orient = ft_vec_unit(orient);
	new->color = ft_vec_product(color, 1 / 255.0f);
	new->size = size;
	refresh_square(new);
	return (new);
}

t_cylinder	*create_cylinder(t_vec origin, t_vec orient, t_vec color, double size[2])
{
	t_cylinder	*new;

	if (NULL == (new = (t_cylinder *)malloc(sizeof(t_cylinder))))
		return (NULL);
	new->top_c = create_circle(origin, orient, color, size[0]);
	new->bot_c = create_circle(origin, orient, color, size[0]);
	if (new->top_c == NULL || new->bot_c == NULL)
	{
		free(new->top_c);
		free(new->bot_c);
		free(new);
		return (NULL);
	}
	new->origin = origin;
	new->orient = ft_vec_unit(orient);
	new->color = ft_vec_product(color, 1 / 255.0f);
	new->radius = size[0] / 2.0;
	new->height = size[1];
	refresh_cylinder(new);
	return (new);
}

t_triangle	*create_triange(t_vec point[3], t_vec color)
{
	t_triangle	*new;

	if (NULL == (new = (t_triangle *)malloc(sizeof(t_triangle))))
		return (NULL);
	new->point[0] = point[0];
	new->point[1] = point[1];
	new->point[2] = point[2];
	new->origin = ft_vec_add(point[0], point[1]);
	new->origin = ft_vec_add(new->origin, point[2]);
	new->origin = ft_vec_product(new->origin, 1 / 3.0);
	new->orient = ft_vec_cross(ft_vec_sub(point[1], point[0]),
			ft_vec_sub(point[2], point[1]));
	new->orient = ft_vec_unit(new->orient);
	new->color = ft_vec_product(color, 1 / 255.0f);
	new->offset = dot_vec(new->orient, new->point[0]);
	return (new);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deulee <deulee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 19:51:59 by deulee            #+#    #+#             */
/*   Updated: 2021/03/25 19:55:40 by deulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_circle	*create_circle(t_vec origin, t_vec orient, t_vec color, double radius)
{
	t_circle	*new;

	if (NULL == (new = (t_circle *)malloc(sizeof(t_circle))))
		return (NULL);
	new->origin = origin;
	new->orient = ft_vec_orient(orient);
	new->color = ft_vec_product(color, 1 / 255.0f);
	new->radius = size;
	new->offset = ft_vec_dot(new->origin, new->orient);
	return (new);
}

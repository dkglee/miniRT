/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deulee <deulee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 17:31:50 by deulee            #+#    #+#             */
/*   Updated: 2021/05/10 17:38:27 by deulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool	validation_bonus(t_object *o)
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

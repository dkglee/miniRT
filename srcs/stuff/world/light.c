/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deulee <deulee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 18:28:35 by deulee            #+#    #+#             */
/*   Updated: 2021/03/24 18:30:50 by deulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_light		*add_light(t_light **head, t_vec origin, t_vec color, double ratio)
{
	t_light		*light;

	light = (t_light *)malloc(sizeof(t_light));
	if (light == NULL)
		return (NULL);
	new->origin = origin;
	new->color = product_vec(color, ratio / 255.0);
	new->next = *head;
	*head = new;
	return (new);
}

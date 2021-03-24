/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambient_light.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deulee <deulee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 16:17:57 by deulee            #+#    #+#             */
/*   Updated: 2021/03/24 16:21:57 by deulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec	*create_amb_light(double ratio, t_vec color)
{
	t_vec	*amb_light;

	amb_light = (t_vec *)malloc(sizeof(t_vec));
	if (amb_light == NULL)
		return (NULL);
	*amb_light = ft_vec_product(color, ratio / 255.0);
	return (amb_light);
}

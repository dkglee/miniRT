/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deulee <deulee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 17:12:29 by deulee            #+#    #+#             */
/*   Updated: 2021/04/09 17:18:04 by deulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	get_norm(t_vec p, t_vec d, t_vec *normal, t_object *list)
{
	if (list->flag != SP)
	{
		if (ft_vec_cos(d, list->normal) > 0)
			*normal = ft_vec_product(-1, list->normal);
		else
			*normal = list->normal;
	}
	else
	{
		*normal = ft_vec_unit(ft_vec_sub(p, list->fig.sp.center));
		if (ft_vec_cos(d , *normal) > 0)
		{
			*normal = ft_vec_sub(-1, *normal);
			list->fig.sp.inside = 1;
		}
		else
			list->fig.sp.inside = 0;
	}
}

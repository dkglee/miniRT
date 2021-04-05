/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_object.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deulee <deulee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 18:19:50 by deulee            #+#    #+#             */
/*   Updated: 2021/03/26 16:52:26 by deulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	move_sp(void *ptr, t_vec src)
{
	t_sphere	*new;

	new = (t_sphere *)ptr;
	new->origin = ft_vec_add(new->origin, src);
}

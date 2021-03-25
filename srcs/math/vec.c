/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deulee <deulee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 12:46:26 by deulee            #+#    #+#             */
/*   Updated: 2021/03/25 17:37:59 by deulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec	ft_vec_set(double x, double y, double z)
{
	t_vec	new;

	new.x = x;
	new.y = y;
	new.z = z;
	return (new);
}

t_vec	ft_vec_unit(t_vec u)
{
	double	vec_size;

	vec_size = sqrt(ft_vec_dot(u, u));
	u.x /= vec_size;
	u.y /= vec_size;
	u.z /= vec_size;
	return (u);
}

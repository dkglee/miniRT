/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deulee <deulee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 12:46:26 by deulee            #+#    #+#             */
/*   Updated: 2021/03/21 17:07:22 by deulee           ###   ########.fr       */
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
	double	vec_len;

	vec_len = sqrt(ft_vec_dot(u, u));
	u.x /= vec_len;
	u.y /= vec_len;
	u.z /= vec_len;
	return (u);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deulee <deulee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 17:07:53 by deulee            #+#    #+#             */
/*   Updated: 2021/05/10 18:55:29 by deulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec	ft_vec_add(t_vec u, t_vec v)
{
	t_vec	result;

	result.x = u.x + v.x;
	result.y = u.y + v.y;
	result.z = u.z + v.z;
	return (result);
}

t_vec	ft_vec_sub(t_vec u, t_vec v)
{
	t_vec	result;

	result.x = u.x - v.x;
	result.y = u.y - v.y;
	result.z = u.z - v.z;
	return (result);
}

t_vec	ft_vec_cross(t_vec u, t_vec v)
{
	t_vec	result;

	result.x = u.y * v.z - u.z * v.y;
	result.y = u.z * v.x - u.x * v.z;
	result.z = u.x * v.y - u.y * v.x;
	return (result);
}

t_vec	ft_vec_product(double scalar, t_vec u)
{
	u.x *= scalar;
	u.y *= scalar;
	u.z *= scalar;
	return (u);
}

double	ft_vec_dot(t_vec u, t_vec v)
{
	double dot;

	dot = u.x * v.x + u.y * v.y + u.z * v.z;
	return (dot);
}

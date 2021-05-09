/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deulee <deulee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 12:46:26 by deulee            #+#    #+#             */
/*   Updated: 2021/05/09 23:31:38 by deulee           ###   ########.fr       */
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

double	ft_vec_size(t_vec v)
{
	return (sqrt(ft_vec_dot(v, v)));
}

double	ft_vec_cos(t_vec v, t_vec u)
{
	return (ft_vec_dot(v, u) / (ft_vec_size(v) * ft_vec_size(u)));
}

double	ft_vec_sin(t_vec v, t_vec u)
{
	return (sqrt(1 - pow(ft_vec_cos(v, u), 2)));
}

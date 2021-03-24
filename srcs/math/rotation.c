/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deulee <deulee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 18:11:05 by deulee            #+#    #+#             */
/*   Updated: 2021/03/24 18:14:59 by deulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec	rotation(t_rot rotation, t_vec u)
{
	t_vec	v;

	v.x = dot_vec(rotation.r1, u);
	v.y = dot_vec(rotation.r2, u);
	v.z = dot_vec(rotation.r3, u);
	return (v);
}

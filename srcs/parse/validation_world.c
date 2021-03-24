/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_world.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deulee <deulee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 13:34:43 by deulee            #+#    #+#             */
/*   Updated: 2021/03/24 15:02:25 by deulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool	validation_resolution(double horiz, double ver)
{
	if (horiz < 0.0f || y < 0.0f)
		return (false);
	return (true);
}

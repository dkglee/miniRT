/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deulee <deulee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 16:42:17 by deulee            #+#    #+#             */
/*   Updated: 2021/03/26 16:35:36 by deulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "minirt.h"

int		main(int argc, char **argv)
{
	t_render	render;

	init_render(&render);
	parsing(&render, argc, argv);
	if (!validation_parse(&render))
		error("Create World Error", clear_render, &render);
	start_render(&render);
	return (0);
}

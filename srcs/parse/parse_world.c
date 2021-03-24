/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_world.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deulee <deulee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 13:34:11 by deulee            #+#    #+#             */
/*   Updated: 2021/03/24 15:07:42 by deulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	*parse_resolution(t_parse *parse)
{
	double	horiz;
	double	ver;
	int		max_horiz;
	int		max_ver;

	horiz = 0.0f;
	ver = 0.0f;
	if (count_info(parse->info) != 3)
		error("Resolution Information Number Error", parse_error, parse);
	parse->info++;
	if (!validation_extraction(parse->info))
		error("Resolution Information Error", parse_error, parse);
	if (!parse_double(parse->info[0], &horiz) ||
			!parse_double(parse->info[1], &ver) ||
			!validation_resolution(horiz, ver))
		error("Resolution Parse Error", parse_error, parse);
	mlx_get_screen_size(NULL, &max_horiz, &max_ver);
	if (horiz > (double)max_horiz)
		horiz = max_horiz;
	if (ver > (double)max_ver)
		ver = max_ver;
	parse->render->trace.width = horiz;
	parse->render->trace.height = ver;
}



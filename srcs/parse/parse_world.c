/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_world.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deulee <deulee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 13:34:11 by deulee            #+#    #+#             */
/*   Updated: 2021/03/24 17:42:01 by deulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	parse_resolution(t_parse *parse)
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

void	parse_amb_light(t_parse *parse)
{
	double	ratio;
	t_vec	color;

	color = ft_vec_set(0, 0, 0);
	if (count_info(parse->info++) != 3)
		error("Ambient Light Information Number Error", parse_error, parse);
	if (!validation_extraction(parse->info))
		error("Ambient Light Information Error", parse_error, parse);
	if (!parse_double(parse->info[0], &ratio) ||
			!parse_vec(parse->info[1], &color) ||
			!validation_amb_light(ratio, &color))
		error("Ambient Light Parse Error", parse_error, parse);
	parse->render->stuff.amb_light = create_amb_light(ratio, color);
	if (parse->render->stuff.amb_light = NULL)
		error("Malloc Error", parse_error, parse);
}

void	parse_cam(t_parse *parse)
{
	t_vec	origin;
	t_vec	orient;
	double	fov;
	
	if (count_info(parse->info++) != 4)
		error("Cam Information Number Error", parse_error, parse);
	if (!validation_extraction(parse->info))
		error("Cam Information Error", parse_error, parse);
	if (!parse_vec(info[0], &origin) ||
			!parse_vec(info[1], &orient) ||
			!parse_double(info[2], &fov) ||
			!validate_cam(&normal, degree))
		error("Cam Parse Error", parse_error, parse);
	if (add_cam(&parse->render->stuff.cam, origin, orient, fov))
		error("Malloc Error", parse_error, parse);
}

void	parse_light(t_parse *parse)
{
	
}

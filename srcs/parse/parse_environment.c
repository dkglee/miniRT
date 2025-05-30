/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_environment.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deulee <deulee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 17:52:13 by deulee            #+#    #+#             */
/*   Updated: 2021/05/13 18:17:53 by deulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	parse_resolution(t_parse *parse)
{
	if (parse->trace->res_idx > 0)
		error("Resolution can be declared only once time", parse_error, parse);
	else
		parse->trace->res_idx = 1;
	if (count_info(parse->info) != 3)
		error("Resolution Information Number Error", parse_error, parse);
	if (!validation_extraction(parse->info + 1, RS))
		error("Resolution Information Error", parse_error, parse);
	if (!parse_int(parse->info[1], &parse->trace->x_res) ||
			!parse_int(parse->info[2], &parse->trace->y_res) ||
			!validation_resolution(parse->trace->x_res, parse->trace->y_res))
		error("Resolution Parse Error", parse_error, parse);
}

void	parse_amb_light(t_parse *parse)
{
	t_color	color;
	bool	flag;

	flag = true;
	if (parse->trace->amb_idx > 0)
		error("Ambient Light can be declared once time", parse_error, parse);
	else
		parse->trace->amb_idx = 1;
	if (count_info(parse->info) != 3)
		error("Ambient Light Information Number Error", parse_error, parse);
	if (!validation_extraction(parse->info + 1, AM))
		error("Ambient Light Information Error", parse_error, parse);
	flag = flag && parse_double(parse->info[1], &parse->trace->amb_light);
	flag = flag && parse_vec_color(parse->info[2], &color);
	flag = flag && validation_amb_light(parse->trace->amb_light, &color);
	if (flag == false)
		error("Ambient Light Parse Error", parse_error, parse);
	parse->trace->amb_color = get_color(color);
}

void	parse_cam(t_parse *parse)
{
	t_cam	*new;
	t_cam	*begin;
	bool	flag;

	flag = true;
	begin = parse->mlx->cam; 
	new = (t_cam *)malloc(sizeof(t_cam));
	if (new == NULL)
		error("Cam Malloc Error", NULL, NULL);
	new->next = NULL;
	ft_addcam_back(&parse->mlx->cam, new);
	if (count_info(parse->info) != 4)
		error("Cam Information Number Error", parse_error, parse);
	if (!validation_extraction(parse->info + 1, CM))
		error("Cam Information Error", parse_error, parse);
	flag = flag && parse_vec(parse->info[1], &new->o);
	flag = flag && parse_vec(parse->info[2], &new->nv);
	flag = flag && parse_double(parse->info[3], &new->fov);
	flag = flag && validation_cam(&new->nv, new->fov);
	if (flag == false)
		error("Cam Parse Error", parse_error, parse);
	new->nv = ft_vec_unit(new->nv);
	parse->mlx->cam = begin ? begin : new;
}

void	parse_light(t_parse *parse)
{
	t_light	*new;
	t_light *begin;
	t_color	color;
	bool	flag;

	flag = true;
	begin = parse->trace->light;
	new = (t_light *)malloc(sizeof(t_light));
	if (new == NULL)
		error("Light Malloc Error", NULL, NULL);
	new->next = NULL;
	ft_addlight_back(&parse->trace->light, new);
	if (count_info(parse->info) != 4)
		error("Light Information Number Error", parse_error, parse);
	if (!validation_extraction(parse->info + 1, LI))
		error("Light Information Error", parse_error, parse);
	flag = flag && parse_vec(parse->info[1], &new->o);
	flag = flag && parse_double(parse->info[2], &new->br);
	flag = flag && parse_vec_color(parse->info[3], &color);
	flag = flag && validation_light(new->br, &color);
	if (flag == false)
		error("Light Parse Error", parse_error, parse);
	new->color = get_color(color);
	parse->trace->light = begin ? begin : new;
}

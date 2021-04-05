/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_environmet.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deulee <deulee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 16:21:50 by deulee            #+#    #+#             */
/*   Updated: 2021/04/05 22:13:17 by deulee           ###   ########.fr       */
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
	parse->info++;
	if (!validation_extraction(parse->info))
		error("Resolution Information Error", parse_error, parse);
	if (!parse_double(parse->info[0], &parse->trace->x_res) ||
			!parse_double(parse->info[1], &parse->trace->y_res) ||
			!validation_resolution(parse->trace->x_res, parse->trace->y_res))
		error("Resolution Parse Error", parse_error, parse);
}

void	parse_amb_light(t_parse *parse)
{
	t_vec	color;

	if (parse->trace->amb_idx > 0)
		error("Ambient Light can be declared once time", parse_error, parse);
	else
		parse->trace->amb_idx = 1;
	if (count_info(parse->info++) != 3)
		error("Ambient Light Information Number Error", parse_error, parse);
	if (!validation_extraction(parse->info))
		error("Ambient Light Information Error", parse_error, parse);
	if (!parse_double(parse->info[0], &parse->trace->amb_light) ||
			!parse_vec(parse->info[1], &color) ||
			!validation_amb_light(parse->trace->amb_light, &color))
		error("Ambient Light Parse Error", parse_error, parse);
	parse->trace->amb_color = get_color(color);
}

void	parse_cam(t_parse *parse)
{
	t_cam	*new;
	t_cam	*begin;

	begin = parse->mlx->cam; 
	new = (t_cam *)malloc(sizeof(t_cam));
	if (new == NULL)
		error("Cam Malloc Error", parse_error, parse);
	new->next = NULL;
	ft_lstadd_back(&parse->mlx->cam, new);
	new->idx = ft_lstsize(parse->mlx->cam);
	parse->trace->cam_nb = new->idx;
	if (count_info(parse->info++) != 4)
		error("Cam Information Number Error", parse_error, parse);
	if (!validatoin_extraction(parse->info))
		error("Cam Information Error", parse_error, parse);
	if (!parse_vec(parse->info[0], &new->o) ||
			!parse_vec(parse->info[1], &new->nv) ||
			!parse_double(parse->info[2], &new->fov) ||
			!validation(&new->nv, new->fov))
		error("Cam Parse Error", parse_error, parse);
	new->nv = ft_vec_unit(new->nv);
	parse->mlx->cam = begin ? begin : new;
}

void	parse_light(t_parse *parse)
{
	t_light	*new;
	t_light *begin;
	t_vec	color;

	begin = parse->trace->light;
	new = (t_light *)malloc(sizeof(t_light));
	if (new == NULL)
		error("Light Malloc Error", parse_error, parse);
	new->next = NULL;
	ft_lstadd_back(&parse->trace->light, new);
	if (count_info(parse->info++) != 4)
		error("Light Information Number Error", parse_error, parse);
	if (!validation_extraction(parse->info))
		error("Light Information Error", parse_error, parse);
	if (!parse_vec(parse->info[0], &new->o) ||
			!parse_double(parse->info[1], &new->br) ||
			!parse_color(parse->info[2], &color) ||
			!validation_light(new_br, &color))
		error("Light Parse Error", parse_error, parse);
	new->color = get_color(color);
	parse->trace->light = begin ? begin : new;
}

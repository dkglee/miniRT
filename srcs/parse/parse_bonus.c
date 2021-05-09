/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deulee <deulee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 16:29:00 by deulee            #+#    #+#             */
/*   Updated: 2021/05/09 22:32:08 by deulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	parse_cube(t_parse *parse, t_object *list)
{
	t_object	*new;

	new = ft_new_object(list);
	if (count_info(parse->info++) != 9)
		error("Cube Information Number Error", parse_error, parse);
	if (!validation_extraction(parse->info))
		error("Cube Information Error", parse_error, error);
	new->flag = CU;
	if (!parse_vec(parse->info[0], &new->fig.sq.center) ||
			!parse_double(parse->info[1], &new->fig.sq.side) ||
			!parse_int(parse->info[2], &new->specular) ||
			!parse_double(parse->info[3], &new->reflec) ||
			!parse_double(parse->info[4], &new->refrac) ||
			!parse_int(parse->info[5], &new->texture) ||
			!parse_double(parse->info[6], &new->wavelength) ||
			!parse_vec(parse->info[7], &new->rgb_color) ||
			!validation_bonus(new))
		error("Cube Parse Error", parse_error, error);
	new->color = get_color(new->rgb_color);
}

void	parse_pyramid(t_parse *parse, t_object *list)
{
	t_object	*new;

	new = ft_new_object(list);
	if (count_info(parse->info++) != 9)
		error("Pyramid Information Number Error", parse_error, parse);
	if (!validation_extraction(parse->info))
		error("Pyramid Information Error", parse_error, error);
	new->flag = PY;
	if (!parse_vec(parse->info[0], &new->fig.sq.center) ||
			!parse_double(parse->info[1], &new->fig.sq.side) ||
			!parse_int(parse->info[2], &new->specular) ||
			!parse_double(parse->info[3], &new->reflec) ||
			!parse_double(parse->info[4], &new->refrac) ||
			!parse_int(parse->info[5], &new->texture) ||
			!parse_double(parse->info[6], &new->wavelength) ||
			!parse_vec(parse->info[7], &new->rgb_color) ||
			!validation_bonus(new))
		error("Pyramid Parse Error", parse_error, error);
	new->color = get_color(new->rgb_color);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deulee <deulee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 16:29:00 by deulee            #+#    #+#             */
/*   Updated: 2021/05/16 16:29:17 by deulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	parse_cube(t_parse *parse, t_object **list)
{
	t_object	*new;

	new = ft_new_object(list);
	if (count_info(parse->info) != 9)
		error("Cube Information Number Error", parse_error, parse);
	if (!validation_extraction(parse->info + 1, CU))
		error("Cube Information Error", parse_error, parse);
	new->flag = CU;
	if (!parse_vec(parse->info[1], &new->fig.sq.center) ||
			!parse_double(parse->info[2], &new->fig.sq.side) ||
			!parse_int(parse->info[3], &new->specular) ||
			!parse_double(parse->info[4], &new->reflec) ||
			!parse_double(parse->info[5], &new->refrac) ||
			!parse_int(parse->info[6], &new->texture) ||
			!parse_double(parse->info[7], &new->wavelength) ||
			!parse_vec_color(parse->info[8], &new->rgb_color) ||
			!validation_bonus(new))
		error("Cube Parse Error", parse_error, parse);
	new->color = get_color(new->rgb_color);
}

void	parse_pyramid(t_parse *parse, t_object **list)
{
	t_object	*new;

	new = ft_new_object(list);
	if (count_info(parse->info) != 9)
		error("Pyramid Information Number Error", parse_error, parse);
	if (!validation_extraction(parse->info + 1, PY))
		error("Pyramid Information Error", parse_error, parse);
	new->flag = PY;
	if (!parse_vec(parse->info[1], &new->fig.sq.center) ||
			!parse_double(parse->info[2], &new->fig.sq.side) ||
			!parse_int(parse->info[3], &new->specular) ||
			!parse_double(parse->info[4], &new->reflec) ||
			!parse_double(parse->info[5], &new->refrac) ||
			!parse_int(parse->info[6], &new->texture) ||
			!parse_double(parse->info[7], &new->wavelength) ||
			!parse_vec_color(parse->info[8], &new->rgb_color) ||
			!validation_bonus(new))
		error("Pyramid Parse Error", parse_error, parse);
	new->color = get_color(new->rgb_color);
}

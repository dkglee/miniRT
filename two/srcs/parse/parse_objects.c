/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_objects.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deulee <deulee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 21:51:33 by deulee            #+#    #+#             */
/*   Updated: 2021/04/05 23:16:18 by deulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	parse_sphere(t_parse *parse)
{
	t_object	*new;

	new = (t_object *)malloc(sizeof(t_object));
	if (new == NULL)
		error("Sphere Malloc Error", parse_error, parse);
	new->next = NULL;
	ft_lstadd_back(&parse->object, new);
	if (count_info(parse->info++) != 9)
		error("Sphere Information Number Error", parse_error, parse);
	if (!validation_extraction(parse->info))
		error("Sphere Information Error", parse_error, error);
	new->flag = SP;
	if (!parse_vec(parse->info[0], &new->fig.sp.center) ||
			!parse_double(parse->info[1], &new->fig.sp.radius) ||
			!parse_int(parse->info[2], &new->specular) ||
			!parse_double(parse->info[3], &new->reflec) ||
			!parse_double(parse->info[4], &new->refrac) ||
			!parse_int(parse->info[5], &new->texture) ||
			!parse_double(parse->info[6], &new->wavelength) ||
			!parse_vec(parse->info[7], &new->rgb_color) ||
			!validation_sphere(new))
		error("Sphere Parse Error", parse_error, error);
	new->color = get_color(new->rgb_color);
}

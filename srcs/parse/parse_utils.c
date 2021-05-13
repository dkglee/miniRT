/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deulee <deulee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 13:41:38 by deulee            #+#    #+#             */
/*   Updated: 2021/05/13 19:10:51 by deulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		count_info(char **info)
{
	int		idx;

	if (info == NULL)
		return (-1);
	idx = 0;
	while (info[idx])
		idx++;
	return (idx);
}

bool	parse_double(char *info, double *value)
{
	bool	flag;

	flag = true;
	*value = ft_atof(info);
	return (flag);
}

bool	parse_int(char *info, int *value)
{
	bool	flag;

	flag = true;
	*value = ft_atoi(info);
	return (flag);
}

int		get_color(t_color color)
{
	int		r;
	int		g;
	int		b;

	r = 0;
	g = 0;
	b = 0;
	r |= color.x;
	r <<= 16;
	g |= color.y;
	g <<= 8;
	b |= color.z;
	return (r | g | b);
}

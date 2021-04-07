/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deulee <deulee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 11:11:17 by deulee            #+#    #+#             */
/*   Updated: 2021/04/07 11:23:47 by deulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		calc_avg_simple_color(int a, int b)
{
	int		rgb[3];
	int		mask;

	mask = 255;
	ft_memset(rgb, 0, 3 * sizeof(int));
	rgb[0] += (a & (mask << 16)) >> 16;
	rgb[0] += (b & (mask << 16)) >> 16;
	rgb[1] += (a & (mask << 8)) >> 8;
	rgb[1] += (b & (mask << 8)) >> 8;
	rgb[2] += (a & mask);
	rgb[2] += (b & mask);
	rgb[0] /= 2;
	rgb[1] /= 2;
	rgb[2] /= 2;
	return ((rgb[0] << 16) | (rgb[1] << 8) | rgb[2]);
}

int		calc_avg_ssaa_color(int *color)
{
	int		ssaa_color[3];
	int		mask;
	int		i;

	ft_memset(ssaa_color, 0, 3 * sizeof(int));
	mask = 255;
	i = 0;
	while (i < 4)
	{
		ssaa_color[0] += (color[i] & (mask << 16)) >> 16;
		ssaa_color[1] += (color[i] & (mask << 8)) >> 8;
		ssaa_color[2] += color[i] & mask;
		i++;
	}
	i = 0;
	while (i < 3)
		ssaa_color[i] /= 4;
	free(color);
	return ((ssaa_color[0] << 16) | (ssaa_color[1] << 8) | ssaa_color[2]);
}

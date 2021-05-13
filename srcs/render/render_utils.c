/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deulee <deulee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 11:11:17 by deulee            #+#    #+#             */
/*   Updated: 2021/05/14 04:11:06 by deulee           ###   ########.fr       */
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
	{
		ssaa_color[i] /= 4;
		i++;
	}
	free(color);
	return ((ssaa_color[0] << 16) | (ssaa_color[1] << 8) | ssaa_color[2]);
}

int		close_minirt(t_render *render)
{
	clear_render(render);
	exit(EXIT_SUCCESS);
	return (1);
}

int		change_cam(int key, t_mlx *mlx)
{
	if (key == K_ESC)
		exit(0);
	if (key == K_SP)
	{
		if (mlx->cam->next == NULL)
		{
			mlx->cam = mlx->start;
			mlx_put_image_to_window(
					mlx->mlx_ptr, mlx->win_ptr,
					mlx->cam->img, 0, 0);
		}
		else
		{
			mlx->cam = mlx->cam->next;
			mlx_put_image_to_window(
					mlx->mlx_ptr, mlx->win_ptr, 
					mlx->cam->img, 0, 0);
		}
		return (1);
	}
	return (0);
}

void	graphic_loop_mlx(t_mlx mlx, t_scene trace)
{
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, trace.x_res, 
			trace.y_res, "miniRT");
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr,
			mlx.cam->img, 0, 0);
	mlx_hook(mlx.win_ptr, DESTROYNOTIFY, STRUCTURENOTIFYMASK,
			close_minirt, 0);
	mlx_hook(mlx.win_ptr, KEYPRESS, KEYPRESSMASK,
			change_cam, &mlx);
	mlx_loop(mlx.mlx_ptr);
}

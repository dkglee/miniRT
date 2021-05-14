/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deulee <deulee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 13:51:49 by deulee            #+#    #+#             */
/*   Updated: 2021/05/14 14:28:01 by deulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	init_mlx(t_mlx *mlx, t_scene *trace)
{
//	int		win_weight;
//	int		win_height;

	mlx->mlx_ptr = mlx_init();
/*	if (OS_TYPE == 2)
	{
		mlx_get_screen_size(mlx->mlx_ptr, &win_weight, &win_height);
		trace->x_res = trace->x_res < win_weight ? trace->x_res : win_weight;
		trace->y_res = trace->y_res < win_height ? trace->y_res : win_height;
	}*/
	mlx->start = mlx->cam;
	printf("trace->x_res: %d\n", trace->x_res);
	printf("trace->y_res: %d\n", trace->y_res);
	while (mlx->cam)
	{
		mlx->cam->img = mlx_new_image(mlx->mlx_ptr, trace->x_res, trace->y_res);
		mlx->cam->addr = (int *)mlx_get_data_addr(mlx->cam->img,
				&mlx->cam->bits_per_pixel, &mlx->cam->size_line, &mlx->cam->endian);
		mlx->cam = mlx->cam->next;
	}
	mlx->cam = mlx->start;
}

#ifndef LINUX

int		mlx_get_screen_size(void *mlx_ptr, int *sizex, int *sizey)
{
	mlx_ptr = (int *)mlx_ptr;
	sizex = sizey;
	return (0);
}

#endif

void	check_arg(int argc, char **argv)
{
	if (!(argc == 2 || argc == 3) || (argc == 3 && ft_strcmp("--save", argv[2])))
		error("Wrong Argument", NULL, NULL);
}

int		main(int argc, char **argv)
{
	t_render	render[NUM_THREADS];
	t_mlx		mlx;
	t_scene		trace;
	t_object	*list;
	int			size;

	check_arg(argc, argv);
	size = ft_strlen(argv[1]);
	if (size < 3)
		error("Filename Extension Error", NULL, NULL);
	else if (argv[1][size - 3] != '.' || argv[1][size - 2] != 'r' ||
			argv[1][size - 1] != 't')
		error("Filename Extension Error", NULL, NULL);
	parse(&mlx, &trace, &list, argv);
	init_mlx(&mlx, &trace);
	init_render(mlx, trace, list, render);
	multithread_render(render);
	if (argc == 3)
	{
		bmp_making(mlx, trace, argv[1]);
		clear_render(&render[0]);
	}
	else
		graphic_loop_mlx(mlx, trace);
	return (0);
}

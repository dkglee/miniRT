/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deulee <deulee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 13:51:49 by deulee            #+#    #+#             */
/*   Updated: 2021/05/07 08:03:36 by deulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	init_mlx(t_mlx *mlx, t_scene *trace)
{
	double	win_weight;
	double	win_height;

	mlx->mlx_ptr = mlx_init();
//	if (OS_NAME == 2) HAVE TO DELETE
//	{
		mlx_get_screen_size(mlx->mlx_ptr, &win_weight, &win_height);
		trace->x_res = trace->x_res < win_weight ? trace->x_res : win_weight;
		trace->y_res = trace->y_res < win_height ? trace->y_res : win_height;
//	}
	mlx->start = mlx->cam;
	while (mlx->cam)
	{
		mlx->cam->img = mlx_new_image(mlx->mlx->ptr, trace->x_res, trace->y_res);
		mlx->cam->addr = (int *)mlx_get_data_addr(mlx->cam->img,
				&mlx->cam->bits_per_pixel, &mlx->cam->size_line, &mlx->cam->endian);
		mlx->cam = mlx->cam->next;
	}
	mlx->cam = mlx->start;
}

int		main(int argc, char **argv)
{
	t_render	render[NUM_THREADS];
	t_mlx		mlx;
	t_scene		trace;
	t_object	*list;

	if (!(argc == 2 || argc == 3) || (argc == 3 && ft_strcmp("--save", argv[2])))
		error("Wrong Argument", NULL, NULL);
	if (ft_strlen(argv[1]) < 3)
		error("Filename Extension Error", NULL, NULL);
	else if (argv[1][size - 3] != '.' || argv[1][size - 2] != 'r' ||
			argv[1][size - 1] != 't')
		error("Filename Extension Error", NULL, NULL);
	parse(&mlx, &trace, list, argv);
	init_mlx(&mlx, &data);
	init_render(mlx, data, list, render);
	multithread_render(render);
	if (argc == 3)
	{
		bmp_making(mlx, data, argv[1]);
		clear_render(&render[0]);
	}
	graphic_loop_mlx(&render[0]);
	return (0);
}

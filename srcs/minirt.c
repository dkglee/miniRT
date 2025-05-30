/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deulee <deulee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 13:51:49 by deulee            #+#    #+#             */
/*   Updated: 2021/05/16 20:27:23 by deulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	init_mlx(t_mlx *mlx, t_scene *trace)
{
	int		win_weight;
	int		win_height;

	mlx->mlx_ptr = mlx_init();
	win_weight = 5120;
	win_height = 2880;
	trace->x_res = trace->x_res < win_weight ? trace->x_res : win_weight;
	trace->y_res = trace->y_res < win_height ? trace->y_res : win_height;
	mlx->start = mlx->cam;
	while (mlx->cam)
	{
		mlx->cam->img = mlx_new_image(mlx->mlx_ptr, trace->x_res, trace->y_res);
		mlx->cam->addr = (int *)mlx_get_data_addr(mlx->cam->img,
				&mlx->cam->bits_per_pixel, &mlx->cam->size_line, &mlx->cam->endian);
		mlx->cam = mlx->cam->next;
	}
	mlx->cam = mlx->start;
}

void	clear_memory(t_mlx *mlx, t_scene *trace, t_object **head)
{
	void		*tmp;
	t_object	*list;

	list = *head;
	while (list)
	{
		tmp = (void *)list->next;
		free(list);
		list = (t_object *)tmp;
	}
	list = NULL;
	head = NULL;
	while (mlx->cam)
	{
		tmp = (void *)mlx->cam->next;
		free(mlx->cam);
		mlx->cam = (t_cam *)tmp;
	}
	mlx->cam = NULL;
	while (trace->light)
	{
		tmp = (void *)trace->light->next;
		free(trace->light);
		trace->light = (t_light *)tmp;
	}
	tmp = NULL;
	trace->light = NULL;
}

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
		clear_memory(&mlx, &trace, &list);
	}
	else
		graphic_loop_mlx(&mlx, &trace, &list);
	return (0);
}

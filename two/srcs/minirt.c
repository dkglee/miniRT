/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deulee <deulee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 13:51:49 by deulee            #+#    #+#             */
/*   Updated: 2021/04/05 15:15:09 by deulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	main(int argc, char **argv)
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
	parse(&mlx, &trace, &list, argv);
	init_mlx(&mlx, &data);
	init_render(mlx, data, list, render);
	multithread_render(render);
	if (argc == 3)
		bmp_making(mlx, data, av[1]);
	graphic_loop(mlx, data);
	return (0);
}

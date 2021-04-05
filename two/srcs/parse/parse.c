/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deulee <deulee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 15:37:52 by deulee            #+#    #+#             */
/*   Updated: 2021/04/05 17:03:43 by deulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	parse(t_mlx *mlx, t_scene *trace, t_object *list, char **argv)
{
	t_parse		parse;

	*list = NULL;
	trace->lit = NULL;
	mlx->cam = NULL;
	mlx->start= NULL;
	trace->res_idx = 0;
	trace->amb_idx = 0;
	parse.mlx = mlx;
	parse.trace = trace;
	parse.object = list;
	parse.line = NULL;
	parse.info = NULL;
	parse.fd = open(argv[1], O_RDONLY);
	if (fd <= 2)
		error("File Open Error", NULL, NULL);
	start_parse(&parse);
	if (trace->res_idx == 0 || trace->amb_idx == 0 || mlx->cam == NULL)
		error("No Res Or Amb Or Cam", parse_error, &parse)
}

void	start_parse(t_parse *parse)
{
	int		flag;

	while ((flag = get_next_line(parse.fd, &parse.line)) != -1)
	{
		if (NULL = (parse.info = ft_split(parse.line, "\t\v\f\r ")))
			error(NULL, parse_error, &parse);
		if (parse.info[0] != NULL)
			parse_everyting(&parse);
		if (flag == 0)
			break ;
		free(parse.line);
		clear_info(parse.info);
		parse.info = NULL;
		parse.line = NULL;
	}
	if (flag == -1)
		error("Reading Line Error", parse_error, parse);
	clear_parse(&parse);
}

void	parse_info(t_parse *parse)
{
	if (!ft_strcmp(parse->info[0], RESOLUTION))
		parse_resolution(parse);
	else if (!ft_strcmp(parse->info[0], AMB_LIGHT))
		parse_amb_light(parse);
	else if (!ft_strcmp(parse->info[0], CAM))
		parse_cam(parse);
	else if (!ft_strcmp(parse->info[0], LIGHT))
		parse_light(parse);
	else if (!ft_strcmp(parse->info[0], SPHERE))
		parse_sphere(parse);
	else if (!ft_strcmp(parse->info[0], PLANE))
		parse_plane(parse);
	else if (!ft_strcmp(parse->info[0], SQUARE))
		parse_square(parse);
	else if (!ft_strcmp(parse->info[0], CYLINDER))
		parse_cylinder(parse);
	else if (!ft_strcmp(parse->info[0], TRIANGLE))
		parse_triangle(parse);
	else if (!ft_strcmp(parse->info[0], PYRAMID))
		parse_pyramid(parse);
	else if (!ft_strcmp(parse->info[0], CUBE))
		parse_cube(parse);
	else
		error("Element Error", clear_parser, parse);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deulee <deulee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 15:37:52 by deulee            #+#    #+#             */
/*   Updated: 2021/05/14 17:06:25 by deulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	parse(t_mlx *mlx, t_scene *trace, t_object **list, char **argv)
{
	t_parse		parse;
//	t_object	*tmp;

	*list = NULL;
	trace->light = NULL;
	mlx->cam = NULL;
	mlx->start= NULL;
	trace->res_idx = 0;
	trace->amb_idx = 0;
	parse.mlx = mlx;
	parse.trace = trace;
	parse.list = list;
	parse.line = NULL;
	parse.info = NULL;
	parse.fd = open(argv[1], O_RDONLY);
	if (parse.fd <= 2)
		error("File Open Error", NULL, NULL);
	start_parse(&parse, list);

	/*
	printf("--resolution--\n");
	printf("trace->x_res: %d\n", trace->x_res);
	printf("trace->y_res: %d\n", trace->y_res);
	printf("---amb_lit---\n");
	printf("trace->amb_light_ratio: %f\n", trace->amb_light);
	printf("trace->amb_color: %x\n", trace->amb_color);
//	while(mlx->cam)
//	{
	printf("---cam---\n");
	printf("cam_origin_vec_x: %f\n", mlx->cam->o.x);
	printf("cam_origin_vec_y: %f\n", mlx->cam->o.y);
	printf("cam_origin_vec_z: %f\n", mlx->cam->o.z);
	printf("cam_nv_vec_x: %f\n", mlx->cam->nv.x);
	printf("cam_nv_vec_y: %f\n", mlx->cam->nv.y);
	printf("cam_nv_vec_z: %f\n", mlx->cam->nv.z);
	printf("cam_fov: %f\n", mlx->cam->fov);
	mlx->cam = mlx->cam->next;
//	}
	printf("---light---\n");
	printf("light_origin_vec_x: %f\n", trace->light->o.x);
	printf("light_origin_vec_y: %f\n", trace->light->o.y);
	printf("light_origin_vec_z: %f\n", trace->light->o.z);
	printf("light_bright: %f\n", trace->light->br);
	printf("light->color: %x\n", trace->light->color);
	tmp = *list;
	printf("---object(sphere)---\n");
	printf("object_center_x: %f\n", tmp->fig.sp.center.x);
	printf("object_center_y: %f\n", tmp->fig.sp.center.y);
	printf("object_center_z: %f\n", tmp->fig.sp.center.z);
	printf("object_radius: %f\n", tmp->fig.sp.radius);
	printf("object_specular: %d\n", tmp->specular);
	printf("object_reflec: %f\n", tmp->reflec);
	printf("object_refrac: %f\n", tmp->refrac);
	printf("object_texture: %d\n", tmp->texture);
	printf("object_wavelength: %f\n", tmp->wavelength);
	printf("object_color: %x\n", tmp->color);
	tmp = tmp->next;
	printf("--object(plan)--\n");
	printf("object_center_x: %f\n", tmp->fig.pl.p.x);
	printf("object_center_y: %f\n", tmp->fig.pl.p.y);
	printf("object_center_z: %f\n", tmp->fig.pl.p.z);
	printf("object_nv_x: %f\n", tmp->normal.x);
	printf("object_nv_y: %f\n", tmp->normal.y);
	printf("object_nv_z: %f\n", tmp->normal.z);
	printf("object_specular: %d\n", tmp->specular);
	printf("object_reflec: %f\n", tmp->reflec);
	printf("object_refrac: %f\n", tmp->refrac);
	printf("object_texture: %d\n", tmp->texture);
	printf("object_wavelength: %f\n", tmp->wavelength);
	printf("object_color: %x\n", tmp->color);
*/
	if (trace->res_idx == 0 || trace->amb_idx == 0 || mlx->cam == NULL)
		error("No Res Or Amb Or Cam", parse_error, &parse);
}

void	start_parse(t_parse *parse, t_object **list)
{
	int		flag;

	while ((flag = get_next_line(parse->fd, &(parse->line))) != -1)
	{
		if (NULL == (parse->info = ft_split_str(parse->line, "\t\v\f\r ")))
			error(NULL, parse_error, parse);
		if (parse->info[0] != NULL)
			parse_info(parse, list);
		if (flag == 0)
			break ;
		clear_info(parse->info);
		free(parse->line);
		parse->info = NULL;
		parse->line = NULL;
	}
	if (flag == -1)
		error("Reading Line Error", parse_error, parse);
	clear_parse(parse);
}

void	parse_info(t_parse *parse, t_object **list)
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
		parse_sphere(parse, list);
	else if (!ft_strcmp(parse->info[0], PLANE))
		parse_plane(parse, list);
	else if (!ft_strcmp(parse->info[0], SQUARE))
		parse_square(parse, list);
	else if (!ft_strcmp(parse->info[0], CYLINDER))
		parse_cylinder(parse, list);
	else if (!ft_strcmp(parse->info[0], TRIANGLE))
		parse_triangle(parse, list);
	else if (!ft_strcmp(parse->info[0], PYRAMID))
		parse_pyramid(parse, list);
	else if (!ft_strcmp(parse->info[0], CUBE))
		parse_cube(parse, list);
	else
		error("Element Error", clear_parse, parse);
}

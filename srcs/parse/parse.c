/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deulee <deulee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 18:21:33 by deulee            #+#    #+#             */
/*   Updated: 2021/03/24 13:29:43 by deulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	parse(t_render *render, int argc, char **argv)
{
	t_parse		parse;
	int			flag;

	parse.render = render;
	parse.fd = is_valid_arg(render, argc, argv);
	parse.line = NULL;
	parse.info = NULL;
	while ((flag = get_next_line(parse.fd, &parse.line)) != -1)
	{
		if (NULL == (parse.info = ft_split(parser.line, "\t\v\f\r ")))
			error(NULL, parse_error, &parser);
		if (parse.info[0] != NULL)
			parse_info(&parse);
		if (flag == 0)
			break ;
		free(parse.line);
		clear_info(parse);
		parse.line = NULL;
	}
	if (flag == -1)
		error("Reading Line Error", parse_error, &parser);
	clear_parse(parse);
}

void	parse_info(t_parse *parse)
{
	if (!ft_strcmp(parse->info[0], RESOLUTION))
		parse_resolution(parse);
	else if (!ft_strcmp(parse->info[0], AMB_LIGHT))
		parse_ambient_light(parse);
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
	else
		error("Element Error", clear_parser, parse);
}

void	clear_info(t_parse *parse)
{
	int		i;

	i = 0;
	while (parse->info[i])
	{
		free(parse->info[i]);
		i++;
	}
	free(parse->info);
	parse->info = NULL;
}

void	clear_parse(t_parse *parse)
{
	free(parse->line);
	clear_lines(parse);
	parse->line = NULL;
	close(parse->fd);
}

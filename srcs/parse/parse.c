/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deulee <deulee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 18:21:33 by deulee            #+#    #+#             */
/*   Updated: 2021/03/23 19:11:49 by deulee           ###   ########.fr       */
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils_more.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deulee <deulee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 16:08:14 by deulee            #+#    #+#             */
/*   Updated: 2021/05/15 00:52:57 by deulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	clear_parse(void *ptr)
{
	t_parse		*parse;

	parse = (t_parse *)ptr;
	free(parse->line);
	clear_info(parse->info);
	parse->line = NULL;
	parse->info = NULL;
	close(parse->fd);
}

void	parse_error(void *ptr)
{
	t_parse		*parse;

	parse = (t_parse *)ptr;
	clear_parse(parse);
	clear_parsing(parse);
}

void	clear_parsing(t_parse *parse)
{
	void		*temp;
	t_object	*lst_temp;

	lst_temp = *(parse->list);
	while (parse->mlx->cam)
	{
		temp = (void *)parse->mlx->cam->next;
		free(parse->mlx->cam);
		parse->mlx->cam = (t_cam *)temp;
	}
	parse->mlx->cam = NULL;
	while (parse->trace->light)
	{
		temp = (void *)parse->trace->light->next;
		free(parse->trace->light);
		parse->trace->light = (t_light *)temp;
	}
	while (lst_temp)
	{
		temp = (void *)lst_temp->next;
		free(lst_temp);
		lst_temp = (t_object *)lst_temp;
	}
	*(parse->list) = NULL;
}

void	clear_info(char **info)
{
	int		i;

	i = 0;
	if (info == NULL)
		return ;
	while (info[i])
	{
		free(info[i]);
		info[i] = NULL;
		i++;
	}
	free(info);
	info = NULL;
}

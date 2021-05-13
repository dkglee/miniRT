/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils_more.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deulee <deulee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 16:08:14 by deulee            #+#    #+#             */
/*   Updated: 2021/05/13 18:43:26 by deulee           ###   ########.fr       */
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

bool	parse_vec_color(char *info, t_color *color)
{
	bool	flag;
	char	**split;
	char	*line;

	line = NULL;
	split = NULL;
	flag = true;
	line = ft_strdup(info);
	split = ft_split_str(line, ",");
	if (count_info(split) != 3)
		flag = false;
	else
	{
		color->x = ft_atoi(split[0]);
		color->y = ft_atoi(split[1]);
		color->z = ft_atoi(split[2]);
	}
	clear_info(split);
	free(line);
	line = NULL;
	split = NULL;
	return (flag);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils_more.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deulee <deulee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 16:08:14 by deulee            #+#    #+#             */
/*   Updated: 2021/05/10 17:17:44 by deulee           ###   ########.fr       */
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

	lst_tmp = *(parse->list);
	while (parse->mlx.cam)
	{
		temp = (void *)parse->mlx.cam->next;
		free(parse->mlx.cam);
		parse->mlx.cam = (t_cam *)temp;
	}
	parse->mlx.cam = NULL;
	while (parse->trace.light)
	{
		temp = (void *)parse->trace.light->next;
		free(parse->trace.light);
		parse->trace.light = (t_light *)temp;
	}
	while (lst_tmp)
	{
		temp = (void *)lst_tmp->next;
		free(lst_tmp);
		lst_tmp = (t_object *)lst_tmp;
	}
	*(parse->list) = NULL;
}

void	clear_info(char **info)
{
	int		i;

	i = 0;
	while (info[i])
	{
		free(info[i]);
		i++;
	}
	free(info);
}

bool	parse_vec_color(char *info, t_color *color)
{
	bool	flag;
	char	**split;

	flag = true;
	split = ft_split(info, ',');
	if (count_info(split) != 3)
		flag = false;
	else
	{
		color->x = ft_atoi(split[0]);
		color->y = ft_atoi(split[1]);
		color->z = ft_atoi(split[2]);
	}
	clear_info(split);
	split = NULL;
	return (flag);
}

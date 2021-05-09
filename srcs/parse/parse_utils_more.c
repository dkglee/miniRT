/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils_more.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deulee <deulee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 16:08:14 by deulee            #+#    #+#             */
/*   Updated: 2021/05/09 23:05:17 by deulee           ###   ########.fr       */
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

t_object	*ft_new_object(t_object *list)
{
	t_object	*new;

	new = (t_object *)malloc(sizeof(t_object));
	if (new == NULL)
		error("Object Malloc Error", NULL, NULL);
	ft_objadd_back(&list, new);
	return (new);
}

void	ft_objadd_back(t_object **head, t_object *new)
{
	t_object	*fin;

	if (!(head) || !(new))
		return ;
	if (*head == NULL)
	{
		*head = new;
		return ;
	}
	fin = *head;
	while (fin->next != NULL)
		fin = fin->next;
	new->next = fin->next;
	fin->next = new;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils_more.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deulee <deulee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 16:08:14 by deulee            #+#    #+#             */
/*   Updated: 2021/04/16 14:43:53 by deulee           ###   ########.fr       */
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
	clear_render(parse);
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

t_object	*ft_new_object(t_parse *parse)
{
	t_object	*new;

	new = (t_object *)malloc(sizeof(t_object));
	if (new == NULL)
		error("Object Malloc Error", NULL, NULL);
	ft_lstadd_back(&parse->object, new);
	return (new);
}

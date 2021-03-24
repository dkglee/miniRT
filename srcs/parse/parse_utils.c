/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deulee <deulee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 13:41:38 by deulee            #+#    #+#             */
/*   Updated: 2021/03/24 15:57:02 by deulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		count_info(char **info)
{
	int		idx;

	if (info == NULL)
		return (-1);
	idx = 0;
	while (info[idx])
		idx++;
	return (idx);
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

bool	parse_double(char *info, double *value)
{
	bool	flag;
	char	**split;

	flag = true;
	split = ft_split(info, ",");
	if (count_info(split) != 1)
	{
		flag = false;
		return (flag);
	}
	*value = ft_atof(info);
	clear_info(split);
	split = NULL;
	return (flag);
}

bool	parse_vec(char *info, t_vec *v)
{
	bool	flag;
	char	**split;

	flag = true;
	split = ft_split(info, ",");
	if (count_info(split) != 3)
		flag = false;
	else
	{
		v->x = ft_atof(split[0]);
		v->y = ft_atof(split[1]);
		v->z = ft_atof(split[2]);
	}
	clear_info(split);
	split = NULL;
	return (flag);
}

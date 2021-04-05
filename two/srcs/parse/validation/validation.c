/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deulee <deulee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 19:12:54 by deulee            #+#    #+#             */
/*   Updated: 2021/04/05 23:52:23 by deulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool	validation_extraction(char **info)
{
	bool	flag;
	int		idx;
	char	**split;

	idx = 0;
	flag = true;
	while (info[idx])
	{
		if (info[idx][0] == ',' ||
				info[idx][ft_strlen(info[idx]) ?
				ft_strlen(info[idx]) - 1 : 0] == ',')
			flag = false;
		split = ft_split(info[idx], ",");
		if (split == NULL)
			flag = false;
		else if (!validation_float(split))
			flag = false;
		clear_info(split);
		idx++;
	}
	return (flag);
}

bool	validation_float(char **info)
{
	bool	flag;
	char	*num;
	int		idx;

	idx = 0;
	flag = true;
	while (info[idx])
	{
		num = info[idx];
		if (*num == '+' || *num == '-')
			num++;
		while (ft_isdigit(*num))
			num++;
		if (*num == '.')
			num++;
		while (ft_isdigit(*num))
			num++;
		if (*num != '\0')
		{
			flag = false;
			break;
		}
		idx++;
	}
	return (flag);
}

bool	validation_range(double num, double min, double max)
{
	if (num < min || nb > max)
		return (false);
	return (true);
}

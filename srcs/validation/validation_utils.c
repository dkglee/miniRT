/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deulee <deulee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 16:17:17 by deulee            #+#    #+#             */
/*   Updated: 2021/05/13 17:48:54 by deulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool	validate_int(char *info)
{
	bool	flag;
	int		i;

	i = 0;
	flag = true;
	while (info[i])
	{
		if (!(ft_isdigit(info[i])))
			flag = false;
		i++;
	}
	return (flag);
}

bool	validate_double(char *info)
{
	bool	flag;
	int		i;

	i = 0;
	flag = true;
	while (info[i])
	{
		if (!(ft_isdigit(info[i]) || info[i] == '.'))
			flag = false;
		i++;
	}
	return (flag);
}

bool	validate_vector(char *info)
{
	bool	flag;
	int		i;
	int		check;

	i = 0;
	check = 0;
	flag = true;
	while (info[i])
	{
		if (!(ft_isdigit(info[i]) || info[i] == '.' || info[i] == ',' || info[i] == '-'))
			flag = false;
		i++;
	}
	i = 0;
	while (info[i])
	{
		if (info[i] == ',')
			check++;
		i++;
	}
	if (check != 2)
		flag = false;
	return (flag);
}

bool	validate_color(char *info)
{
	bool	flag;
	int		i;

	i = 0;
	flag = true;
	while (info[i])
	{
		if (!(ft_isdigit(info[i]) || info[i] == ','))
			flag = false;
		i++;
	}
	return (flag);
}

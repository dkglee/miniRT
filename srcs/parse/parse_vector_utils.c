/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_vector_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deulee <deulee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 19:06:15 by deulee            #+#    #+#             */
/*   Updated: 2021/05/13 19:38:49 by deulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool	check_line(char *line)
{
	bool	flag;
	int		i;
	int		check;

	i = 0;
	check = 0;
	flag = true;
	while (line[i])
	{
		if (ft_isdigit(line[i]) || line[i] == '.' || line[i] == '-')
		{
			check += 1;
			while (ft_isdigit(line[i]) || line[i] == '.' || line[i] == '-')
				i++;
			i--;
		}
		else if (line[i] == ',')
			check += 1;
		i++;
	}
	if (check != 5)
		flag = false;
	return (flag);
}

double	parse_vec_double(char *info, int len)
{
	char	*line;
	double	num;
	int		i;

	i = 0;
	line = (char *)malloc(sizeof(char) * (len + 1));
	while (i < len)
	{
		line[i] = info[i];
		i++;
	}
	line[i] = '\0';
	num = ft_atof(line);
	return (num);
}

int		ft_strlen_vec(char *str)
{
	int		i;

	i = 0;
	while(str[i] != ',' && str[i])
		i++;
	return (i);
}

bool	parse_vec(char *info, t_vec *v)
{
	bool	flag;
	int		len_1;
	int		len_2;
	int		len_3;

	flag = true;
	flag = flag && check_line(info);
	len_1 = ft_strlen_vec(info);
	len_2 = ft_strlen_vec(info + len_1 + 1);
	len_3 = ft_strlen_vec(info + len_1 + len_2 + 2);
	v->x = parse_vec_double(info, len_1);
	v->y = parse_vec_double(info + len_1 + 1, len_2);
	v->z = parse_vec_double(info + len_1 + len_2 + 2, len_3);
	return (flag);
}

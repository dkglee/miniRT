/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deulee <deulee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 00:52:25 by deulee            #+#    #+#             */
/*   Updated: 2021/05/15 01:07:31 by deulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static bool	check_color_line(char *line)
{
	bool	flag;
	int		i;
	int		check;

	i = 0;
	check = 0;
	flag = true;
	while (line[i])
	{
		if (ft_isdigit(line[i]))
		{
			check += 1;
			while (ft_isdigit(line[i]))
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

static int	parse_color(char *info, int len)
{
	char	*line;
	double	num;
	int		i;

	i = 0;
	line = (char *)malloc(sizeof(char) * (len + 1));
	if (line == NULL)
		error("Malloc Error", NULL, NULL);
	while (i < len)
	{
		line[i] = info[i];
		i++;
	}
	line[i] = '\0';
	num = ft_atoi(line);
	free(line);
	line = NULL;
	return (num);
}

bool	parse_vec_color(char *info, t_color *color)
{
	bool	flag;
	int		len_1;
	int		len_2;
	int		len_3;

	flag = true;
	flag = flag && check_color_line(info);
	len_1 = ft_strlen_vec(info);
	len_2 = ft_strlen_vec(info + len_1 + 1);
	len_3 = ft_strlen_vec(info + len_1 + len_2 + 2);
	color->x = parse_color(info, len_1);
	color->y = parse_color(info + len_1 + 1, len_2);
	color->z = parse_color(info + len_1 + len_2 + 2, len_3);
	return (flag);
}

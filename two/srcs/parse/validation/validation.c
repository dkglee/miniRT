/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deulee <deulee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 19:12:54 by deulee            #+#    #+#             */
/*   Updated: 2021/03/26 16:35:27 by deulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		is_valid_arg(t_render *render, int argc, char **argv)
{
	int				fd;
	unsigned int	size;

	if (!(argc == 2 || argc == 3) || (argc == 3 && ft_strcmp("--save", argv[2])))
		error("Wrong Argument", NULL, NULL);
	if (argc == 3)
		render->control.save = true;
	size = ft_strlen(argv[1]);
	if (size < 3)
		error("Filename Extension Error", NULL, NULL);
	else if (argv[1][size - 3] != '.' || argv[1][size - 2] != 'r' ||
			argv[1][size - 1] != 't')
		error("Filename Extension Error", NULL, NULL);
	fd = open(argv[1], O_RDONLY);
	if (fd <= 2)
		error(NULL, NULL, NULL);
	return (fd);
}

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

bool	validation_parse(t_render *render)
{
	double	ratio;
	t_cam	*cam;

	if (render->trace.width <= 0 ||
			render->trace.height <= 0 ||
			render->stuff.cam == NULL ||
			render->stuff.amb_light == NULL)
		return (false);
	ratio = (double)render->trace.width / (double)render->trace.height;
	cam = render->stuff.cam;
	while (cam != NULL)
	{
		cam->viewport_ratio = ratio;
		refresh_cam(cam);
		cam = cam->next;
	}
	return (true);
}

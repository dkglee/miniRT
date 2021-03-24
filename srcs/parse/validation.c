/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deulee <deulee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 19:12:54 by deulee            #+#    #+#             */
/*   Updated: 2021/03/24 13:02:13 by deulee           ###   ########.fr       */
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

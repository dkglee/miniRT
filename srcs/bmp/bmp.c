/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deulee <deulee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 20:46:17 by deulee            #+#    #+#             */
/*   Updated: 2021/05/16 15:14:45 by deulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		create_fd(char *name)
{
	int		i[2];
	char	*tmp_name;
	char	*tmp_name_2;
	char	*file_name;
	int		fd;

	i[0] = 0;
	i[1] = 0;
	while (name[i[0]])
	{
		if (name[i[0]] == '/')
			i[1] = i[0] + 1;
		(i[0])++;
	}
	tmp_name = ft_strndup(name + i[1], ft_strlen(name + i[1]) - 3);
	tmp_name_2 = ft_strjoin("images/", tmp_name);
	file_name = ft_strjoin(tmp_name_2, ".bmp");
	fd = open(file_name, O_WRONLY | O_CREAT | O_TRUNC,
			S_IRUSR | S_IWUSR);
	if (fd <= 0)
		error("Fd Making Error", NULL, NULL);
	name_free(&tmp_name, &tmp_name_2, &file_name);
	return (fd);
}

void	create_header(t_scene trace, t_bmpheader *header, t_bmpinfhead *info)
{
	header->bftype[0] = 0x42;
	header->bftype[1] = 0x4D;
	header->bfsize = (trace.x_res * trace.y_res * 4) + 54;
	header->bfreserved = 0x00000000;
	header->bfoffbits = 0x36;
	info->bisize = 40;
	info->biwidth = trace.x_res;
	info->biheight = -trace.y_res;
	info->bicolplanes = 1;
	info->bibitcount = 32;
	info->bicompression = 0;
	info->bisize_img = (trace.x_res * trace.y_res * 4);
	info->bix_ppm = 2835;
	info->biy_ppm = 2835;
	info->bicolor_used = 0;
	info->biimport_color = 0;
}

void	write_head(int fd, t_bmpheader header, t_bmpinfhead info)
{
	write(fd, &header.bftype, 2);
	write(fd, &header.bfsize, 4);
	write(fd, &header.bfreserved, 4);
	write(fd, &header.bfoffbits, 4);
	write(fd, &info.bisize, 4);
	write(fd, &info.biwidth, 4);
	write(fd, &info.biheight, 4);
	write(fd, &info.bicolplanes, 2);
	write(fd, &info.bibitcount, 2);
	write(fd, &info.bicompression, 4);
	write(fd, &info.bisize_img, 4);
	write(fd, &info.bix_ppm, 4);
	write(fd, &info.biy_ppm, 4);
	write(fd, &info.bicolor_used, 4);
	write(fd, &info.biimport_color, 4);
}

void	write_contents(int fd, t_mlx mlx, t_scene trace)
{
	char	*data;
	int		size;
	int		i;
	int		j;
	int		mask;

	i = 0;
	j = 0;
	mask = 255;
	data = (char *)malloc(mlx.cam->size_line * trace.y_res);
	if (data == NULL)
		error("Malloc Error", NULL, NULL);
	size = trace.x_res * trace.y_res;
	while (i < size)
	{
		data[j++] = mlx.cam->addr[i] & mask;
		data[j++] = (mlx.cam->addr[i] & mask << 8) >> 8;
		data[j++] = (mlx.cam->addr[i] & mask << 16) >> 16;
		data[j++] = 0;
		i++;
	}
	write(fd, data, mlx.cam->size_line * trace.y_res);
	free(data);
}

void	bmp_making(t_mlx mlx, t_scene trace, char *name)
{
	int				fd;
	t_bmpheader		head;
	t_bmpinfhead	info;

	fd = create_fd(name);
	create_header(trace, &head, &info);
	write_head(fd, head, info);
	write_contents(fd, mlx, trace);
	close(fd);
}

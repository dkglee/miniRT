/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deulee <deulee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 20:46:17 by deulee            #+#    #+#             */
/*   Updated: 2021/04/16 14:32:59 by deulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		create_fd(char *name)
{
	int		i;
	int		start;
	char	*tmp_name;
	char	*file_name;

	i = 0;
	start = 0;
	while (name[i])
	{
		if (name[i] == '/')
			start = i;
		i++;
	}
	tmp_name = ft_strjoin("images/", name + start);
	file_name = ft_strjoin(tmp_name, ".bmp");
	free(tmp_name);
	tmp_name = NULL;
	fd = open(file_name, O_WRONLY | O_CREAT | O_TRUNC,
			S_IRUSR | S_IWUSR);
	if (fd <= 0)
		error("Fd Making Error", NULL, NULL);
	free(file_name);
	file_name = NULL;
	return (fd);
}

void	create_header(t_scene trace, t_bmpheader *head, t_bmpinfhead *info)
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
	info->bix_ppm 2835;
	info->biy_ppm = 2835;
	info->bicolor_used = 0;
	info->biimport_color = 0;
}

void	write_head(int fd, t_bmpheader head, t_bmpinfhead info)
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

char	*write_contents(t_mlx mlx, t_scene trace)
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
		data[j++] = (mlx.cam->addr[i] & (mask << 8)) >> 8;
		data[j++] = (mlx.cam->addr[i] & (mask << 16)) >> 16;
		data[j++] = 0;
		i++;
	}
	return (data);
}

void	bmp_making(t_mlx mlx, t_scene trace, char *name)
{
	int				fd;
	t_bmpheader		head;
	t_bmpinfhead	info;
	char			*data;

	fd = create_fd(name);
	create_header(trace, &head, &info);
	write_head(fd, head, info);
	data = write_contents(mlx, trace);
	write(fd, data, mlx.cam->size_line * trace.y_res);
	free(data);
	close(fd);
}

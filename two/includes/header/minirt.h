/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deulee <deulee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 13:52:59 by deulee            #+#    #+#             */
/*   Updated: 2021/04/05 23:11:19 by deulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "mlx.h"
# include "ggl_mlx_define.h"
# include "libft.h"
# include "vector.h"
# include "object.h"
# include "error.h"
# include "rotation.h"
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include <pthread.h>

# ifndef MACOS
#  define OS_TYPE 1
# endif

# ifndef LINUX
#  define OS_TYPE 2
# endif

# define REFLECTION_LIMIT 3

# define EPSILON 0.00001

# define BUFFSIZE 1024

# ifndef NUM_THREADS
#  define NUM_THREADS 4
# endif

# define SP 1
# define PL 2
# define SQ 3
# define TR 4
# define CY 5
# define CU 6
# define PY 7

# define RESOLUTION "R"
# define AMB_LIGHT "A"
# define CAM "c"
# define LIGHT "l"
# define SPHERE "sp"
# define PLANE "pl"
# define SQUARE "sq"
# define CYLINDER "cy"
# define TRIANGLE "tr"
# define CUBE "cu"
# define PYRAMID "py"

# define CAM_MODE 8
# define OBJ_MODE 9
# define LIT_MODE 10

typedef	struct		s_vec3
{
	t_vec			orig;
	t_vec			dir;
}

typedef	struct		s_mlx
{
	void			*mlx_ptr;
	void			*win_ptr;
	t_cam			*cam;
	t_cam			*start;
}					t_mlx;

typedef	struct		s_object
{
	int				flag;
	t_figures		fig;
	int				color;
	t_vec			rgb_color;
	int				specular;
	double			reflec;
	double			refrac;
	int				texture;
	t_vec			normal;
	double			wavelength;
	struct s_object	*next;
}					t_object;

typedef	struct		s_rss
{
	double			x_res;
	double			y_res;
	int				i;
	int				j;
	int				limit;
}

typedef	struct		s_cam
{
	int				init;
	int				idx;
	t_vec			o;
	t_vec			nv;
	int				fov;
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				size_line;
	int				endian;
	struct s_cam	*next;
}					t_cam;

typedef	struct		s_light
{
	t_vec			o;
	double			br;
	int				color;
	struct s_light	*next;
}					t_light;

typedef	struct		s_scene
{
	double			x_res;
	double			y_res;
	int				cam_nb;
	t_light			*light;
	int				res_idx;
	int				amb_idx;
	double			amb_light;
	int				amb_color;
	int				bgr;
}					t_scene;

typedef	struct		s_bmp
{
	char			type[2];
	unsigned int	size;
	unsigned int	reserved;
	unsigned int	offest;
}					t_bmp;

typedef	struct		s_render
{
	t_mlx			mlx;
	t_scene			data;
	t_obj			*list;
	int				idx;
	int				i;
	int				j;
}					t_render;

typedef	struct		s_inter
{
	int				color;
	int				ref_color;
	t_vec			norm;
	t_vec			p;
	t_vec			ref_vec;
}					t_inter;

typedef	struct		s_heading
{
	unsigned int	size;
	double			width;
	double			height;
	unsigned int	bpp;
	unsigned int	colplanes;
	unsigned int	compression;
	unsigned int	img_size;
	int				x_ppm;
	int				y_ppm;
	unsigned int	color_nb;
	unsigned int	import_color;
}					t_heading;

typedef	struct		s_parse
{
	char			*line;
	char			**info;
	int				fd;
	t_mlx			*mlx;
	t_scence		*trace;
	t_object		*list;
}					t_parse;

#endif

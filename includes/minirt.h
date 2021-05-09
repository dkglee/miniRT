/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deulee <deulee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 13:52:59 by deulee            #+#    #+#             */
/*   Updated: 2021/05/09 22:44:40 by deulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "mlx.h"
# include "x_eleven.h"
# include "libft.h"
# include "get_next_line.h"
# include "vector.h"
# include "object.h"
# include "error.h"
# include "rotation.h"
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include <pthread.h>
# include <stdbool.h>

# ifndef MACOS
#  define OS_TYPE 1
# endif

# ifndef LINUX
#  define OS_TYPE 2
# endif

# define REFLECTION_LIMIT 3

# define EPSILON 0.00001

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

typedef	struct		s_ray
{
	t_vec			origin;
	t_vec			dir;
}					t_ray;

typedef struct		s_object
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

typedef struct		s_tmp
{
	int				x_res;
	int				y_res;
	int				i;
	int				j;
	int				limit;
}					t_tmp;

typedef struct		s_cam
{
	int				init;
	int				idx;
	t_vec			o;
	t_vec			nv;
	int				fov;
	void			*img;
	int				*addr;
	int				bits_per_pixel;
	int				size_line;
	int				endian;
	struct s_cam	*next;
}					t_cam;

typedef struct		s_light
{
	t_vec			o;
	double			br;
	int				color;
	struct s_light	*next;
}					t_light;

typedef	struct		s_scene
{
	int				x_res;
	int				y_res;
	int				cam_nb;
	t_light			*light;
	int				res_idx;
	int				amb_idx;
	double			amb_light;
	int				amb_color;
	int				bgr;
}					t_scene;

typedef	struct		s_bmpheader
{
	char			bftype[2];
	unsigned int	bfsize;
	unsigned int	bfreserved;
	unsigned int	bfoffbits;
}					t_bmpheader;

typedef	struct		s_mlx
{
	void			*mlx_ptr;
	void			*win_ptr;
	t_cam			*cam;
	t_cam			*start;
}					t_mlx;

typedef	struct		s_render
{
	t_mlx			mlx;
	t_scene			trace;
	t_object		*list;
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

typedef	struct		s_bmpinfhead
{
	unsigned int	bisize;
	double			biwidth;
	double			biheight;
	unsigned int	bibitcount;
	unsigned int	bicolplanes;
	unsigned int	bicompression;
	unsigned int	bisize_img;
	int				bix_ppm;
	int				biy_ppm;
	unsigned int	bicolor_used;
	unsigned int	biimport_color;
}					t_bmpinfhead;

typedef	struct		s_parse
{
	char			*line;
	char			**info;
	int				fd;
	t_mlx			*mlx;
	t_scene			*trace;
	t_object		**list;
}					t_parse;

typedef	struct		s_sq
{
	t_vec			half_size;
	t_vec			floor;
	t_vec			center_to_point;
}					t_sq;

typedef struct		s_cube
{
	t_object		sq;
	t_vec			center;
	t_vec			normal[6];
}					t_cube;

typedef	struct		s_pyramid
{
	t_object		sq;
	t_object		tr;
	t_vec			center;
	t_vec			normal[5];
	t_vec			corner[4];
}					t_pyramid;

/* bmp */

int					create_fd(char *name);
void				create_header(t_scene trace, t_bmpheader *head, t_bmpinfhead *info);
void				write_head(int fd, t_bmpheader head, t_bmpinfhead info);
char				*write_contents(t_mlx mlx, t_scene trace);
void				bmp_making(t_mlx mlx, t_scene trace, char *name);

/* error */

void				error(char *str, void (*func)(void *), void *arg);

/* math */

int					color_product(int color, double coef);
int					color_add(int x, int y);
int					color_difference(int x, int y);
int					color_light(int color, t_vec rgb);

double				ft_vec_dis(t_vec v, t_vec u);
t_vec				rotation_x(t_vec v, double degree);
t_vec				rotation_y(t_vec v, double degree);
t_vec				rotation_z(t_vec v, double degree);

t_vec				ft_vec_set(double x, double y, double z);
t_vec				ft_vec_unit(t_vec u);
double				ft_vec_size(t_vec v);
double				ft_vec_cos(t_vec v, t_vec u);
double				ft_vec_sin(t_vec v, t_vec u);
t_vec				ft_vec_add(t_vec u, t_vec v);
t_vec				ft_vec_sub(t_vec u, t_vec v);
t_vec				ft_vec_cross(t_vec u, t_vec v);
t_vec				ft_vec_product(t_vec u, double scalar);
double				ft_vec_dot(t_vec u, t_vec v);

/* minirt */

void				init_mlx(t_mlx *mlx, t_scene *trace);

/* parse */

void				parse_cube(t_parse *parse);
void				parse_pyramid(t_parse *parse);
void				parse(t_mlx *mlx, t_scene *trace, t_object *list, char **argv);
void				start_parse(t_parse *parse);
void				parse_info(t_parse *parse);
void				parse_resolution(t_parse *parse);
void				parse_amb_light(t_parse *parse);
void				parse_cam(t_parse *parse);
void				parse_light(t_parse *parse);
void				parse_sphere(t_parse *parse);
void				parse_plane(t_parse *parse);
void				parse_square(t_parse *parse);
void				parse_triangle(t_parse *parse);
void				parse_cylinder(t_parse *parse);
int					count_info(char **info);
bool				parse_double(char *info, double *value);
bool				parse_vec(char *info, t_vec *v);
bool				parse_int(char *info, int *value);
int					get_color(t_vec color);
void				ft_addcam_back(t_cam **head, t_cam *new);
void				ft_addlight_back(t_light **head, t_light *new);
void				clear_parse(void *ptr);
void				parse_error(void *ptr);
void				clear_info(char **info);
t_object			*ft_new_object(t_parse *parse);
void				ft_objadd_back(t_object **head, t_object *new);

/* parse validation */


bool				validation_extraction(char **info);
bool				validation_float(char **info);
bool				validation_range(double num, double min, double max);
bool				validation_sqaure(t_object *o);
bool				validation_sphere(t_object *o);
bool				validation_plane(t_object *o);
bool				validation_sqaure(t_object *o);
bool				validation_triangle(t_object *o);
bool				validation_cylinder(t_object *o);
bool				validation_resolution(double horiz, double ver);
bool				validation_amb_light(double ratio, t_vec *color);
bool				validation_cam(t_vec *normal, double fov);
bool				validation_light(double ratio, t_vec *color);

/* ray */

t_vec				set_camera(int n, t_tmp tmp, t_mlx mlx);
t_vec				ft_look_at(t_vec dir, t_vec cam);
int					calc_ray(int n, t_tmp tmp, t_render *render);

/* trace */

void				make_pyramid(t_pyramid *f, t_object *list);
double				cube_intersection_point(t_vec o, t_vec d, t_object *list);
void				make_pyramid(t_pyramid *f, t_object *list);
double				pyramid_intersection_point(t_vec o, t_vec d, t_object *list);
void				find_intersection(t_ray ray, t_render *list,
			t_object *closet_obj, double *closet_dis);
void				init_information(t_object *cl_obj, double cl_dis);
int					ray_trace(t_vec origin, t_vec dir, t_render *render, int depth);
bool				find_distance(double dis[2], t_vec origin, t_vec dir, t_object *list);
t_vec				get_cy_normal(double dis[2], t_vec origin, t_vec dir, t_object *list);
double				intersection_cylinder(t_vec origin, t_vec dir, t_vec *cy_normal, t_object *list);
double				intersection_circle(t_vec origin, t_vec dir, t_object *list);
double				cylinder_intersection_point(t_vec origin, t_vec dir, t_object *list);
double				intersection_plane(t_vec origin, t_vec dir, t_vec point, t_vec nv);
double				plane_intersection_point(t_vec origin, t_vec dir, t_object *list);
void				intersection_sphere(double dis[2], t_vec origin, t_vec dir, t_object *list);
double				sphere_intersection_point(t_vec origin, t_vec dir, t_object *list);
double				square_intersection_point(t_vec origin, t_vec dir, t_object *list);
bool				check_point_inside(t_vec p1, t_vec p2, t_vec p3, t_vec point);
double				triangle_intersection(t_vec origin, t_vec dir, t_object *list);

/* light */

void				apply_shading(t_vec ray, t_inter *inter, t_scene trace, t_object *list);
void				get_norm(t_vec p, t_vec d, t_vec *normal, t_object *list);
void				add_light(double (*rgb)[3], double ratio, int color);
t_vec				reflection(t_vec ray, t_vec normal);
t_vec				refraction(t_vec dir, t_vec normal, t_object *list);
double				apply_specular(t_vec ray, t_inter *inter, t_scene trace, t_object *list);
bool				valid_bright(t_vec o, t_vec d, t_object *list);

/* texture */

int					checkboard(t_inter *inter);
int					wave(t_inter *inter, t_object *list);
void				apply_color(double r, double g, double b, double color[3]);
int					rainbow(double y);
void				get_texture(int	texture, t_inter *inter, t_object *list);

/* render */

void				*start_render(void *ptr);
void				multithread_render(t_render render[NUM_THREADS]);
void				init_render(t_mlx mlx, t_scene trace, t_object *list, t_render *render);
void				render_word(t_render *render);
int					find_pixel_color(t_render *render);
void				render_error(void *ptr);
void				clear_render(t_render *render);
int					calc_avg_simple_color(int a, int b);
int					calc_avg_ssaa_color(int *color);
int					close_minirt(t_render *render);
int					change_cam(int key, t_render *render);
void				graphic_loop_mlx(t_render *render);
int					sample_first(int *edge, int last[2], t_tmp tmp, t_render *render);
int					sample_center(int *edge, int last[2], t_tmp tmp, t_render *render);
int					sample_last(int *edge, int last[2], t_tmp tmp, t_render *render);
int					*simple_sample(int *edge, int last[2], t_tmp tmp, t_render *render);
int					ssaa_zero(int *color, int c_col, t_tmp tmp, t_render *render);
int					ssaa_one(int *color, int c_col, t_tmp tmp, t_render *render);
int					ssaa_two(int *color, int c_col, t_tmp tmp, t_render *render);
int					ssaa_three(int *color, int c_col, t_tmp tmp, t_render *render);
int					super_sample(int *color, t_tmp tmp, t_render *render);

#endif

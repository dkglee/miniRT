/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deulee <deulee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 19:30:18 by deulee            #+#    #+#             */
/*   Updated: 2021/04/17 17:54:00 by deulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	render_word(t_render *render)
{
	int		size;
	int		color;

	size = w->trace.y_res / NUM_THREADS;
	render->j = size * render->idx;
	while (render->j < size * (render->idx + 1))
	{
		render->i = 0;
		while (render->i < render->trace.x_res)
		{
			color = find_pixel_color(render);
			render->mlx.cam->addr[render->j *
				render->trace.x_res + render->i] = color;
			render->i++;
		}
		render->j++;
	}
}

int		find_pixel_color(t_render *render)
{
	int		*color;
	int		last[2];
	int		edge[render->trace.x_res + 2];
	t_tmp	tmp;

	tmp.limit = 3;
	tmp.x_res = render->trace.x_res;
	tmp.y_res = render->trace.y_res;
	tmp.i = render->i;
	tmp.j = render->j;
	render->trace.bgr = 0x202020;
	color = simple_sample(edge, last, tmp, render);
	if ((color_difference(color[0], color[3]) > 1000) ||
			(color_difference(color[1], color[2]) > 1000))
		return (super_sample(color, tmp, render));
	return (cal_avg_ssaa_color(color));
}

void	render_error(void *ptr)
{
	t_render *render;

	render = (t_render *)ptr;
	clear_render(render);
}

void	clear_render(t_render *render)
{
	void	*temp;

	while (render->list)
	{
		temp = (void *)render->list->next;
		free(render->list);
		render->list = (t_object *)temp;
	}
	render->list = NULL;
	while (render->mlx.cam)
	{
		temp = (void *)render->mlx.cam->next;
		free(render->mlx.cam);
		render->mlx.cam = (t_cam *)temp;
	}
	render->mlx.cam = NULL;
	while (render->trace.light)
	{
		temp = (void *)render->trace.light->next;
		free(render->trace.light);
		render->trace.light = (t_light *)temp;
	}
	temp = NULL;
	render->trace.light = NULL;
}

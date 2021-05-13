/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multithread.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deulee <deulee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 17:56:47 by deulee            #+#    #+#             */
/*   Updated: 2021/05/14 03:17:51 by deulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	*start_render(void *ptr)
{
	t_render	*render;

	render = (t_render *)ptr;
	while (render->mlx.cam)
	{
		render_world(render);
		render->mlx.cam = render->mlx.cam->next;
	}
	return (NULL);
}

void	multithread_render(t_render render[NUM_THREADS])
{
	pthread_t	threads[NUM_THREADS];
	int			idx;

	idx = 0;
	while (idx < NUM_THREADS)
	{
		pthread_create(&threads[idx], NULL, start_render, &render[idx]);
		idx++;
	}
	idx = 0;
	while (idx < NUM_THREADS)
	{
		pthread_join(threads[idx], NULL);
		idx++;
	}
}

void	init_render(t_mlx mlx, t_scene trace, t_object *list, t_render *render)
{
	int		idx;

	idx = 0;
	while (idx < NUM_THREADS)
	{
		render[idx].mlx = mlx;
		render[idx].trace = trace;
		render[idx].list = list;
		render[idx].idx = idx;
		idx++;
	}
}

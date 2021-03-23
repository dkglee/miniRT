/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deulee <deulee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 17:10:39 by deulee            #+#    #+#             */
/*   Updated: 2021/03/21 17:13:50 by deulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

typedef struct	s_render
{
	t_world		world;
	t_control	control;
	t_trace		trace;
}				t_render;

void			init_render(t_render *render);

#endif

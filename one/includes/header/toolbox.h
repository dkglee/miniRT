/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toolbox.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deulee <deulee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 17:48:03 by deulee            #+#    #+#             */
/*   Updated: 2021/03/23 18:16:05 by deulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOOLBOX_H
# define TOOLBOX_H

typedef	struct	s_toolbox
{
	void		(*move)(void *, t_vec);
	void		(*rotate)(void *, t_vec (*rotate_dir)(t_vec, double), double);
	void		(*stretch)(void *, double, int);
	void		(*hit)(void *, t_ray *, t_vec *);
	void		(*clear)(void *);
	void		(*refresh)(void *);
	int			stretch_mode;
}				t_toolbox;

void		init_sp_toolbox(t_toolbox *tool);
void		init_pl_toolbox(t_toolbox *tool);
void		init_sq_toolbox(t_toolbox *tool);
void		init_cy_toolbox(t_toolbox *tool);
void		init_tr_toolbox(t_toolbox *tool);

#endif

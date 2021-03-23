/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_toolbox.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deulee <deulee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 17:36:28 by deulee            #+#    #+#             */
/*   Updated: 2021/03/23 17:45:23 by deulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void		init_sp_toolbox(t_toolbox *tool)
{
	tool->move = move_sp;
	tool->rotate = rotate_sp;
	tool->stretch = stretch_sp;
	tool->hit = hit_sp;
	tool->clear = clear_sp;
	tool->refresh = refresh_sp;
	tool->stretch_mode = 0;
}

void		init_pl_toolbox(t_toolbox *tool)
{
	tool->move = move_pl;
	tool->rotate = rotate_pl;
	tool->stretch = stretch_pl;
	tool->hit = hit_pl;
	tool->clear = clear_pl;
	tool->refresh = refresh_pl;
	tool->stretch_mode = 0;
}

void		init_sq_toolbox(t_toolbox *tool)
{
	tool->move = move_sq;
	tool->rotate = rotate_sq;
	tool->stretch = stretch_sq;
	tool->hit = hit_sq;
	tool->clear = clear_sq;
	tool->refresh = refresh_sq;
	tool->stretch_mode = 0;
}

void		init_cy_toolbox(t_toolbox *tool)
{
	tool->move = move_cy;
	tool->rotate = rotate_cy;
	tool->stretch = stretch_cy;
	tool->hit = hit_cy;
	tool->clear = clear_cy;
	tool->refresh = refresh_cy;
	tool->stretch_mode = 0;
}

void		init_tr_toolbox(t_toolbox *tool)
{
	tool->move = move_tr;
	tool->rotate = rotate_tr;
	tool->stretch = stretch_tr;
	tool->hit = hit_tr;
	tool->clear = clear_tr;
	tool->refresh = refresh_tr;
	tool->stretch_mode = 0;
}

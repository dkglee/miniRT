/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stuff.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deulee <deulee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 17:21:50 by deulee            #+#    #+#             */
/*   Updated: 2021/03/23 17:28:27 by deulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	init_stuff(t_stuff *stuff)
{
	stuff->amb_light = NULL;
	stuff->cam = NULL;
	stuff->light = NULL;
	stuff->object = NULL;
	init_sp_toolbox(&stuff->sp_toolbox);
	init_pl_toolbox(&stuff->pl_toolbox);
	init_sq_toolbox(&stuff->sq_toolbox);
	init_cy_toolbox(&stuff->cy_toolbox);
	init_tr_toolbox(&stuff->tr_toolbox);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deulee <deulee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 16:47:42 by deulee            #+#    #+#             */
/*   Updated: 2021/03/26 16:43:18 by deulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void		init_render(t_render *render)
{
	init_info(&render->stuff);
	init_control(&render->control);
	init_trace(&render->trace);
}

void		start_render(t_render *render)
{
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deulee <deulee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 18:13:54 by deulee            #+#    #+#             */
/*   Updated: 2021/03/23 18:15:16 by deulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	init_trace(t_trace *trace)
{
	trace->width = 0;
	trace->height = 0;
	trace->mlx = NULL;
	trace->mlx_win = NULL;
	trace->img = NULL;
	trace->addr = NULL;
}

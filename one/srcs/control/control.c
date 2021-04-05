/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deulee <deulee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 17:56:33 by deulee            #+#    #+#             */
/*   Updated: 2021/03/23 18:07:41 by deulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void		init_control(t_control *control)
{
	control->mode = CAM_MODE;
	control->select_cam = NULL;
	contorl->select_light = NULL;
	contorl->select_object = NULL;
	control->save = false;
}

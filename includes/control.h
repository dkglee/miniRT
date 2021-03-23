/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deulee <deulee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 17:57:07 by deulee            #+#    #+#             */
/*   Updated: 2021/03/23 18:15:36 by deulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTROL_H
# define CONTROL_H

typedef	struct	s_control
{
	t_key		mode;
	t_cam		*select_cam;
	t_light		*select_light;
	t_object	*select_object;
	bool		save;
}				t_control;

void			init_control(t_control *control);

#endif

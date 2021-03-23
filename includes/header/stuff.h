/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stuff.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deulee <deulee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 17:28:38 by deulee            #+#    #+#             */
/*   Updated: 2021/03/23 18:15:57 by deulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STUFF_H
# define STUFF_H

typedef	struct	s_stuff
{
	t_vec		*amb_light;
	t_cam		*cam;
	t_light		*light;
	t_object	*object;
	t_toolbox	sp_toolbox;
	t_toolbox	pl_toolbox;
	t_toolbox	sq_toolbox;
	t_toolbox	cy_toolbox;
	t_toolbox	tr_toolbox;
}				t_stuff;

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deulee <deulee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 17:46:25 by deulee            #+#    #+#             */
/*   Updated: 2021/03/26 17:59:57 by deulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

typedef	struct	s_ray
{
	t_vec		origin;
	t_vec		orient;
	t_vec		point;
	t_vec		point_orient;
	double		time;
}				t_ray;



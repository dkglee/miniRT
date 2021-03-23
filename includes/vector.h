/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deulee <deulee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 12:42:33 by deulee            #+#    #+#             */
/*   Updated: 2021/03/17 12:46:11 by deulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

typedef struct	s_vec
{
	double		x;
	double		y;
	double		z;
}				t_vec;

t_vec			ft_vec_add(t_vec u, t_vec v);
t_vec			ft_vec_sub(t_vec u, t_vec v);
t_vec			ft_vec_cross(t_vec u, t_vec v);
t_vec			ft_vec_product(t_vec u, double scalar);
double			ft_vec_dot(t_vec u, t_vec v);
t_vec			ft_vec_set(double x, double y, double z);
t_vec			ft_vec_unit(t_vec u);

#endif

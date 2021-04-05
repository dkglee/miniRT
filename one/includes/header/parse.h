/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deulee <deulee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 18:21:55 by deulee            #+#    #+#             */
/*   Updated: 2021/03/23 19:12:37 by deulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

typedef	struct	s_parse
{
	t_render	*render;
	char		*line_gnl;
	char		**info;
	int			fd;
}				t_parse;

void			parse(t_render *render, int argc, char **argv);
void			clear_parse(t_parse *parse);
void			clear_info(char	**info);

int				is_valid_arg(t_render *render, int argc, char **argv);

#endif

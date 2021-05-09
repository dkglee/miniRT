/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deulee <deulee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 12:10:03 by deulee            #+#    #+#             */
/*   Updated: 2021/05/09 21:45:30 by deulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# define BUFFER_SIZE 1024

typedef struct		s_file
{
	int				fd;
	unsigned int	buff_size;
	char			buffer[BUFFER_SIZE];
	char			*backup;
	struct s_file	*next;
}					t_buff;

int					get_next_line(int fd, char **line);
int					find_next_line(char **line, t_buff *list);
int					make_line(char **line, t_buff *list);
int					make_backup(char *backupline, t_buff *list,
		unsigned int nsize);
char				*ft_strndup(char *src, unsigned int size);
int					backup_update(t_buff *list, unsigned int len);
void				clear_fd(t_buff **header);
void				del_fd(int fd, t_buff **header);
t_buff				*find_fd_or_make(int fd, t_buff **header);

#endif

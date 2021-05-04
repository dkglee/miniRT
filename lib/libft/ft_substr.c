/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deulee <deulee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 23:06:56 by deulee            #+#    #+#             */
/*   Updated: 2020/12/27 16:42:32 by deulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str_sub;
	size_t	s_len;

	s_len = ft_strlen(s);
	if (!s)
		return (0);
	if ((unsigned int)s_len < start)
		return (ft_strdup(""));
	if (0 == (str_sub = (char *)malloc(sizeof(char) * (len + 1))))
		return (0);
	ft_strlcpy(str_sub, s + start, len + 1);
	return (str_sub);
}

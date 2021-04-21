/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deulee <deulee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 22:10:11 by deulee            #+#    #+#             */
/*   Updated: 2020/12/25 13:18:04 by deulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	int		i;
	int		str_len;
	char	*str_tmp;

	i = 0;
	str_len = ft_strlen(str);
	if (0 == (str_tmp = (char *)malloc(sizeof(char) * (str_len + 1))))
		return (0);
	while (str[i])
	{
		str_tmp[i] = str[i];
		i++;
	}
	str_tmp[i] = '\0';
	return (str_tmp);
}

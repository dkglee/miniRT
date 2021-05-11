/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deulee <deulee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 15:51:42 by deulee            #+#    #+#             */
/*   Updated: 2021/05/11 21:10:12 by deulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	**mem_error(char **arr)
{
	int		i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (0);
}

int		mem_trim(char *tmp)
{
	free(tmp);
	return (0);
}

int		check_split(char c, char *cut)
{
	int		i;

	i = 0;
	while (cut[i])
	{
		if (c == cut[i])
			return (1);
		i++;
	}
	return (0);
}

int		arr_size(char *str, char *cut)
{
	int		size;
	int		i;
	char	*tmp;

	size = 1;
	i = 0;
	tmp = ft_strtrim(str, cut);
	if (tmp == 0 || tmp[i] == '\0')
		return (mem_trim(tmp));
	while (tmp[i])
	{
		if (check_split(tmp[i], cut))
			size++;
		while (check_split(tmp[i], cut))
			i++;
		i++;
	}
	free(tmp);
	return (size);
}

char	**ft_split_str(char *str, char *cut)
{
	char	**arr;
	int		i;
	int		k;
	int		len;

	i = 0;
	k = 0;
	if (0 == (arr = (char **)malloc(sizeof(char *) * (arr_size(str, cut) + 1))))
		return (0);
	while (str[i] && k < arr_size(str, cut))
	{
		len = 0;
		while (check_split(str[i], cut))
			i++;
		while (!check_split(str[i], cut))
		{
			len++;
			i++;
		}
		if (0 == (arr[k] = (char *)malloc(sizeof(char) * (len + 1))))
			return (mem_error(arr));
		ft_strlcpy(arr[k++], &str[i - len], len + 1);
	}
	arr[k] = 0;
	return (arr);
}

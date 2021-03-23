/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deulee <deulee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 15:09:39 by deulee            #+#    #+#             */
/*   Updated: 2020/12/23 19:42:19 by deulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dest, int c, size_t n)
{
	size_t			i;
	unsigned char	set;
	unsigned char	*dst_tmp;

	i = 0;
	dst_tmp = dest;
	set = c;
	while (i++ < n)
		*dst_tmp++ = set;
	return (dest);
}

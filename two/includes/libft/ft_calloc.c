/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deulee <deulee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 19:43:30 by deulee            #+#    #+#             */
/*   Updated: 2020/12/23 22:09:33 by deulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*memarr;

	if (0 == (memarr = malloc(nmemb * size)))
		return (0);
	ft_bzero(memarr, (nmemb * size));
	return (memarr);
}

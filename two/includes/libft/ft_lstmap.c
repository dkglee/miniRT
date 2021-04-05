/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deulee <deulee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 23:34:38 by deulee            #+#    #+#             */
/*   Updated: 2020/12/29 23:47:35 by deulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*output;
	t_list	*tmp;

	if (lst == 0 || f == 0)
		return (0);
	output = NULL;
	while (lst)
	{
		if (0 != (tmp = ft_lstnew((*f)(lst->content))))
		{
			ft_lstadd_back(&output, tmp);
			tmp = tmp->next;
			lst = lst->next;
			continue ;
		}
		ft_lstclear(&output, del);
		return (NULL);
	}
	return (output);
}

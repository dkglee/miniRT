/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deulee <deulee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 18:26:15 by deulee            #+#    #+#             */
/*   Updated: 2021/03/25 18:33:25 by deulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_object	*add_object(t_object **head, void *obj, t_toolbox *toolbox)
{
	t_object	*new;

	if (obj == NULL)
		return (NULL);
	if (NULL == (new = (t_object *)malloc(sizeof(t_object))))
		return (NULL);
	new->object = obj;
	new->toolbox = toolbox;
	new->stretch_mode = 0;
	new->next = *head;
	*head = new;
	return (new);
}

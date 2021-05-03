/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils_more_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deulee <deulee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 17:05:46 by deulee            #+#    #+#             */
/*   Updated: 2021/05/03 17:08:34 by deulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_addcam_back(t_cam **head, t_cam *new)
{
	t_cam	*fin;

	if (!(head) || !(new))
		return ;
	if (*head == NULL)
	{
		*head = new;
		return ;
	}
	fin = *head;
	while (fin->next != NULL)
		fin = fin->next;
	new->next = fin->next;
	fin->next = new;
}

void	ft_addlight_back(t_light **head, t_light *new)
{
	t_light	*fin;

	if (!(head) || !(new))
		return ;
	if (*head == NULL)
	{
		*head = new;
		return ;
	}
	fin = *head;
	while (fin->next != NULL)
		fin = fin->next;
	new->next = fin->next;
	fin->next = new;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deulee <deulee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 14:32:08 by deulee            #+#    #+#             */
/*   Updated: 2021/05/16 14:32:59 by deulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	name_free(char **s1, char **s2, char **s3)
{
	free(*s1);
	free(*s2);
	free(*s3);
	*s1 = NULL;
	*s2 = NULL;
	*s3 = NULL;
	s1 = NULL;
	s2 = NULL;
	s3 = NULL;
}

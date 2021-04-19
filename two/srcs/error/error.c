/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deulee <deulee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 13:25:15 by deulee            #+#    #+#             */
/*   Updated: 2021/04/16 16:41:52 by deulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	error(char *str, void (*func)(void *), void *arg)
{
	if (str == NULL)
		printf("%s\n", strerror(errno));
	else
		printf("%s\n", str);
	if (func == NULL)
		exit(0);
	func(arg);
	exit(0);
}

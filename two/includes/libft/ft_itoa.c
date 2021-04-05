/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deulee <deulee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 17:27:10 by deulee            #+#    #+#             */
/*   Updated: 2020/12/30 23:44:51 by deulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_cal_len(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		i++;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_min(long num, char *str, int len)
{
	str[0] = '-';
	while (len-- > 1)
	{
		str[len] = '0' + num % 10;
		num /= 10;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	int		len;
	long	num;
	char	*str;

	num = n;
	len = ft_cal_len(n);
	if (0 == (str = (char *)malloc(sizeof(char) * len + 1)))
		return (0);
	if (num < 0)
	{
		num *= -1;
		str = ft_min(num, str, len);
		str[len] = '\0';
		return (str);
	}
	str[len] = '\0';
	while (len--)
	{
		str[len] = '0' + num % 10;
		num /= 10;
	}
	return (str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 14:36:54 by exam              #+#    #+#             */
/*   Updated: 2017/11/12 14:05:04 by ahrytsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_getsize(int value, int base)
{
	int	res;

	res = (value < 0 && base == 10) ? 3 : 2;
	while (value >= base || value <= -base)
	{
		value /= base;
		res++;
	}
	return (res);
}

char	*ft_itoa_base(int value, int base)
{
	long	val;
	int		size;
	char	*res;

	val = value;
	size = ft_getsize(value, base);
	if (!(res = (char*)malloc(sizeof(char) * size--)))
		return (NULL);
	res[size--] = '\0';
	if (base == 10 && value < 0)
		res[0] = '-';
	val *= val < 0 ? -1 : 1;
	while (val >= base)
	{
		res[size] = (val % base >= 10) ? val % base + 'A' - 10 :
			val % base + '0';
		val /= base;
		size--;
	}
	res[size] = (val % base >= 10) ? val % base + 'A' - 10 :
		val % base + '0';
	return (res);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 10:01:43 by exam              #+#    #+#             */
/*   Updated: 2017/12/19 11:24:29 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_ascii(unsigned char *str, size_t size, size_t i)
{
	size_t	st;

	st = i - 15;
	while (st <= i && st < size)
	{
		if (str[st] > 31 && str[st] < 127)
			write(1, str + st, 1);
		else
			write(1, ".", 1);
		st++;
	}
	write(1, "\n", 1);
}

void	print_memory(const void *addr, size_t size)
{
	size_t			i;
	unsigned char	tmp;
	unsigned char	*adr;
	size_t			map_size;

	adr = (unsigned char*)addr;
	i = 0;
	map_size = (size % 16) ? (size + 16 - size % 16) : size;
	while (i < map_size)
	{
		if (i < size)
		{
			tmp = adr[i] / 16;
			tmp = tmp > 9 ? tmp - 10 + 'a' : tmp + '0';
			write(1, &tmp, 1);
			tmp = adr[i] % 16;
			tmp = tmp > 9 ? tmp - 10 + 'a' : tmp + '0';
			write(1, &tmp, 1);
		}
		else
			write(1, "  ", 2);
		(i % 2) ? write(1, " ", 1) : 0;
		(!((i + 1) % 16)) ? print_ascii(adr, size, i) : 0;
		i++;
	}
}

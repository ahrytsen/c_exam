/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 16:27:47 by exam              #+#    #+#             */
/*   Updated: 2017/11/10 22:47:12 by ahrytsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_ascii(const unsigned char *adr, int size)
{
	int i;

	i = size;
	while (i < 16)
	{
		write(1, "  ", 2);
		if (i % 2)
			write(1, " ", 1);
		i++;
	}
	while (size--)
	{
		if (*adr > 31 && *adr < 127)
			write(1, adr, 1);
		else
			write(1, ".", 1);
		adr++;
	}
}

void	print_memory(const void *addr, size_t size)
{
	const unsigned char	*a;
	unsigned char		tmp;
	int					i;

	a = addr;
	while (size)
	{
		i = 0;
		while (i < 16 && (size - i))
		{
			tmp = a[i] / 16 >= 10 ? a[i] / 16 + 'a' - 10 : a[i] / 16 + '0';
			write(1, &tmp, 1);
			tmp = a[i] % 16 >= 10 ? a[i] % 16 + 'a' - 10 : a[i] % 16 + '0';
			write(1, &tmp, 1);
			if (i % 2)
				write(1, " ", 1);
			i++;
		}
		print_ascii(a, i);
		write(1, "\n", 1);
		a += i;
		size -= i;
	}
}

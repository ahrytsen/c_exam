/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_wstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 14:04:14 by exam              #+#    #+#             */
/*   Updated: 2017/11/10 14:32:29 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

unsigned long	ft_strlen(char *s)
{
	unsigned long i;

	i = 0;
	while (*s++)
		i++;
	return (i);
}

void			ft_print_word(char *s)
{
	while (*s && *s != ' ')
		write(1, s++, 1);
}

int				main(int ac, char **av)
{
	unsigned long	str_size;

	if (ac == 2 && av[1][0])
	{
		str_size = ft_strlen(av[1]) - 1;
		while (str_size)
		{
			if (av[1][str_size - 1] == ' ')
			{
				ft_print_word(av[1] + str_size);
				write(1, " ", 1);
			}
			else if (str_size - 1 == 0)
				ft_print_word(av[1] + str_size - 1);
			str_size--;
		}
	}
	write(1, "\n", 1);
}

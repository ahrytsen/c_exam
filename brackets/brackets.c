/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brackets.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 10:04:29 by exam              #+#    #+#             */
/*   Updated: 2017/11/21 11:48:58 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	get_size(char *str)
{
	int i;

	i = 0;
	while (*str)
	{
		if (*str == 40 || *str == 123 || *str == 91)
			i++;
		str++;
	}
	return (i);
}

int	brackets(char *str, int size)
{
	char	stack[size];
	int		i;
	char	tmp;

	i = 0;
	while (*str)
	{
		if (*str == 40 || *str == 123 || *str == 91)
			stack[i++] = *str;
		else if (*str == 41 || *str == 125 || *str == 93)
		{
			if (i)
			{
				tmp = *str - stack[--i];
				if (tmp > 3 || tmp < 1)
					return (0);
			}
			else
				return (0);
		}
		str++;
	}
	if (i)
		return (0);
	return (1);
}

int	main(int ac, char **av)
{
	int size;

	if (ac == 1)
		write(1, "\n", 1);
	while (--ac)
	{
		size = get_size(*++av);
		if (brackets(*av, size))
			write(1, "OK\n", 3);
		else
			write(1, "Error\n", 6);
	}
}

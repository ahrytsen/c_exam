/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_alpha.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 12:40:28 by exam              #+#    #+#             */
/*   Updated: 2017/11/28 13:25:16 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_count(int *arr, char *str)
{
	while (*str)
	{
		if ((*str >= 'a' && *str <= 'z')
			|| (*str >= 'A' && *str <= 'Z'))
			(*str >= 'a' && *str <= 'z') ? arr[*str - 'a']++
				: arr[*str - 'A']++;
		str++;
	}
}

void	ft_print(int *arr, char *str)
{
	int i;

	i = 0;
	while (*str)
	{
		if ((*str >= 'a' && *str <= 'z') || (*str >= 'A' && *str <= 'Z'))
		{
			if (*str >= 'a' && *str <= 'z' && arr[*str - 'a'])
			{
				i++ ? printf(", ") : 0;
				printf("%d%c", arr[*str - 'a'], *str);
				arr[*str - 'a'] = 0;
			}
			else if (*str >= 'A' && *str <= 'Z' && arr[*str - 'A'])
			{
				i++ ? printf(", ") : 0;
				printf("%d%c", arr[*str - 'A'], *str + ' ');
				arr[*str - 'A'] = 0;
			}
		}
		str++;
	}
}

int		main(int ac, char **av)
{
	int i;
	int arr[26];

	i = 0;
	while (i < 26)
		arr[i++] = 0;
	if (ac == 2)
	{
		ft_count(arr, av[1]);
		ft_print(arr, av[1]);
	}
	printf("\n");
}

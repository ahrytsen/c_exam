/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 10:56:18 by exam              #+#    #+#             */
/*   Updated: 2017/11/14 12:11:28 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <stdlib.h>
# include <stdio.h>

typedef struct s_stack t_stack;

struct  s_stack
{
	int		operand;
	struct s_stack	*prew;
};

void			ft_push(t_stack **stack, int op);
int				ft_pop(t_stack **stack);
void			rpn_calc(char *str);
int				ft_math(int op1, int op2, char operator);

#endif

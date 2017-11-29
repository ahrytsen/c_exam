/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 10:56:01 by exam              #+#    #+#             */
/*   Updated: 2017/11/14 12:07:43 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_push(t_stack **stack, int op)
{
	t_stack	*tmp;

	tmp = (t_stack*)malloc(sizeof(t_stack));
	tmp->operand = op;
	tmp->prew = *stack;
	*stack = tmp;
}

int		ft_pop(t_stack **stack)
{
	t_stack	*tmp;
	int		op;

	op = 0;
	tmp = *stack;
	if (stack)
	{
		op = (*stack)->operand;
		*stack = (*stack)->prew;
	}
	free(tmp);
	return (op);
}

int		ft_math(int op1, int op2, char operator)
{
	if (operator == '+')
		return (op1 + op2);
	if (operator == '-')
        return (op1 - op2);
	if (operator == '*')
        return (op1 * op2);
    if (operator == '/')
        return (op1 / op2);
	return (op1 % op2);
}

void	rpn_calc(char *str)
{
	t_stack	*stack;
	int		tmp;

	stack = NULL;
	while (*str)
	{
		if ((*str >= '0' && *str <= '9') || ((*str == '+' || *str == '-') && (*(str + 1) >= '0' && *(str + 1) <= '9')))
		{
			ft_push(&stack, atoi(str++));
			while (*str >= '0' && *str <= '9')
				str++;
		}
		else if (*str == '+' || *str == '-' || *str == '/' || *str == '*' || *str == '%')
		{
			if (!stack)
			{
				printf("Error");
				return ;
			}
			else if (!stack->prew)
			{
				printf("Error");
				return;
			}
			else if ((*str == '/' || *str == '%') && !stack->operand)
			{
				printf("Error");
                return;
			}
			tmp = ft_pop(&stack);
			stack->operand = ft_math(stack->operand, tmp, *str);
		}
		else if (*str != ' ')
		{
			printf("Error");
			return ;
		}
		str++;
	}
	if (stack && stack->prew == NULL)
		printf("%d", stack->operand);
	else
		printf("Error");
}

int		main(int ac, char **av)
{
	if (ac == 2)
		rpn_calc(av[1]);
	else
		printf("Error");
	printf("\n");
}

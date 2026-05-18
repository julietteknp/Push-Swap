/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_list_manip_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkonop <jkonop@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 17:05:20 by jkonop            #+#    #+#             */
/*   Updated: 2026/05/18 19:24:16 by jkonop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>
#include "header.h"

t_stack    *second_last(t_stack *stack)
{
	t_stack	*next;
	if (stack == NULL)
		return (NULL);

	next = stack->next;
	while (next->next != NULL)
	{
		stack = stack->next;
		next = stack->next;
	}
	return (stack);
}

int	is_sorted(t_stack *stack)
{
	if (stack == NULL || stack->next == NULL)
		return (1);
	if (stack->value > (stack->next)->value)
	{
		while (stack->next != NULL)
		{
			if (stack->value < (stack->next)->value)
				return (0);
			else
				stack = stack->next;
		}
	}
	if (stack->value < (stack->next)->value)
	{
		while (stack->next != NULL)
		{	
			if (stack->value > (stack->next)->value)
				return (0);
			else 
				stack = stack->next;
		}
	}
	return (1);
}

t_stack *new_node(int value)
{
        t_stack *node;
        node = malloc(sizeof(t_stack));
        if (node == NULL)
                return (NULL);
        node->value = value;
        node->next = NULL;
        return (node);
}

void    add_back(t_stack **stack, t_stack *new)
{
        t_stack *tmp;

        if (*stack == NULL)
        {
                *stack = new;
                return ;
        }
        tmp = *stack;
        while (tmp->next != NULL)
                tmp = tmp->next;
        tmp->next = new;
        new->next = NULL;
}

int     fake_atoi(char *argv)
{
        int     result;
        int     sign;

        result = 0;
        sign = 1;
        if (*argv ==  '-' || *argv == '+')
        {
                if (*argv == '-')
                        sign = -1;
                argv++;
        }
        while (*argv)
        {
                result = result * 10 + *argv - '0';
                argv++;
        }
        return (result * sign);
}

void    print_list(t_stack *stack)
{
        if (stack == NULL)
                return ;
        while (stack != NULL)
        {
                printf("%d", stack->value);
                stack = stack->next;
        }
}

int	main(int argc, char **argv)
{
	t_stack	*current;
	if (argc < 3)
		return (0);
	argv++;
	current = new_node(fake_atoi(*argv));
	argv++;
	while (*argv)
	{
		add_back(&current, new_node(fake_atoi(*argv)));
		argv++;
		//printf("%d", current->value);
	}
	//print_list(current);
	//printf("%d", second_last(current)->value);
	printf("%d", is_sorted(current));	
	return (0);
}

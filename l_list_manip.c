/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_list_manip.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkonop <jkonop@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 17:29:19 by jkonop            #+#    #+#             */
/*   Updated: 2026/05/18 12:48:34 by jkonop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include "header.h"

t_stack	*new_node(int value)
{
	t_stack *node;
	node = malloc(sizeof(t_stack));
	if (node == NULL)
		return (NULL);
	node->value = value;
	node->next = NULL;
	return (node);
}

t_stack	*add_front(t_stack **stack, t_stack *new)
{
	new->next = *stack;
	*stack = new;
	return (*stack);	
}

void	add_back(t_stack **stack, t_stack *new)
{
	t_stack	*tmp;

	if (stack == NULL)
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
int	fake_atoi(char *argv)
{
	int	result;
	int	sign;

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

t_stack	*last_node(t_stack *stack)
{
	if (stack == NULL)
		return (NULL);
	while (stack->next != NULL)
	{
		stack = stack->next;
	}
	return (stack);
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

int	main (int argc, char **argv)
{
	if (argc < 3)
	       return (0);
	argv++;
	t_stack *init = new_node(5);
	//printf("%d\n", init->value);
	//t_stack *start = init;
	while (*argv)
	{	
		t_stack *node = new_node(fake_atoi(*argv));
		if (node == NULL)
			return (1);
		add_back(&init, node);
		argv++;
	}
	//t_stack *last = last_node(start);
	print_list(init);
	return (0);
}

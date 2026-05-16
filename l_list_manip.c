/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_list_manip.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkonop <jkonop@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 17:29:19 by jkonop            #+#    #+#             */
/*   Updated: 2026/05/16 15:25:21 by jkonop           ###   ########.fr       */
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

int	main (int argc, char **argv)
{
	if (argc < 3)
	       return (0);
	argv++;
	t_stack *init = new_node(0);
	printf("%d\n", init->value);
	while (*argv)
	{	
		t_stack *node = new_node(fake_atoi(*argv));
		if (node == NULL)
			return (1);
		add_front(&init, node);
		printf("%d\n", init->value);
		argv++;
	}
	return (0);
}

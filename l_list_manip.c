/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_list_manip.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkonop <jkonop@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 17:29:19 by jkonop            #+#    #+#             */
/*   Updated: 2026/05/26 11:20:23 by jkonop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
int	stack_size(t_stack *stack)
{
	int	size;

	if (stack == NULL)
		return (0);
	else
	{
		size = 1;
		while (stack != NULL)
		{
			size++;
			stack = stack->next;
		}
	}
	return (size);
}
int	safe_atoi(char *argv)
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

t_stack    *second_last(t_stack *stack)
{
        t_stack *next;
        if (stack == NULL || stack->next == NULL)
                return (NULL);

        next = stack->next;
        while (next->next != NULL)
        {
                stack = stack->next;
                next = stack->next;
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

void	clear_stack(t_stack **stack)
{
	t_stack	*tmp;

	if (*stack == NULL)
		return;
	while(*stack != NULL)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	*stack = NULL;
}	

int ascending(int a, int b)
{
    return (a <= b);
}

t_stack *sort_list(t_stack* lst, int (*cmp)(int, int))
{
	t_stack *head;
	int tmp;

	head = lst;
	if (head == NULL || head->next == NULL)
	{
		return (NULL);
	}
	while (head != NULL && head->next != NULL)
	{
		if (cmp(head->value, head->next->value) == 0)
		{
			tmp = head->value;
			head->value = head->next->value;
			head->next->value = tmp;
			head = lst;
		}
		else
			head = head->next;
	}
	return (lst);
}

/*int	main (int argc, char **argv)
{
	if (argc < 3)
	       return (0);
	argv++;
	t_stack *init = new_node(5);
	//printf("%d\n", init->value);
	//t_stack *start = init;
	while (*argv)
	{	
		t_stack *node = new_node(safe_atoi(*argv));
		if (node == NULL)
			return (1);
		add_back(&init, node);
		argv++;
	}
	//t_stack *last = last_node(start);
	//print_list(init);
	//printf("%d", stack_size(init));
	sort_list(init, ascending);
	while (init != NULL)
	{
		printf("%d\n", init->value);
		init = init->next;
	}
	return (0);*/

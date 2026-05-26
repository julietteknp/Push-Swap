/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkonop <jkonop@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 15:46:05 by jkonop            #+#    #+#             */
/*   Updated: 2026/05/21 15:20:16 by jkonop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "header.h"

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

t_stack *add_front(t_stack **stack, t_stack *new)
{
        new->next = *stack;
        *stack = new;
        return (*stack);
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

void swap(t_stack **stack)
{
        int     tmp;

        if (!stack || !*stack || !(*stack)->next)
                return ;
        tmp = (*stack)->value;
        (*stack)->value = (*stack)->next->value;
        (*stack)->next->value = tmp;
}

void    push(t_stack **dest, t_stack **src)
{
        t_stack *node;

	if (!src || !*src)
    		return ;
        node = *src;
	(*src) = (*src)->next;
	node->next = NULL;
        add_front(dest, node);
}

void    rotate(t_stack **stack)
{
	if (stack == NULL || *stack == NULL)
		return;
        if ((*stack)->next == NULL)
                return;
	t_stack *new_last = *stack;
	*stack = (*stack)->next;
	new_last->next = NULL;
	add_back(stack, new_last);
}
void    reverse_rotate(t_stack **stack)
{	
	if (!stack || !*stack || !(*stack)->next)
        	return ;
	t_stack *sec_last = second_last(*stack);
	t_stack *new_first = sec_last->next;
	sec_last->next = NULL;
	add_front(stack, new_first);
}

void    print_list(t_stack *stack)
{
        if (stack == NULL)
                return ;
        while (stack != NULL)
        {
                printf("%d\n", stack->value);
                stack = stack->next;
        }
}

int     stack_size(t_stack *stack)
{
        int     size;

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

t_stack	*dup_list(t_stack *list)
{
	t_stack *copy;
	t_stack *copy_start;
	copy = NULL;
	copy_start = copy;
	while (list != NULL)
	{
		add_back(&copy, new_node(list->value));
		list = list->next;
	}
	return(copy_start);
}
/*int     main (int argc, char **argv)
{
        if (argc < 3)
               return (0);
        argv++;
        t_stack *init = new_node(fake_atoi(*argv));
	argv++;
        //t_stack *start = init;
        while (*argv)
        {
                t_stack *node = new_node(fake_atoi(*argv));
                if (node == NULL)
                        return (1);
                add_back(&init, node);
                argv++;
        }
        print_list(init);
	//swap(&init);
	//print_list(init);
	//t_stack *dst = dup_list(init);
	t_stack *a = init;
	reverse_rotate(&a);
	printf("%s", "la liste a after reverse=\n");
        print_list(a);
	rotate(&a);
	printf("%s", "la liste a after rotate=\n");
        print_list(a);
	t_stack *b = NULL;
	push(&b, &a);
	printf("%s", "la liste a=\n");
	print_list(a);
	printf("%s", "la liste b=\n");
	print_list(b);
	push(&b, &a);
        printf("%s", "la liste a=\n");
        print_list(a);
        printf("%s", "la liste b=\n");
        print_list(b);
        return (0);
}*/

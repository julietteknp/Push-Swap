/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_op.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkonop <jkonop@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 11:08:55 by jkonop            #+#    #+#             */
/*   Updated: 2026/05/28 17:14:49 by jkonop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "header.h"

void    sa(t_stack **a)
{
    swap(a);
    write(1, "sa\n", 3);
}

void    sb(t_stack **b)
{
    swap(b);
    write(1, "sb\n", 3);
}

void    ss(t_stack **a, t_stack **b)
{
    swap(a);
    swap(b);
    write(1, "ss\n", 3);
}

void    pa(t_stack **a, t_stack **b)
{
    push(a, b);
    write(1, "pa\n", 3);
}

void    pb(t_stack **a, t_stack **b)
{
    push(b, a);
    write(1, "pb\n", 3);
}

void    ra(t_stack **a)
{
    rotate(a);
    write(1, "ra\n", 3);
}

void    rb(t_stack **b)
{
    rotate(b);
    write(1, "rb\n", 3);
}

void    rr(t_stack **a, t_stack **b)
{
    rotate(a);
    rotate(b);
    write(1, "rr\n", 3);
}

void    rra(t_stack **a)
{
    reverse_rotate(a);
    write(1, "rra\n", 4);
}

void    rrb(t_stack **b)
{
    reverse_rotate(b);
    write(1, "rrb\n", 4);
}

void    rrr(t_stack **a, t_stack **b)
{
    reverse_rotate(a);
    reverse_rotate(b);
    write(1, "rrr\n", 4);
}

/*int main(int argc, char **argv)
{
    if (argc != 3)
        return (0);
    t_stack *list_a = NULL;
    t_stack *list_b = NULL;
    int n;
    while(*argv[1])
    {
        n = *argv[1] - '0';
        t_stack *node = new_node(n);
        if (node == NULL)
            return (1);
        add_back(&list_a, node);
        argv[1]++;
    }
    while(*argv[2])
    {
        n = *argv[2] - '0';
        t_stack *node = new_node(n);
        if (node == NULL)
            return (1);
        add_back(&list_b, node);
        argv[2]++;
    }
    print_list(list_a);
    print_list(list_b);
    printf("%s","test swap\n");
    //sa(&list_a);
    //sb(&list_b);
    //ss(&list_a, &list_b);
    //printf("%s","test push\n");
    //pb(&list_a, &list_b);
    //pa(&list_a, &list_b);
    //printf("%s","test rotate\n");
    //ra(&list_a);
    //rb(&list_b);
    //rr(&list_a, &list_b);
    //printf("%s","test reverse_rotate\n");
    //rra(&list_a);
    //rrb(&list_b);
    rrr(&list_a, &list_b);
    print_list(list_a);
    printf("%c", '\n');
    print_list(list_b);
    clear_stack(&list_a);
    clear_stack(&list_b);
    return (0);
}*/
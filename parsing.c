/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkonop <jkonop@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 17:29:19 by jkonop            #+#    #+#             */
/*   Updated: 2026/05/28 17:51:08 by jkonop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include "header.h"

int error_clean(t_stack **a)
{
    write(2, "Error\n", 6);
    clear_stack(a);
    return (1);
}

int is_algo_flag(char *s)
{
    if (ft_strcmp(s, "--simple") == 0)
        return (1);
    if (ft_strcmp(s, "--medium") == 0)
        return (1);
    if (ft_strcmp(s, "--complex") == 0)
        return (1);
    if (ft_strcmp(s, "--adaptive") == 0)
        return (1);
    return (0);
}

int get_algo(char *s)
{
    if (ft_strcmp(s, "--simple") == 0)
        return ('S');
    if (ft_strcmp(s, "--medium") == 0)
        return ('M');
    if (ft_strcmp(s, "--complex") == 0)
        return ('C');
    if (ft_strcmp(s, "--adaptive") == 0)
        return ('A');
    return (0);
}

int is_valid_int(char *s)
{
    if (*s == '-' ||*s == '+')
        s++;
    if(*s < '0' || *s > '9')
            return(0);
    while(*s)
    {
        if(*s < '0' || *s > '9')
            return(0);
        s++;
    }
    return(1);
}

int has_duplicate(t_stack *a, int value)
{
    while (a != NULL)
    {
        if (a->value == value)
            return(1);
        a = a->next;
    }
    return (0);
}

int add_number(char *arg, t_stack **a)
{
    long    n;
    int     value;
    t_stack *node;

    if (!is_valid_int(arg))
        return (error_clean(a));
    n = ft_safe_atoi(arg);
    if (n < INT_MIN || n > INT_MAX)
        return (error_clean(a));
    value = (int)n;
    if (has_duplicate(*a, value))
        return (error_clean(a));
    node = new_node(value);
    if (!node)
        return (error_clean(a));
    add_back(a, node);
    return (0);
}

int parse_numbers(char **argv, int i, t_stack **a)
{
    while (argv[i])
    {
        if (add_number(argv[i], a))
            return (1);
        i++;
    }
    return (0);
}

int parse_args(char **argv, t_stack **a, int *bench, int *algo)
{
    int i;

    i = 1;
    *bench = 0;
    *algo = 'A';
    if (argv[i] && ft_strcmp(argv[i], "--bench") == 0)
    {
        *bench = 1;
        i++;
    }
    if (!argv[i])
        return (error_clean(a));
    if (argv[i] && is_algo_flag(argv[i]))
    {
        *algo = get_algo(argv[i]);
        i++;
    }
    if (!argv[i])
        return (error_clean(a));
    return (parse_numbers(argv, i, a));
}
    
int main(int argc, char **argv)
{
    int     bench;
    int     algo;
    t_stack *a;
    t_stack *b;

    if (argc < 2)
        return (0);
    a = NULL;
    if (parse_args(argv, &a, &bench, &algo))
        return (1);
    b = NULL;
    //print_list_value(a);
    set_index(a);
    //printf("%c", '\n');
    //print_list_index(a);
    //printf("%c", '\n');
    put_a_in_b(&a, &b);
    printf("%c", '\n');
    //print_list_value(a);
    //print_list_value(b);
    put_b_in_a(&a, &b);
    printf("%c", '\n');
    print_list_value(a);
    /*printf("%d", stack_size(a));
    printf("%c", '\n');
    printf("%d", number_of_chunk(a));
    printf("%c", '\n');
    printf("%d", size_of_chunk(a));
    print_chunk(a);*/

    // algo de tri

    clear_stack(&a);
    return (0);
}

// ./pushswap --bench --algo 123 456 5 7 9 "4 6 5"  



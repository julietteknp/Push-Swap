/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkonop <jkonop@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 17:29:19 by jkonop            #+#    #+#             */
/*   Updated: 2026/05/26 15:52:06 by jkonop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <limits.h>

int error_clean(t_stack **a)
{
    write(2, "Error\n", 6);
    clear_stack(&a);
    return (1);
}

int is_algo_flag(char *s)
{
    if (strcmp(s, "--simple") == 0)
        return (1);
    if (strcmp(s, "--medium") == 0)
        return (1);
    if (strcmp(s, "--complex") == 0)
        return (1);
    if (strcmp(s, "--adaptive") == 0)
        return (1);
    return (0);
}

int get_algo(char *s)
{
    if (strcmp(s, "--simple") == 0)
        return (SIMPLE);
    if (strcmp(s, "--medium") == 0)
        return (MEDIUM);
    if (strcmp(s, "--complex") == 0)
        return (COMPLEX);
    if (strcmp(s, "--adaptive") == 0)
        return (ADAPTIVE);
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

int parse_args(char **argv, t_stack **a, int *bench, int *algo)
{
    int i;
    long    n;
    int value;
    t_stack  *node;
    
    i = 1;
    *bench = 0;
    *algo = ADAPTIVE;
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
    while (argv[i])
    {
        if (!is_valid_int(argv[i]))
            return (error_clean(a));
        n = safe_atoi(argv[i]);
        if (n < INT_MIN || n > INT_MAX)
            return (error_clean(a));
        value = (int)n;
        if (has_duplicate(*a, value))
            return (error_clean(a));
        node = new_node(value);
        if (!node)
            return (error_clean(a));
        add_back(a, node);
        i++;
    }
    return (0);
}

int main(int argc, char **argv)
{
    int     bench;
    int     algo;

    t_stack *a;
    if (argc < 2)
        return (0);
    a = NULL;
    if (parse_args(argv, &a, &bench, &algo))
        return (1);

    /* ici : is_sorted / choix algo / tri */

    clear_stack(&a);
    return (0);
}

./pushswap --bench --algo 123 456 5 7 9 "4 6 5"  
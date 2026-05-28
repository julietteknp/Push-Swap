/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkonop <jkonop@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 17:29:29 by jkonop            #+#    #+#             */
/*   Updated: 2026/05/28 17:43:35 by jkonop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define HEADER_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_stack
{
    int	value;	
    int index;	
    struct s_stack *next;
} t_stack;

/* utils */
int     ft_safe_atoi(char *argv);
int     ft_strcmp(const char *s1, const char *s2);

/* stack utils */
t_stack    *new_node(int value);
void        add_back(t_stack **stack, t_stack *new);
t_stack     *add_front(t_stack **stack, t_stack *new);
t_stack    *last_node(t_stack *stack);
int         stack_size(t_stack *stack);
void        clear_stack(t_stack **stack);
void        print_list_value(t_stack *stack);
void        print_list_index(t_stack *stack);
t_stack     *sort_list(t_stack* lst, int (*cmp)(int, int));

/* operations */
void        swap(t_stack **stack);
void        push(t_stack **dest, t_stack **src);
void        rotate(t_stack **stack);
void        reverse_rotate(t_stack **stack);

/* push_swap operations */
void        sa(t_stack **a);
void        sb(t_stack **b);
void        ss(t_stack **a, t_stack **b);

void        pa(t_stack **a, t_stack **b);
void        pb(t_stack **a, t_stack **b);

void        ra(t_stack **a);
void        rb(t_stack **b);
void        rr(t_stack **a, t_stack **b);

void        rra(t_stack **a);
void        rrb(t_stack **b);
void        rrr(t_stack **a, t_stack **b);

/* parsing */
int error_clean(t_stack **a);
int is_algo_flag(char *s);
int get_algo(char *s);
int is_valid_int(char *s);
int has_duplicate(t_stack *a, int value);
int add_number(char *arg, t_stack **a);
int parse_numbers(char **argv, int i, t_stack **a);
int parse_args(char **argv, t_stack **a, int *bench, int *algo);

/* index */
void    set_index(t_stack *a);

#endif

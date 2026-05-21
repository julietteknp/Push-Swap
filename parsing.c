/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkonop <jkonop@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 17:29:19 by jkonop            #+#    #+#             */
/*   Updated: 2026/05/21 17:03:10 by jkonop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int main(int argc, char **argv)
{
    t_stack *list_a = NULL;
    char **tokens;
    
    if (argc < 2)
        return(0);
    while(*argv)
    {
        tokens = split(*argv);
        while(*tokens)
        {
            value = fake_atoi(*tokens);
            check_int_range(value);
            check_duplicate(value);
            add_back(&list_a, new_node(value));
            token++;
        }
        free tokens;
    }   
}
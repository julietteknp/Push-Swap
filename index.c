#include <stddef.h>
#include "header.h"

void    set_index(t_stack *a)
{
    int rank;
    t_stack *a_next;

    a_next = NULL;
    while (a != NULL)
    {
        rank = 0;
        a_next = a->next;
        while (a_next != NULL)
        {
            if (a_next->value < a->value)
                rank++;
            a_next = a_next->next;
        }
        a->index = rank;
        a=a->next;
    }
}
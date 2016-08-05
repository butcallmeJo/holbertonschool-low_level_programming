#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

/* The function 'print_stack' is provided */
void print_stack(const Stack *);

int push_stack(Stack **, char *);
void free_stack(Stack *);

int main(int ac, char **av)
{
        Stack *stack;
        int i;

        stack = NULL;
        i = 0;
        while (i < ac)
        {
                push_stack(&stack, av[i]);
                ++i;
        }
        print_stack(stack);
		free_stack(stack);
        return (0);
}

#include "stack.h"
#include <stdlib.h>

/**
 * free_stack -
 * @stack:
 * Description:
 */
void free_stack(Stack *stack)
{
	Stack *temp = stack;
	while (stack != NULL) {
		free(stack->str);
		temp = stack;
		stack = stack->next;
		free(temp);
	}
	free(stack);
}

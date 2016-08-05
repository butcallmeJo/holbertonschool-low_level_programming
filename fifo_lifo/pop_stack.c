/****************************************************************************
 * This file is part of the fifo_lifo project for Holberton School low level
 * programming track.
 ****************************************************************************/

/**
 * @file pop_stack.c
 * @author Josquin Gaillard
 * @date 08 Aug 2016
 * @brief File with the purpose to pop elements off a stack.
 */

#include <stdlib.h>
#include <string.h>
#include "stack.h"

/**
 * push_stack -
 * @stack: The Stack to which we push another node
 * Description: function that pops an element off a stack
 */
char *pop_stack(Stack **stack)
{
	Stack *ptr; /*ptr that will tempora stack*/
	char *ret_str;

	ptr = *stack; /*ptr needs to start at beginning*/
	if (ptr == NULL || ptr->str == NULL) /**/
	{
		return (NULL);
	}
	else /**/
	{
		ret_str = strdup(ptr->str);
		ptr->str = NULL;
		*stack = ptr->next;
		free(ptr->str);
		free(ptr);
	}
	return (ret_str);
}

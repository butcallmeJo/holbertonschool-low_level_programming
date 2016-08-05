/****************************************************************************
 * This file is part of the fifo_lifo project for Holberton School low level
 * programming track.
 ****************************************************************************/

/**
 * @file push_stack.c
 * @author Josquin Gaillard
 * @date 08 Aug 2016
 * @brief File with the purpose to push elements to a stack.
 */

#include <stdlib.h>
#include <string.h>
#include "stack.h"

/**
 * push_stack -
 * @stack:
 * @string:
 * Description:
 */
int push_stack(Stack **stack, char *string)
{
	Stack *front_ptr; /*ptr that will stay at front of stack*/

	front_ptr = (Stack *) malloc(sizeof(Stack));
	if (*stack == NULL) /*if stack not existing, creates it*/
	{
		*stack = front_ptr;
	}
	else /**/
	{
		front_ptr->next = *stack;
		*stack = front_ptr; /**/
	}
	front_ptr->str = strdup(string); /*duplicates the string to front_ptr*/
	return (0);
}

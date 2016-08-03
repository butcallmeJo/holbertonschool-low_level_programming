/****************************************************************************
 * This file is part of the fifo_lifo project for Holberton School low level
 * programming track.
 ****************************************************************************/

/**
 * @file pop_queue.c
 * @author Josquin Gaillard
 * @date 08 Aug 2016
 * @brief File with the purpose to pop elements off a queue.
 */

#include <stdlib.h>
#include <string.h>
#include "queue.h"

/**
 * push_queue -
 * @queue: The Queue to which we push another node
 * @string: The string to copy to the new node at the end of queue
 * Description: function that pushes an element to the rear of a queue
 */
char *pop_queue(Queue **queue)
{
	Queue *ptr; /*ptr that will tempora queue*/
	char *ret_str;

	ptr = *queue; /*ptr needs to start at beginning*/
	if (ptr == NULL || ptr->str == NULL) /*if queue not existing, creates it*/
	{
		return (NULL);
	}
	else /**/
	{
		ret_str = ptr->str;
		ptr->str = NULL;
		*queue = ptr->next;
		free(ptr);
	}
	return (ret_str);
}

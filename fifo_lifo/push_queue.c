/****************************************************************************
 * This file is part of the fifo_lifo project for Holberton School low level
 * programming track.
 ****************************************************************************/

/**
 * @file push_queue.c
 * @author Josquin Gaillard
 * @date 08 Aug 2016
 * @brief File with the purpose to push elements to a queue.
 */

#include <stdlib.h>
#include <string.h>
#include "queue.h"

/**
 * push_queue -
 * @queue:
 * @string:
 * Description:
 */
int push_queue(Queue **queue, char *string)
{
	Queue *rear_ptr; /*ptr that will traverse queue*/

	rear_ptr = *queue; /*rear_ptr needs to start at beginning*/
	if (rear_ptr == NULL) /*if queue not existing, creates it*/
	{
		rear_ptr = (Queue *) malloc(sizeof(Queue));
		*queue = rear_ptr;
	}
	else /*traverse queue to the last node*/
	{
		while (rear_ptr->next != NULL)
		{
			rear_ptr = rear_ptr->next;
		}
		rear_ptr->next = (Queue *) malloc(sizeof(Queue));
		rear_ptr = rear_ptr->next; /*rear_ptr is at the correct spot now*/
	}
	rear_ptr->next = NULL; /*rear_ptr is the last, so next is NULL*/
	rear_ptr->str = strdup(string); /*duplicates the string to rear_ptr*/
	return (0);
}

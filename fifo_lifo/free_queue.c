#include "queue.h"
#include <stdlib.h>

/**
 * free_queue -
 * @queue:
 * Description:
 */
void free_queue(Queue *queue)
{
	Queue *temp = queue;
	while (queue != NULL) {
		free(queue->str);
		temp = queue;
		queue = queue->next;
		free(temp);
	}
	free(queue);
}

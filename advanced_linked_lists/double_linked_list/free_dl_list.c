#include <stdlib.h>
#include <string.h>
#include "list.h"

void free_dl_list(List *list)
{
	/*init node to go thru list freeing eveything*/
	List *node;
	node = list;

	/*loop thru list while freeing everything*/
	while (node != NULL) {
		free(node->str);
		free(node);
		node = node->next;
	}
}

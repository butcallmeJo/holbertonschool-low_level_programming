#include "hashtable.h"
#include <stdlib.h>
#include <string.h>

void ht_free(HashTable *hashtable)
{
	unsigned int i;
	List *ptr;
	List *prev_ptr;
	for (i=0; i<hashtable->size; i++) {
		ptr = hashtable->array[i];
		while (ptr != NULL) {
			free(ptr->key);
			free(ptr->value);
			prev_ptr = ptr;
			ptr = ptr->next;
			free(prev_ptr);
		}
	}
	free(hashtable->array);
	free(hashtable);
	return
}

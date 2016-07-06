#include <stdlib.h>
#include "hashtable.h"

HashTable *ht_create(unsigned int size)
{
	/*init counter and hashtable*/
	int i;
	HashTable *ht = NULL;
	/*error checking and allocating mem*/
	if (size < 1) return NULL;
	if ((ht = malloc(sizeof(HashTable))) == NULL) {
		return NULL;
	}
	if ((ht->table = malloc(sizeof(List *) * size)) == NULL) {
		return NULL;
	}
	/*loop through */
	for(i = 0; i < size; i++) {
		ht->table[i] = NULL;
	}
	ht->size = size;
	return ht;
}

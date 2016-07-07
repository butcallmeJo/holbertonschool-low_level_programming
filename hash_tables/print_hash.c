#include "hashtable.h"
#include <stdio.h>
#include <stdlib.h>

int print_hashtable(HashTable *ht);
HashTable *ht_create(unsigned int size);
int ht_put(HashTable *hashtable, const char *key, const char *value);
unsigned int hash(const char *key, unsigned int size);
char *ht_get(HashTable *hashtable, const char *key);
void ht_free(HashTable *hashtable);

int main(void)
{
	HashTable *ht = ht_create(5);
	char *result;
	ht_put(ht, "One", "Value One");
	ht_put(ht, "Two", "Value Two");
	ht_put(ht, "Three", "Value Three");
	ht_put(ht, "Four", "Value Four");
	ht_put(ht, "Five", "Value Five");
	ht_put(ht, "Six", "Value Six");
	ht_put(ht, "Seven", "Value Seven");
	print_hashtable(ht);
	result = ht_get(ht, "Seven");
	printf("\n**\n%s\n**\n", result);
	free(result);
	ht_free(ht);
	return 0;
}

int print_hashtable(HashTable *ht)
{
	unsigned int i;
	List *listptr;
	for (i=0 ; i<ht->size ; i++) {
		printf("%d\n", i);
		/* traverse list */
		listptr = ht->array[i];
		printf("\t--------\n");
		while (listptr != NULL) {
			printf("\tkey: %s\n\tval: %s\n\t--------\n", listptr->key, listptr->value);
			listptr = listptr->next;
		}
		printf("\tNULL\n\t--------\n");
	}
	return 0;
}

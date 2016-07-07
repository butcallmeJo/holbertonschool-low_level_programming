#include <stdlib.h>
#include <string.h>
#include "hashtable.h"

int str_cmp(const char *str1, const char *str2);

int ht_put(HashTable *hashtable, const char *key, const char *value)
{
	/*init of index by passing to hash function*/
	int index = hash(key, hashtable->size);
	List *ptr = hashtable->array[index];
	/*loop over the hashtable array of index*/
	while (ptr != NULL) {
		/*finds the correct key*/
		if (str_cmp(ptr->key, key) == 0) {
			/*copies value to correct key*/
			ptr->value = strdup(value);
			return 0;
		}
		ptr = ptr->next;
	}
	/*puts key value pairs in the hashtable at the correct index*/
	ptr = hashtable->array[index];
	hashtable->array[index] = malloc(sizeof(List));
	hashtable->array[index]->next = ptr;
	hashtable->array[index]->key = strdup(key);
	hashtable->array[index]->value = strdup(value);
	return 0;
}

int str_cmp(const char *str1, const char *str2)
{
	int i;
	for (i = 0; str1[i]!=0 || str2[i]!=0; i++) {
		if (str1[i] != str2[i]) {
			return str1[i] - str2[i];
		}
	}
	return 0;
}

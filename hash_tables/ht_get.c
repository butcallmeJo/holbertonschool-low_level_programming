#include "hashtable.h"
#include <stdlib.h>
#include <string.h>

int str_cmp2(const char *str1, const char *str2);

char *ht_get(HashTable *hashtable, const char *key)
{
	/*init of index by passing to hash function*/
	int index = hash(key, hashtable->size);
	List *ptr = hashtable->array[index];
	/*loop over the hashtable array of index*/
	while (ptr != NULL) {
		if (str_cmp2(ptr->key, key) == 0) {
			/*returns the correct value of the key*/
			return strdup(ptr->value);
		}
		ptr = ptr->next;
	}
	/*Nope, couldn't find it. Sorry*/
	return NULL;
}

int str_cmp2(const char *str1, const char *str2)
{
	int i;
	for (i = 0; str1[i]!=0 || str2[i]!=0; i++) {
		if (str1[i] != str2[i]) {
			return str1[i] - str2[i];
		}
	}
	return 0;
}

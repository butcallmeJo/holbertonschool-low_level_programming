#include <stdlib.h>
#include "hashtable.h"

int str_cmp(char *str1, char *str2);

int ht_put(HashTable *hashtable, const char *key, const char *value)
{
	int index = hash(key, *hashtable->size);
	List *ptr = hashtable->array[index];
	while (ptr != NULL) {
		if (str_cmp(ptr->key, key) == 0) {
			ptr->value = strdup(value);
			return 0;
		}
		ptr = ptr=->next;
	}
}

int str_cmp(char *str1, char *str2)
{
	int i;
	for (i = 0; str1[i]!=0 || str2[i]!=0; i++) {
		if (str1[i] != str2[i]) {
			return str1[i] - str2[i];
		}
	}
	return 0
}

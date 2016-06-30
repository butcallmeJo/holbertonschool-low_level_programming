#include <stdlib.h>
#include <string.h>
#include "list.h"

int add_end_dcl_list(List **list, char *str);

List *array_to_dcl_list(char **array)
{
	/*init of list and i for incrementing*/
	int i;
	List *list;
	list = NULL;
	/*looping over array and adding to list while error checking*/
	for (i=0; array[i] != 0; i++) {
		if (add_end_dcl_list(&list, array[i]) == 1) return NULL;
	}
	return list;
}

#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int add_begin_cl_list(List **list, char *str)
{
	/*init new node and ptr*/
	List *node;
	List *ptr; /*pointer to help go thru nodes*/

	/*error checking and malloc node*/
	if (list == NULL) return 1;
	node = malloc(sizeof(List));
	if (node == NULL) return 1;
	if (str == NULL) return 1;

	/*contents of new node*/
	node->str = strdup(str);
	if (node->str == NULL) return 1;
	node->next = list;
	list = node;

	/*linking last node to first*/
	ptr = *list;
	while (ptr->next != NULL) {
		ptr = ptr->next;
	}
	ptr->next = list;

	return 0;
}

int add_end_cl_list(List **list, char *str)
{
	/*init new node and ptr*/
	List *node;
	List *ptr; /*pointer to help go thru nodes*/

	/*error checking and malloc node*/
	if (list == NULL) return 1;
	node = malloc(sizeof(List));
	if (node == NULL) return 1;
	if (str == NULL) return 1;

	/*contents of new node*/
	node->str = strdup(str);
	if (node->str == NULL) return 1;
	node->next = list;

	/*going thru list to get last node and link to new node*/
	ptr = *list;
	while (ptr->next != NULL) {
		ptr = ptr->next;
	}
	ptr->next = node;
	return 0;
}

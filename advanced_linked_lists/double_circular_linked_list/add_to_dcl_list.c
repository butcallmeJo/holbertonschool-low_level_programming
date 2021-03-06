#include <stdlib.h>
#include <string.h>
#include "list.h"

int add_end_dcl_list(List **list, char *str)
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

	/*if list empty, list should point to node*/
	if (*list == NULL) {
		*list = node;
		node->prev = *list;
		node->next = *list;
	}
	/*else going thru list to get last node and link to new node*/
	else {
		ptr = *list;
		while (ptr->next != *list) {
			ptr = ptr->next;
		}
		node->next = *list;
		node->prev = ptr;
		ptr->next = node;
		(*list)->prev = node;
	}
	return 0;
}

int add_begin_dcl_list(List **list, char *str)
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

	if (*list == NULL) {
		*list = node;
	}
	else {
		/*linking last node to first*/
		ptr = *list;
		while (ptr->next != *list) {
			ptr = ptr->next;
		}
	}
	node->prev = (*list)->prev;
	(*list)->prev = node;
	node->next = *list;
	*list = node;
	ptr->next = *list;
	return 0;
}

#include <stdlib.h>
#include <string.h>
#include "list.h"

int add_begin_dl_list(List **list, char *str);
int add_end_dl_list(List **list, char *str);

int add_end_dl_list(List **list, char *str)
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
	node->next = NULL;

	/*if list empty, node prev should be NULL*/
	if (*list == NULL) {
		node->prev = NULL;
		*list = node;
	}
	/*else find the last node in list and link it to new node*/
	else {
		ptr = *list;
		while (ptr->next != NULL) {
			ptr = ptr->next;
		}
		node->prev = ptr;
		ptr->next = node;
	}
	return 0;
}

int add_begin_dl_list(List **list, char *str)
{
	/*init new node and ptr*/
	List *node;
	List *ptr;

	/*error checking and malloc node*/
	if (list == NULL) return 1;
	node = malloc(sizeof(List));
	if (node == NULL) return 1;
	if (str == NULL) return 1;

	/*contents of new node*/
	node->str = strdup(str);
	if (node->str == NULL) return 1;
	node->prev = NULL;

	/*if list empty, node next should be NULL*/
	if (*list == NULL) {
		node->next = NULL;
		*list = node;
	}
	/*else find the first node in list and link it to new node*/
	else {
		node->next = *list;
		(*list)->prev = node;
		*list = node;
	}
	return 0;
}

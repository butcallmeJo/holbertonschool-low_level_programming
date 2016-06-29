#include <stdlib.h>
#include <string.h>
#include "list.h"

void print_string(char *str);
void print_char(char c);

void print_dl_list(List *list)
{
	/*inits and err checking*/
	List *ptr; /*ptr to be reused*/
	if (list == NULL) return;
	ptr = list;
	if (ptr == NULL) return;

	while (ptr != NULL) {
		print_string(ptr->str);
		print_char('\n');
		print_char('\t');
		if (ptr->prev == NULL) print_string("NULL");
		else {
			print_string(ptr->prev->str);
		}
		print_char('\n');
		print_char('\t');
		if (ptr->next == NULL) print_string("NULL");
		else {
			print_string(ptr->next->str);
		}
		print_char('\n');
		ptr = ptr->next;
	}
}

void print_string(char *str)
{
	int i;
	for (i=0; str[i] != 0; i++) {
		print_char(str[i]);
	}
}

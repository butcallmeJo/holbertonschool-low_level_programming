#include <stdlib.h>
#include <string.h>
#include "list.h"

void print_string(char *str);
void print_char(char c);

void print_dcl_list(List *list)
{
	/*inits and err checking*/
	List *head; /*ptr to start of list*/
	List *ptr; /*ptr to be reused*/
	if (list == NULL) return;
	ptr = list;
	head = list;
	if (ptr == NULL) return;
	if (head == NULL) return;

	/*looping over the list*/
	while (ptr->next != head) {
		print_string(ptr->str);
		print_char('\n');
		print_char('\t');
		print_string(ptr->prev->str);
		print_char('\n');
		print_char('\t');
		print_string(ptr->next->str);
		print_char('\n');
		ptr = ptr->next;
		if (ptr->next == head) {
			print_string(ptr->str);
			print_char('\n');
			print_char('\t');
			print_string(ptr->prev->str);
			print_char('\n');
			print_char('\t');
			print_string(ptr->next->str);
			print_char('\n');
		}
	}
	return;
}

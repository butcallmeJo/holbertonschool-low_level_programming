#include <stdlib.h>

/*
 * Function that frees a char **
 * CHECKED: functions, length, width, brackets, comments
 */
void free_command(char **command)
{
	int counter = 0;
	while (command[counter] != 0) {
		free(command[counter]);
		counter++;
	}
	free(command);
}

#include "utils.h"
#include <stdlib.h>

/*
 * Function that updates the environment status value <?>.
 */
void update_status(int status, char ***env)
{
	char *question_mark_string = malloc(sizeof(char) * 2);
	char *status_str = int_to_string(status);
	question_mark_string[0] = '?';
	question_mark_string[1] = 0;
	set_env(question_mark_string, status_str, env);
	free(status_str);
	free(question_mark_string);
}

#include "utils.h"
#include <unistd.h>
#include <stdlib.h>

/*
 * Function to print the status of a program <?>
 */
void print_status(char **env)
{
	char *status = get_env("?", env);
	write(1, status, str_len(status));
	write(1, "\n", 1);
	free(status);
}

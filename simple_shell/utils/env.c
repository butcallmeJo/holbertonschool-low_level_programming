#include <unistd.h>
#include "utils.h"

/*
 * Function that prints the environment variables
 * CHECKED: functions, length, width, brackets, comments
 */
int print_env(char **env)
{
	for ( ; *env!=0 ; env++) {
		char* thisEnv = *env;
		write(1, thisEnv, str_len(thisEnv));
		write(1, "\n", 1);
	}
	return(0);
}

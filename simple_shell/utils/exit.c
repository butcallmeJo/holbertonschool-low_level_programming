#include <stdlib.h>
#include "utils.h"
#include <unistd.h>

/*
 * Function that exits out of the shell and frees mem
 * CHECKED: functions, length, width, brackets, comments
 */
void cmd_exit(char **command, char ***env)
{
	int arg_val;
	free_command(*env);
	if (len_command(command) <= 1) {
		free_command(command);
		exit(0);
	}

	/*
	 * try to parse argv[1] as an int.
	 * if that fails, return 0. (default return of string_to_int)
	 */
	arg_val = string_to_int(command[1]);
	free_command(command);
	exit(arg_val);
}

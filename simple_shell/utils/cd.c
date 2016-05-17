#include <unistd.h>
#include <stdlib.h>
#include "utils.h"

/*
 * Function that will change directories
 * CHECKED: functions, length, width, brackets, comments
 */
void cd(char **command, char ***env)
{
	char *wd = get_wd();
	char *address;
	if (len_command(command) <= 1) {
		address = get_env("HOME", *env);
	}
	/*getting the old directory when '-' is the option*/
	else if (strings_compare(command[1], "-") == 0) {
		address = get_env("OLDPWD", *env);
	} else {
		address = malloc(sizeof(char) * str_len(command[1])+1);
		string_copy(address, command[1]);
	}
	
	/*error checking if path to dir doesn't exist*/
	if (chdir(address) == -1) {
		write(2, "cd: no such directory\n", 22);
		return;
	}
	/*making sure to set the current dir as OLDPWD before changing dir*/
	set_env("OLDPWD", wd, env);
	free(wd);
	wd = get_wd();
	set_env("PWD", wd, env);
	free(wd);
	free(address);
}

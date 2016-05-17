#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include "utils.h"

/*
 * Function will return the correct cmd to run or NULL if no cmd
 * TODO reduce function to multiple functions.
 * TODO reduce numbers of while and ifs statements.
 */
void *ret_correct_path(char *cmd, __attribute__((unused)) char **env)
{
	char *cmd_cpy;
	char **path;
	char *str;
	DIR *pDir;
	struct dirent *pDirent;
	int i;

	cmd_cpy = malloc(sizeof(char) * str_len(cmd) + 1);
	cmd_cpy = string_copy(cmd_cpy, cmd);

	/*if cmd is a path, return it without changing it*/
	if (check_path(cmd_cpy) == 1) {
		/* check if path exists */
		i = open(cmd_cpy, O_RDONLY);
		if (i < 0) {
			free(cmd_cpy);
			return NULL;
		}
		close(i);
		return cmd_cpy;
	}

	/*Splitting path to get all path directories needed*/
	str = get_env("PATH");
	path = string_split(str, ':');

	/*search thru each paths' directories for cmd */
	for (i=0; path[i] != 0; i++) {
		pDir = opendir(path[i]);
		/*Searching the opened dir for cmd*/
		while ((pDirent = readdir(pDir)) != NULL) {
			if (strings_compare(cmd, pDirent->d_name) == 0) {
				free(cmd_cpy);
				/*recreating correct path to cmd from path dir + cmd*/
				cmd_cpy = malloc(sizeof(char)*(str_len(path[i]) + str_len(cmd) + 2));
				cmd_cpy = string_copy(cmd_cpy, path[i]);
				str_cat(cmd_cpy, "/");
				str_cat(cmd_cpy, cmd);
				free_command(path);
				free(str);
				closedir(pDir);
				return cmd_cpy;
			}
		}
		closedir(pDir);
	}
	free_command(path);
	free(str);
	free(cmd_cpy);
	/* Command not found, return null */
	return NULL;
}

/*
 * if cmd is a path, return it without changing it
 */
int check_path(char *cmd_cpy)
{
	while (*cmd_cpy != 0) {
		if (*cmd_cpy == '/')
			return 1;
		cmd_cpy++;
	}
	return 0;
}

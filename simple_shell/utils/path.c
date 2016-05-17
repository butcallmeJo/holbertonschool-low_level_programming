#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include "utils.h"

/*
 * Function will return the correct cmd to run or NULL if no cmd
 * TODO reduce numbers of while and ifs statements.
 */
void *ret_correct_path(char *cmd, char **env)
{
	char *cmd_cpy;
	char **path;
	char *str;
	cmd_cpy = malloc(sizeof(char) * str_len(cmd) + 1);
	cmd_cpy = string_copy(cmd_cpy, cmd);
	/*if cmd is a path, return it without changing it*/
	if (check_path(cmd_cpy) == 1) {
		/* check if path exists */
		if (is_dir(cmd_cpy) || access(cmd_cpy, X_OK) != 0) {
			free(cmd_cpy);
			return NULL;
		}
		return cmd_cpy;
	}
	/*Splitting path to get all path directories needed*/
	str = get_env("PATH", env);
	path = string_split(str, ':');
	free(str);
	free(cmd_cpy);
	/*search thru each paths' directories for cmd */
	cmd_cpy = get_correct_cmd_path(path, cmd_cpy, cmd);
	if (cmd_cpy != NULL)
		return cmd_cpy;
	/* Command not found, return null */
	free(cmd_cpy);
	return NULL;
}

/*
 * if cmd is a path, return it without changing it
 */
int check_path(char *cmd_cpy)
{
	if (is_dir(cmd_cpy))
		return 1;
	while (*cmd_cpy != 0) {
		if (*cmd_cpy == '/')
			return 1;
		cmd_cpy++;
	}
	return 0;
}

/*
 * Function to get the correct path for the cmd input
 */
char *get_correct_cmd_path(char **path, char *cmd_cpy, char *cmd)
{
	int i;
	int s1;
	int s2;
	DIR *pDir;
	struct dirent *pDirent;
	s1 = str_len(cmd);
	for (i=0; path[i] != 0; i++) {
		pDir = opendir(path[i]);
		s2 = str_len(path[i]);
		/*Searching the opened dir for cmd*/
		while ((pDirent = readdir(pDir)) != NULL) {
			if (strings_compare(cmd, pDirent->d_name) == 0) {
				/* recreating correct path to cmd from
				 * path dir + cmd */
				cmd_cpy = malloc(sizeof(char) * (s1 + s2 + 2));
				cmd_cpy = string_copy(cmd_cpy, path[i]);
				str_cat(cmd_cpy, "/");
				str_cat(cmd_cpy, cmd);
				free_command(path);
				closedir(pDir);
				return cmd_cpy;
			}
		}
		closedir(pDir);
	}
	free_command(path);
	return NULL;
}

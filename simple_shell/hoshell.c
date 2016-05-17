#include <unistd.h>
#include <stdlib.h>
#include "utils/utils.h"
#include <sys/wait.h>
#include <stdio.h> /*TODO remove after testing?*/

void fork_exec(char **command, char ***env);
int check_builtins(char **command, char ***env);

/*
 * Highly Original SHELL
 */
int main(__attribute__((unused)) int argc,
	 __attribute__((unused)) char **argv, char **env)
{
	char **command;
	char *line;
	init_env(&env); /* moves environment variables to the heap */
	/* read from stdin */
	while (1) {
		write(1, "HOS :: ", 7);
		line = read_line(0);
		/*ignore comments*/
		/*TODO string split on ';' and run loop around each*/
		/*TODO after ';' check for '$'*/
		command = string_split(line, '#');
		if (command[0] == NULL) {
			free_command(command);
			free(line);
			continue;
		};
		string_copy(line, command[0]);
		free_command(command);
		command = string_split(line, ' ');
		free(line);
		if (command[0] == NULL) {
			free_command(command);
			continue;
		};
		fork_exec(command, &env);
		free_command(command);
	}
}

/*
 * Function to run a command without killing the main thread
 */
void fork_exec(char **command, char ***env)
{
	int status;
	int pid;
	char *cmd = command[0];
	if (check_builtins(command, env)) 	/*runs custom built cmds*/
		return;
	cmd = ret_correct_path(cmd, *env); 	/*returns the correct cmd*/
	if (cmd == NULL) { 			/*error checking*/
		write(2, command[0], str_len(command[0]));
		write(2, ": Command not found\n", 20);
		return;
	}
	pid = fork();				/*starting child process*/
	if (pid == -1) {			/*error checking*/
		write(2, "Fork failed", 11);
	} else if (pid == 0) {
		execve(cmd, command, *env);	/*executing correct cmd*/
	} else {				/*TBD*/
		wait(&status);
		update_status(status, env);
	}
	free(cmd);
	return;
}

/*
 * Function to check builtin commands before searching path.
 * returns 1 if found, 0 otherwise.
 * TODO: make this use a function pointer array or something else sane
 */
int check_builtins(char **command, char ***env)
{
	if (strings_compare(command[0], "exit") == 0) {
		cmd_exit(command, env);
		return 1;
	}
	if (strings_compare(command[0], "env") == 0) {
		print_env(*env);
		return 1;
	}
	if (strings_compare(command[0], "cd") == 0) {
		cd(command, env);
		return 1;
	}
	if (strings_compare(command[0], "pwd") == 0) {
		pwd();
		return 1;
	}
	if (strings_compare(command[0], "$?") == 0) {
		print_status(*env);
		return 1;
	}
	return 0;
}

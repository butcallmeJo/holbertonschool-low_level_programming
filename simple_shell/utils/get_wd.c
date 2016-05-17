#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>
#include <stdlib.h>
#include "utils.h"
#include <stdio.h>
#include <string.h>

char *path_concat(char *path, char *newname);
char *get_wd_recurse(char *path, char *reverse_path, unsigned int search_inode);
char *get_wd();
int check_inode(char *reverse_path, unsigned int search_inode,
                struct dirent *dir_entry);

/*
 * Prints working directory.
 */
void pwd()
{
	char *wd = get_wd();
	if (wd == NULL)
		return;
	write(1, wd, str_len(wd));
	write(1, "\n", 1);
	free(wd);
}

/*
 * Returns a char *containing the current working directory path. This does not
 * follow symlinks.
 */
char *get_wd()
{
	char *path = malloc(sizeof(char) * 1);
	char *reverse_path = malloc(sizeof(char) * 3);
	DIR *dir = opendir(".");
	int self_inode = get_self_inode(dir);
	if (is_root(dir, self_inode)) {
		free(path);
		path = malloc(sizeof(char) * 2);
		str_cat(path, "/");
		return path;
	}
	closedir(dir);
	string_copy(path, "");
	string_copy(reverse_path, "..");
	path = get_wd_recurse(path, reverse_path, self_inode);
	return path;
}

/*
 * Recursion function for pwd. Traverses directories towards root and builds
 * path string.
 */
char *get_wd_recurse(char *path, char *reverse_path, unsigned int search_inode)
{
	DIR *dir = opendir(reverse_path);
	unsigned int self_inode = get_self_inode(dir);
	int root_boolean = is_root(dir, self_inode);
	struct dirent *dir_entry;
	dir_entry = readdir(dir);
	while (dir_entry != NULL) {
		if (check_inode(reverse_path, search_inode, dir_entry)) {
			/* prepend name/ to path */
			path = path_concat(path, dir_entry->d_name);
			/* break recursion if no parent */
			if (root_boolean) {
				path = path_concat(path, "");
				free(reverse_path);
				closedir(dir);
				return path;
			}
			reverse_path = path_concat(reverse_path, "..");
			closedir(dir);
			return get_wd_recurse(path, reverse_path, self_inode);
		}
		dir_entry = readdir(dir);
	}
	closedir(dir);
	return NULL;
}

/*
 * A better check than using dirent struct inode field.
 * Checks each directory's inode from within that directory to guarantee
 * functionality at mount points
 */
int check_inode(char *reverse_path, unsigned int search_inode,
		struct dirent *dir_entry)
{
	DIR *checkdir;
	char *r_r_path;
	unsigned int check_inode;
	r_r_path = malloc(str_len(reverse_path)+str_len(dir_entry->d_name)+2);
	r_r_path = string_copy(r_r_path, reverse_path);
	str_cat(r_r_path, "/");
	str_cat(r_r_path, dir_entry->d_name);
	checkdir = opendir(r_r_path);
	if (checkdir == NULL) {
		free(r_r_path);
		return 0;
	}
	check_inode = get_self_inode(checkdir);
	closedir(checkdir);
	free(r_r_path);
	if (check_inode == search_inode)
		return 1;
	return 0;
}

/*
 * Prepends a directory to a path string.
 * Don't use this unless you know what you are doing, it can damage things
 */
char *path_concat(char *path, char *newname)
{
	int size = str_len(newname) + str_len(path) + 2;
	char *temp = malloc(size * sizeof(char));
	string_copy(temp, newname);
	str_cat(temp, "/");
	str_cat(temp, path);
	free(path);
	path = temp;
	return path;
}

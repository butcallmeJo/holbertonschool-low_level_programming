#include "utils.h"
#include <dirent.h>
#include <stdlib.h>
#include <sys/stat.h>
/*
 * Function returns 1 if dir is root, 0 otherwise
 */
int is_root(DIR *dir, unsigned int self_inode)
{
	int ret = 1;
	struct dirent *dir_entry;
	if (!dir)
		return -1;
	dir_entry = readdir(dir);
	while (dir_entry != NULL) {
		if (strings_compare(dir_entry->d_name, "..") == 0) {
			if ((unsigned int) dir_entry->d_ino != self_inode)
				ret = 0;
		}
		dir_entry = readdir(dir);
	}
	rewinddir(dir);
	return ret;
}

/*
 * Function returns the inode of input directory
 */
unsigned int get_self_inode(DIR *dir)
{
	unsigned int ret = 0;
	struct dirent *dir_entry;
	dir_entry = readdir(dir);
	while (dir_entry != NULL) {
		if (strings_compare(dir_entry->d_name, ".") == 0)
			ret = dir_entry->d_ino;
		dir_entry = readdir(dir);
	}
	rewinddir(dir);
	return ret;
}

int is_dir(char *file)
{
	int ret;
	struct stat *filestat = malloc(sizeof(struct stat));
	stat(file, filestat);
	ret = S_ISDIR(filestat->st_mode);
	free(filestat);
	return ret;
}

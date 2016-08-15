/****************************************************************************
 * This file is part of the n_trees project for Holberton School low level
 * programming track.
 ****************************************************************************/

/**
 * @file path_exists.c
 * @author Josquin Gaillard
 * @date 31 Jul 2016
 * @brief File that check if a path is present in a N-ary tree.
 */

#include "tree.h"
#include <stdlib.h>
#include <string.h>

NTree *traverse_path(List *list, char *child);

/**
 * path_exists -
 * @tree: the address of the root node of the Tree.
 * @path:  an array of string.
 * Description:
 */
int path_exists(NTree *tree, char **path)
{
	int i;

	if (tree == NULL || path == NULL || path[0] == NULL)
		return (0);
	for (i = 0; path[i] != NULL; i++)
	{
		if (i == 0 && strcmp(tree->str, path[i]))
			tree = NULL;
		else if (i != 0)
			tree = traverse_path(tree->children, path[i]);
		if (tree == NULL)
			return (0);
	}
	return (1);
}

/**
 * traverse_path -
 * @list:
 * @child:
 * Description:
 */
NTree *traverse_path(List *list, char *child)
{
	if (list == NULL || list->node == NULL)
		return (NULL);
	if (list->node->str == NULL || child == NULL)
		return (NULL);
	if (strcmp(list->node->str, child) == 0)
		return (list->node);

	return (traverse_path(list->next, child));
}

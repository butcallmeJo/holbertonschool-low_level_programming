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

void free_tree_list(List *list);
void free_tree_node(NTree *tree);

void ntree_free(NTree *tree)
{
	free_tree_list(tree->children);
	free(tree->str);
	free(tree);
}

void free_tree_list(List *list)
{
	List *nxt;

	if (list == NULL)
		return;
	nxt = list->next;
	if (list->node != NULL)
		free_tree_node(list->node);
	free(list);
	free_tree_list(nxt);
}

void free_tree_node(NTree *tree)
{
	free(tree->str);
	if (tree->children != NULL)
		free_tree_list(tree->children);
	free(tree);
}

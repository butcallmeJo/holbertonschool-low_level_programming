/****************************************************************************
 * This file is part of the trees project for Holberton School low level
 * programming track.
 ****************************************************************************/

/**
 * @file btree_free.c
 * @author Josquin Gaillard
 * @date 24 Jul 2016
 * @brief File with the purpose to free elements in a Binary tree
 * and the tree itself.
 */

#include "tree.h"
#include <stdlib.h>

void btree_free(BTree *tree)
{
	if (tree == NULL)
		return;
	if (tree->str != NULL)
		free(tree->str);
	btree_free(tree->left); /*frees recursively*/
	btree_free(tree->right); /*frees recursively*/
	free(tree);
}

/****************************************************************************
 * This file is part of the trees project for Holberton School low level
 * programming track.
 ****************************************************************************/

/**
 * @file btree_find.c
 * @author Josquin Gaillard
 * @date 24 Jul 2016
 * @brief File with the purpose to find elements in a Binary tree.
 */

#include "tree.h"
#include <string.h>

BTree *find_str(BTree *tree, char *str);

/**
 * btree_find: function that coordinates the find of
 * a node in a binary tree.
 * @tree: first node of the BTree Stuct.
 * @str: the data (string) to be found in the tree.
 */

BTree *btree_find(BTree *tree, char *str)
{
	if (tree == NULL || str NULL)
		return (NULL);
	else
		return (find_str(tree, str));
}

/**
 * find_str: function that a node in a binary tree.
 * @tree: first node of the BTree Stuct.
 * @str: the data (string) to be found in the tree.
 */

BTree *find_str(BTree *tree, char *str)
{
	if (tree == NULL)
		return (NULL);
	if (strcmp(str, tree->str) == 0)
		return (tree);
	else if (strcmp(str, tree->str) < 0)
		return (find_str(tree->left, str));
	else
		return (find_str(tree->right, str));
}

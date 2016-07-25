/****************************************************************************
 * This file is part of the trees project for Holberton School low level
 * programming track.
 ****************************************************************************/

/**
 * @file btree_insert.c
 * @author Josquin Gaillard
 * @date 24 Jul 2016
 * @brief File with the purpose to insert elements in a Binary tree.
 */

#include "tree.h"
#include <stdlib.h>
#include <string.h>

add_node(BTree **tree, char *data);
traverse_tree(BTree **tree, char *data);

/**
 * btree_insert: function that coordinates the insertion of
 * a node in a binary tree.
 * @tree: first node of the BTree Stuct.
 * @data: the data (string) to be added to the tree.
 */

int btree_insert(BTree **tree, char *data)
{
	if (tree == NULL || data == NULL)
		return 1; /*returns error if tree and data not good*/
	else if (*tree == NULL)
		return add_node(tree, data); /*returns 0 if it worked. 1 otherwise*/
	else
		return traverse_tree(tree, data); /*returns 0 if it worked. 1 otherwise*/
}

/**
 * add_node: function that insert a node in a binary tree.
 * @tree: place of the BTree Stuct to insert node.
 * @data: the data (string) to be added to the tree.
 */

int add_node(BTree **tree, char *data)
{
	BTree *node;

	node = malloc(sizeof(BTree))
	if (node == NULL)
		return 1;
	node->str = strdup(data)
	if (node->str == NULL)
		return 1;
	node->left = NULL;
	node->right = NULL;
	*tree = node;
	return 0;
}

/**
 * btree_insert: function that traverses a binary tree recursively.
 * @tree: node where the BTree Stuct currently is.
 * @data: the data (string) to be added to the tree.
 * @description: if the data is smaller, it goes left, else
 * it goes right.
 */

int traverse_tree(BTree **tree, char *data)
{
	if (strcmp(data, tree->str) < 0)
	{
		if (tree->left == NULL)
			return add_node(&(tree->left), data);
		else
			return traverse_tree(tree->left, data);
	}
	else
	{
		if (tree->right == NULL)
			return add_node(&(tree->right), data);
		else
			return traverse_tree(tree->right, data);
	}
}

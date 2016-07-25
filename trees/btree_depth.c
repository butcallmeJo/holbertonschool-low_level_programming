/****************************************************************************
 * This file is part of the trees project for Holberton School low level
 * programming track.
 ****************************************************************************/

/**
 * @file btree_depth.c
 * @author Josquin Gaillard
 * @date 24 Jul 2016
 * @brief File with the purpose to insert elements in a Binary tree.
 */

#include "tree.h"

/**
 * btree_depth - returns depth of a tree
 * @tree: first node of the BTree Stuct.
 */

int btree_depth(BTree *tree)
{
	int depth = 0;

	if (tree == NULL)
		return -1;
	return find_depth(tree, depth);
}

/**
 * find_depth - returns depth of a tree
 * @tree: node of the BTree Stuct.
 * @depth: depth of the tree
 */

int find_depth(BTree *tree, depth)
{
	int left_depth;
	int right_depth;

	if (tree->left == NULL && tree->right == NULL)
		return depth;
	else if (!tree->right)
		return find_depth(tree->left, depth++);
	else if (!tree->left)
		return find_depth(tree->right, depth++);
	left_depth = find_depth(tree->left, depth + 1);
	right_depth = find_depth(tree->right, depth + 1);
	if (left_depth <= right_depth)
		return right_depth;
	return left_depth;
}

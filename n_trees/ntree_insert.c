/****************************************************************************
 * This file is part of the n_trees project for Holberton School low level
 * programming track.
 ****************************************************************************/

/**
 * @file ntree_insert.c
 * @author Josquin Gaillard
 * @date 31 Jul 2016
 * @brief File with the purpose to insert elements in an n-ary tree.
 */

#include "tree.h"
#include <stdlib.h>
#include <string.h>

NTree *add_node(char *data);
NTree *traverse_tree(List *list, char *child);
List *add_tree(List *first);

/**
 * ntree_insert: function that coordinates the insertion of
 * a node in a n-ary tree.
 * @tree: first node of the NTree Stuct.
 * @data: the data (string) to be added to the tree.
 */

int ntree_insert(NTree **tree, char **parents, char *data)
{
	int i;
	NTree *parent;
	if (tree == NULL || data == NULL)
		return (1); /*returns error if tree or data not good*/
	else if (*tree == NULL)
	{
		*tree = add_node(data);
		return (0);
	}
	else
	{
		parent = *tree;
		for (i = 1; parents[i]; i++)
		{
			parent = traverse_tree(parent->children, parents[i]);
		}
		if (parent == NULL)
			return (-1);
		parent->children = add_tree(parent->children);
		parent->children->node = add_node(data);
		return (0);
	}
}

/**
 * add_node -
 * @data:
 * Description:
 */
NTree *add_node(char *data)
{
	NTree *new;

	new = malloc(sizeof(NTree));
	new->str = strdup(data);
	new->children = NULL;
	return (new);
}

/**
 * traverse_tree -
 * @list:
 * @child:
 * Description:
 */
NTree *traverse_tree(List *list, char *child)
{
	if (list == NULL || list->node == NULL)
		return (NULL);
	if (list->node->str == NULL || child == NULL)
		return (NULL);
	if (strcmp(list->node->str, child) == 0)
		return (list->node);

	return (traverse_tree(list->next, child));
}

/**
 * add_tree -
 * @first:
 * Description:
 */
List *add_tree(List *first)
{
	List *new;

	new = malloc(sizeof(List));
	new->node = NULL;
	new->next = first;
	return (new);
}

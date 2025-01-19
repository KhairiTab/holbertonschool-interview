#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"
/**
 * binary_tree_node - Creates a new binary tree node
 * @parent: Pointer to the parent node
 * @value: Value to be stored in the new node
 *
 * Return: Pointer to the new node, or NULL on failure
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
binary_tree_t *newNode = (binary_tree_t *)malloc(sizeof(binary_tree_t));
if (newNode == NULL)
{
return (NULL);
}
newNode->n = value;
newNode->parent = parent;
newNode->left = NULL;
newNode->right = NULL;
return (newNode);
}

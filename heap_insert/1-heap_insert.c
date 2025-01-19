#include "binary_trees.h"

/**
 * heap_size - measures the size of a binary tree
 * @tree: pointer to the root node of the tree to measure the size
 * Return: Size of the tree, 0 if tree is NULL
 */
size_t heap_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (1 + heap_size(tree->left) + heap_size(tree->right));
}

/**
 * bubble_up - ensures the max heap property is maintained
 * @node: pointer to the node to bubble up
 * Return: pointer to the final position of the node
 */
heap_t *bubble_up(heap_t *node)
{
	int temp;
	heap_t *current = node;

	while (current->parent && current->n > current->parent->n)
	{
		temp = current->n;
		current->n = current->parent->n;
		current->parent->n = temp;
		current = current->parent;
	}
	return (current);
}

/**
 * get_parent - finds the parent node for the next insertion
 * @root: pointer to the root node
 * @index: index where the next node should be inserted
 * Return: pointer to the parent node
 */
heap_t *get_parent(heap_t *root, size_t index)
{
	size_t mask;

	for (mask = 1; mask <= index; mask <<= 1)
		;
	mask >>= 2;

	while (mask > 0)
	{
		if (index & mask)
			root = root->right;
		else
			root = root->left;
		mask >>= 1;
	}
	return (root);
}

/**
 * heap_insert - inserts a value into a Max Binary Heap
 * @root: double pointer to the root node of the Heap
 * @value: value to store in the node to be inserted
 * Return: pointer to the inserted node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_node, *parent;
	size_t size;

	if (!root)
		return (NULL);

	if (!*root)
	{
		*root = binary_tree_node(NULL, value);
		return (*root);
	}

	size = heap_size(*root);
	parent = get_parent(*root, size);

	new_node = binary_tree_node(parent, value);
	if (!new_node)
		return (NULL);

	if (size & 1)
		parent->right = new_node;
	else
		parent->left = new_node;

	return (bubble_up(new_node));
}

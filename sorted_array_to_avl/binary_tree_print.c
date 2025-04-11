#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binary_trees.h"

/* Original code from http://stackoverflow.com/a/13755911/5184480 */

/**
 * print_t - Stores recursively each level in an array of strings
 *
 * @tree: Pointer to the node to print
 * @offset: Offset to print
 * @depth: Depth of the node
 * @s: Buffer
 *
 * Return: length of printed tree after process
 */
static int print_t(const binary_tree_t *tree, int offset, int depth, char **s)
{
	char b[6];
	int width, left, right, is_left, i;

	if (!tree)
		return (0);
	is_left = (tree->parent && tree->parent->left == tree);
	width = sprintf(b, "(%03d)", tree->n);
	left = print_t(tree->left, offset, depth + 1, s);
	right = print_t(tree->right, offset + left + width, depth + 1, s);
	for (i = 0; i < width; i++)
		s[depth][offset + left + i] = b[i];
	if (depth && is_left)
	{
		for (i = 0; i < width + right; i++)
			s[depth - 1][offset + left + width / 2 + i] = '-';
		s[depth - 1][offset + left + width / 2] = '.';
	}
	else if (depth && !is_left)
	{
		for (i = 0; i < left + width; i++)
			s[depth - 1][offset - width / 2 + i] = '-';
		s[depth - 1][offset + left + width / 2] = '.';
	}
	return (left + width + right);
}

/**
 * _height - Measures the height of a binary tree
 *
 * @tree: Pointer to the node to measures the height
 *
 * Return: The height of the tree starting at @node
 */
static size_t _height(const binary_tree_t *tree)
{
	size_t height_l;
	size_t height_r;

	height_l = tree->left ? 1 + _height(tree->left) : 0;
	height_r = tree->right ? 1 + _height(tree->right) : 0;
	return (height_l > height_r ? height_l : height_r);
}

/**
 * binary_tree_print - Prints a binary tree
 *
 * @tree: Pointer to the root node of the tree to print
 */
void binary_tree_print(const binary_tree_t *tree)
{
	char **s;
	size_t height, i, j;

	if (!tree)
		return;
	height = _height(tree);
	s = malloc(sizeof(*s) * (height + 1));
	if (!s)
		return;
	for (i = 0; i < height + 1; i++)
	{
		s[i] = malloc(sizeof(**s) * 255);
		if (!s[i])
			return;
		memset(s[i], 32, 255);
	}
	print_t(tree, 0, 0, s);
	for (i = 0; i < height + 1; i++)
	{
		for (j = 254; j > 1; --j)
		{
			if (s[i][j] != ' ')
				break;
			s[i][j] = '\0';
		}
		printf("%s\n", s[i]);
		free(s[i]);
#include "binary_trees.h"

/**
 * *binary_tree_node - builds an AVL tree from an array
 *
 * @parent: The array to be printed
 * @index: Size of the array
 * @array: Size of the array
 *
 * Return: binary tree on success, NULL on failure
 */
avl_t *binary_tree_node(avl_t *parent, int index, int *array)
{
	avl_t *new_node = NULL;

	new_node = malloc(sizeof(avl_t));
	if (!new_node)
		return (NULL);

	new_node->left = new_node->right = NULL;
	new_node->n = array[index];
	new_node->parent = parent;

	return (new_node);
}

/**
 * *sorted_array_to_avl - builds an AVL tree from an array
 *
 * @array: The array to be printed
 * @size: Size of the array
 *
 * Return: binary tree on success, NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *new_node = NULL;

	if (!array || !size)
		return (NULL);


	new_node = SortedArrayToAVL(array, 0, size - 1, NULL);
	return (new_node);
}

/**
 * *SortedArrayToAVL - builds an AVL tree from an array
 *
 * @array: The array to be printed
 * @root: Size of the array
 * @start: Size of the array
 * @end: Size of the array
 *
 * Return: binary tree on success, NULL on failure
 */
avl_t *SortedArrayToAVL(int *array, size_t start, size_t end, avl_t *root)
{
	size_t mid;
	avl_t *new_node = NULL;

	if (start > end)
		return (NULL);

	mid = (start + end) / 2;

	new_node = binary_tree_node(root, mid, array);
	if (!new_node)
		return (NULL);

	if (mid != start)
		new_node->left = SortedArrayToAVL(array, start, mid - 1,
				new_node);

	if (mid != end)
		new_node->right = SortedArrayToAVL(array, mid + 1, end,
				new_node);

	return (new_node);
}

	}
	free(s);
}
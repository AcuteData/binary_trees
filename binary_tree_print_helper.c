#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "binary_trees.h"

/**
 * binary_tree_print - Prints a binary tree
 *
 * @tree: Pointer to the root node of the tree to print
 */
void binary_tree_print(const binary_tree_t *tree);

/**
 * _tree_height - Calculate the height of a binary tree
 *
 * @tree: Pointer to the root node of the tree
 * Return: Height of the tree
 */
size_t _tree_height(const binary_tree_t *tree)
{
    if (tree == NULL)
        return 0;

    size_t left_height = _tree_height(tree->left);
    size_t right_height = _tree_height(tree->right);

    return (left_height > right_height) ? (left_height + 1) : (right_height + 1);
}

/**
 * print_t - Recursive function to populate the string representation of the tree
 *
 * @tree: Pointer to the current node
 * @offset: Offset for the current node
 * @depth: Depth of the current node
 * @s: Array of strings to store the representation
 */
void print_t(const binary_tree_t *tree, int offset, int depth, char **s)
{
    if (tree == NULL)
        return;

    int width = 5; // Adjust the width as needed
    int left = offset - width / 2;
    int right = offset + width / 2;

    s[depth][offset] = '0' + tree->n;

    if (depth && s[depth - 1][left + 1] == '/')
        s[depth - 1][left + 1] = '0' + tree->n;

    print_t(tree->left, left, depth + 1, s);
    print_t(tree->right, right, depth + 1, s);
}

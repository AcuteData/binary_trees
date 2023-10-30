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
size_t _tree_height(const binary_tree_t *tree);

/**
 * print_t - Recursive function to populate the string representation of the tree
 *
 * @tree: Pointer to the current node
 * @offset: Offset for the current node
 * @depth: Depth of the current node
 * @s: Array of strings to store the representation
 */
void print_t(const binary_tree_t *tree, int offset, int depth, char **s);

void binary_tree_print(const binary_tree_t *tree)
{
    char **lines;
    size_t height, i, j;

    if (!tree)
        return;

    height = _tree_height(tree);
    lines = malloc(sizeof(*lines) * (height + 1));
    if (!lines)
        return;

    for (i = 0; i < height + 1; i++)
    {
        lines[i] = malloc(sizeof(**lines) * 255);
        if (!lines[i])
            return;
        memset(lines[i], 32, 255);
    }

    print_t(tree, 0, 0, lines);

    for (i = 0; i < height + 1; i++)
    {
        for (j = 254; j > 1; --j)
        {
            if (lines[i][j] != ' ')
                break;
            lines[i][j] = '\0';
        }
        printf("%s\n", lines[i]);
        free(lines[i]);
    }
    free(lines);
}

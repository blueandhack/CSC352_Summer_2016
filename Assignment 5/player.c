/*
 * CSc 352 Summer 2016, Assignment 05
 *
 * Author: Yujia Lin
 *
 * Instructor: Lee Savoie
 *
 * ---
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "player.h"

/*
 * This function creates an empty binary search tree. It takes no parameters and returns
 * a pointer to a newly allocated struct Node.
 */
struct Node *createTree() {
    struct Node *tree = (struct Node *) malloc(sizeof(struct Node));
    if (tree == NULL) {
        fprintf(stderr, "Out of memory!");
        return NULL;
    }
    tree->data.name = NULL;
    tree->left = NULL;
    tree->right = NULL;
    return tree;
}

/*
 * This function adds the provided element to the binary search tree.
 *
 * Parameters:
 * tree - the BST to add the element to
 * name - the element of name to add to the BST
 * isWin - the element of isWin to add to the BST
 * isLos - the element of isLos to add to the BST
 *
 * Returns: 1 if insert successful, and 0 if it was not.
 */
int insertPlayer(struct Node *tree, char *name, int isWin, int isLos) {

    if (tree->data.name == NULL) {
        tree->data.name = strdup(name);
        if (tree->data.name == NULL) {
            fprintf(stderr, "Out of memory!");
            return 0;
        }
        tree->data.losses = isLos;
        tree->data.wins = isWin;
        return 1;
    }
    struct Node *node = (struct Node *) malloc(sizeof(struct Node));
    if (node == NULL) {
        fprintf(stderr, "Out of memory!");
        return 0;
    }
    node->data.name = strdup(name);
    if (node->data.name == NULL) {
        free(node);
        fprintf(stderr, "Out of memory!");
        return 0;
    }
    node->data.losses = isLos;
    node->data.wins = isWin;
    node->right = NULL;
    node->left = NULL;

    struct Node *p = tree;

    while (1) {

        if (strcmp(p->data.name, name) < 0) {
            if (p->right == NULL) {
                p->right = node;
                return 1;
            }
            p = p->right;
        } else {
            if (p->left == NULL) {
                p->left = node;
                return 1;
            }
            p = p->left;
        }
    }
}

/*
 * This function finds an element in the binary search tree. It searches for the element
 * whose data.name value matches the name value passed to the function.
 *
 * Parameters:
 * tree - the BST to search in
 * name - the name to search for.
 *
 * Returns: 1 if the element was found in the BST, and 0 if it was not.
 */
int findPlayer(struct Node *tree, char *name) {

    if (tree->data.name == NULL) {
        return 0;
    }
    struct Node *p = tree;
    while (p != NULL) {
        if (strcmp(p->data.name, name) < 0) {

            p = p->right;
        } else if (strcmp(p->data.name, name) > 0) {

            p = p->left;
        } else {
            return 1;
        }
    }
    return 0;
}

/*
 * Updates an element in the BST in place. Nothing is added or removed from the BST.
 * This function searches through the BST to find the element such that data.name
 * equals name. If it finds such an element, that element is set to the value of
 * isWin and isLos.
 *
 * Parameters:
 * tree - the BST to update
 * name - the name to search for.
 * isWin - the element of isWin to update for.
 * isLos - the element of isLos to update for.
 *
 * Returns: 1 if the BST was updated, 0 if the BST was not updated.
 */
int updatePlayer(struct Node *tree, char *name, int isWin, int isLos) {

    if (tree->data.name == NULL) {
        return 0;
    }

    struct Node *p = tree;
    while (p != NULL) {
        if (strcmp(p->data.name, name) < 0) {

            p = p->right;
        } else if (strcmp(p->data.name, name) > 0) {

            p = p->left;
        } else {

            if (isWin == 1) {
                p->data.wins = p->data.wins + 1;
            }
            if (isLos == 1) {
                p->data.losses = p->data.losses + 1;
            }

            return 1;
        }
    }
    return 0;
}

/*
 * Destroys a BST. Every node in the BST will be deallocated, along with the BST itself.
 *
 * Parameters:
 * tree - the BST to destroy
 */
void destroyTree(struct Node *tree) {
    if (tree != 0) {
        destroyTree(tree->left);
        destroyTree(tree->right);
        free(tree->data.name);
        free(tree);
    }
}

/*
 * Prints out the data stored in the BST.
 * The function would print:
 *
 * a, 0, 1
 * b, 1, 0
 *
 * Parameters:
 * tree - the BST to print
 */
void printTree(struct Node *tree) {
    if (tree == NULL) {
        return;
    }
    printTree(tree->left);
    printf("%s, %d, %d\n", tree->data.name, tree->data.wins, tree->data.losses);
    printTree(tree->right);
}

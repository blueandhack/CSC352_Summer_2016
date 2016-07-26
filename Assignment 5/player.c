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
 * The function will print out "Out of memory."
 */
void outOfMemory() {
    fprintf(stderr, "Out of memory!");
}

/*
 * The function creates an empty binary search tree. It takes no parameters and returns
 * a pointer to a newly allocated struct TreeNode.
 */
struct TreeNode *createTree() {
    struct TreeNode *tree = (struct TreeNode *) malloc(sizeof(struct TreeNode));
    if (tree == NULL) {
        outOfMemory();
        return NULL;
    }
    tree->data.name = NULL;
    tree->left = NULL;
    tree->right = NULL;
    return tree;
}

/*
 * The function adds the provided element to the binary search tree.
 *
 * Parameters:
 * tree - the BST to add the element to
 * player - the element to add to the BST
 *
 * Returns: 1 if insert successful, and 0 if it was not.
 */
int insertPlayer(struct TreeNode *tree, struct Player *player) {

    if (tree->data.name == NULL) {
        tree->data.name = strdup(player->name);
        if (tree->data.name == NULL) {
            outOfMemory();
            return 0;
        }
        tree->data.losses = player->losses;
        tree->data.wins = player->wins;
        return 1;
    }

    struct TreeNode *newNode = (struct TreeNode *) malloc(sizeof(struct TreeNode));
    if (newNode == NULL) {
        outOfMemory();
        return 0;
    }

    newNode->data.losses = player->losses;
    newNode->data.wins = player->wins;
    newNode->right = NULL;
    newNode->left = NULL;
    newNode->data.name = strdup(player->name);

    if (newNode->data.name == NULL) {
        free(newNode);
        outOfMemory();
        return 0;
    }


    struct TreeNode *pointer = tree;

    while (1) {

        if (strcmp(pointer->data.name, player->name) < 0) {
            if (pointer->right == NULL) {
                pointer->right = newNode;
                return 1;
            }
            pointer = pointer->right;
        } else {
            if (pointer->left == NULL) {
                pointer->left = newNode;
                return 1;
            }
            pointer = pointer->left;
        }
    }
}

/*
 * The function finds an element in the binary search tree. It searches for the element
 * whose data.name value matches the name value passed to the function.
 *
 * Parameters:
 * tree - the BST to search in
 * name - the name to search for.
 *
 * Returns: 1 if the element was found in the BST, and 0 if it was not.
 */

int findPlayer(struct TreeNode *tree, char *name) {

    if (tree->data.name == NULL) {
        return 0;
    }
    struct TreeNode *pointer = tree;
    while (pointer != NULL) {
        if (strcmp(pointer->data.name, name) == 0) {
            return 1;
        } else if (strcmp(pointer->data.name, name) < 0) {
            pointer = pointer->right;
        } else {
            pointer = pointer->left;
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
 * player - the player to search for.
 *
 * Returns: 1 if the BST was updated, 0 if the BST was not updated.
 */
int updatePlayer(struct TreeNode *tree, struct Player *player) {

    if (tree->data.name == NULL) {
        return 0;
    }

    struct TreeNode *pointer = tree;
    while (pointer != NULL) {
        if (strcmp(pointer->data.name, player->name) == 0) {
            if (player->wins == 1) {
                pointer->data.wins = pointer->data.wins + 1;
            }
            if (player->losses == 1) {
                pointer->data.losses = pointer->data.losses + 1;
            }
            return 1;
        } else if (strcmp(pointer->data.name, player->name) < 0) {

            pointer = pointer->right;
        } else {

            pointer = pointer->left;
        }
    }
    return 0;
}

/*
 * The function destroys a BST. Every node in the BST will be deallocated, along with the BST itself.
 *
 * Parameters:
 * tree - the BST to destroy
 */
void destroyTree(struct TreeNode *tree) {
    if (tree != 0) {
        destroyTree(tree->left);
        destroyTree(tree->right);
        free(tree->data.name);
        free(tree);
    }
}

/*
 * The function prints out the data stored in the BST.
 * The function would print:
 *
 * a, 0, 1
 * b, 1, 0
 *
 * Parameters:
 * tree - the BST to print
 */
void printTree(struct TreeNode *tree) {
    if (tree == NULL) {
        return;
    }
    printTree(tree->left);
    printf("%s, %d, %d\n", tree->data.name, tree->data.wins, tree->data.losses);
    printTree(tree->right);
}

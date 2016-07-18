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

void destroyTree(struct Node *tree) {
    if (tree != 0) {
        destroyTree(tree->left);
        destroyTree(tree->right);
        free(tree->data.name);
        free(tree);
    }
}


void printTree(struct Node *tree) {
    if (tree == NULL) {
        return;
    }
    printTree(tree->left);
    printf("%s, %d, %d\n", tree->data.name, tree->data.wins, tree->data.losses);
    printTree(tree->right);
}

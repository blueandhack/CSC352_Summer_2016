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
    //printf("%d\n", sizeof(struct Node));
    //printf("%d\n", sizeof(struct Player));
    if (tree == NULL) {
        fprintf(stderr, "Out of memory!");
        return NULL;
    }
    tree->data.name = NULL;
    tree->left = NULL;
    tree->right = NULL;
    return tree;
}

int insertPlayer(struct Node *tree, char *name, int win, int los) {
    //printf("%d\n", tree->data.name == NULL);
    if (tree->data.name == NULL) {
        tree->data.name = name;
        tree->data.losses = los;
        tree->data.wins = win;
        return 1;
    }
    struct Node *node = (struct Node *) malloc(sizeof(struct Node));
    if (node == NULL) {
        fprintf(stderr, "Out of memory!");
        return 0;
    }
    node->data.name = name;
    node->data.losses = los;
    node->data.wins = win;
    node->right = NULL;
    node->left = NULL;
    //printf("%s",tree->data.name);
    struct Node *p = tree;
    struct Node *q = tree;
    int nav = 0;
    while (p != NULL) {
        //printf("%d\n", strcmp(p->data.name, name));
        if (strcmp(p->data.name, name) < 0) {
            q = p;
            nav = 0;
            p = p->right;
        } else {
            q = p;
            nav = 1;
            p = p->left;
        }
    }
    if (nav == 0) {
        q->right = node;
    } else {
        q->left = node;
    }
    return 1;
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

int updatePlayer(struct Node *tree, char *name, int win, int los) {

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

            if (win == 1) {
                p->data.wins = p->data.wins + 1;
            }
            if (los == 1) {
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
        free(tree);
    }
}


void printTree(struct Node *tree) {
    if (tree == NULL) {
        return;
    }
    printTree(tree->left);
    printf("%s %d %d\n", tree->data.name, tree->data.wins, tree->data.losses);
    printTree(tree->right);
}

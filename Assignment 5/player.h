/*
 * CSc 352 Summer 2016, Assignment 05
 *
 * Author: Yujia Lin
 *
 * Instructor: Lee Savoie
 *
 * ---
 */
#ifndef PLAYER_H
#define PLAYER_H

struct Player {
    char *name;
    int wins;
    int losses;
};

struct Node {
    struct Player data;
    struct Node *left;
    struct Node *right;
};

struct Node *createTree();

int insertPlayer(struct Node *tree, char *name, int isWin, int isLos);

int findPlayer(struct Node *tree, char *name);

int updatePlayer(struct Node *tree, char *name, int isWin, int isLos);

void destroyTree(struct Node *tree);

void printTree(struct Node *tree);

#endif //PLAYER_H

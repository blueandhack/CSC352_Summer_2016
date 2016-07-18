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

int main() {

    struct Node *tree = createTree();
    if (tree == NULL) {
        fprintf(stderr, "Out of memory!");
        return EXIT_FAILURE;
    }


    char nameOne[20];
    int scoreOne;
    int check;
    char nameTwo[20];
    int scoreTwo;

    int count = 0;

    while ((check = scanf("%s %d", nameOne, &scoreOne)) != EOF) {
        count++;
        if (check != 2) {
            fprintf(stderr, "Invalid scores entered\n");
            destroyTree(tree);
            return EXIT_FAILURE;
        }

        int checkTwo;

        checkTwo = scanf("\n%s %d", nameTwo, &scoreTwo);
        if (checkTwo != 2) {
            fprintf(stderr, "Invalid scores entered\n");
            destroyTree(tree);
            return EXIT_FAILURE;
        }
        if (scoreOne == scoreTwo) {
            fprintf(stderr, "Ties are not allowed\n");
            destroyTree(tree);
            return EXIT_FAILURE;
        }
        if (strcmp(nameOne, nameTwo) == 0) {
            fprintf(stderr, "Players cannot play against themselves\n");
            destroyTree(tree);
            return EXIT_FAILURE;
        }


//        printTree(tree);
//        insertPlayer(tree, nameOne, 0, 0);
//        insertPlayer(tree, nameTwo, 0, 0);
//        printf("\n");
//        printTree(tree);
//        printf("%d\n", count);
//        printf("Find One: %d ", findPlayer(tree, nameOne));
//        printf("Find Two: %d\n", findPlayer(tree, nameTwo));

        if (scoreOne > scoreTwo) {
            //printf("%s %d %s %d\n", nameOne, scoreOne, nameTwo, scoreTwo);
            if (findPlayer(tree, nameOne) == 1) {
                updatePlayer(tree, nameOne, 1, 0);
            } else {
                insertPlayer(tree, nameOne, 1, 0);
            }
            if (findPlayer(tree, nameTwo) == 1) {
                updatePlayer(tree, nameTwo, 0, 1);
            } else {
                insertPlayer(tree, nameTwo, 0, 1);
            }
        } else {
            //printf("%s %d %s %d\n", nameOne, scoreOne, nameTwo, scoreTwo);
            if (findPlayer(tree, nameOne) == 1) {
                updatePlayer(tree, nameOne, 0, 1);
            } else {
                insertPlayer(tree, nameOne, 0, 1);
            }
            if (findPlayer(tree, nameTwo) == 1) {
                updatePlayer(tree, nameTwo, 1, 0);
            } else {
                insertPlayer(tree, nameTwo, 1, 0);
            }
        }

    }


    if (count == 0 && check == -1) {
        return EXIT_SUCCESS;
    }


    printTree(tree);

    destroyTree(tree);

    return EXIT_SUCCESS;
}

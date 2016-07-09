/*
 * CSc 352 Summer 2016, Assignment 04
 *
 * Author: Yujia Lin
 *
 * Instructor: Lee Savoie
 *
 * ---
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "llist.h"

/*
 * The function will insert a x value to linked list
 */
void insert(struct LList *list, int x) {
    struct LList_data *data = (struct LList_data *) malloc(sizeof(struct LList_data));
    // If it can not create new memory unit, then return.
    if (data == NULL) {
        fprintf(stderr, "Out of memory!");
        return;
    }
    data->y = 0;
    data->x = x;
    // Called LList_push_front function to insert element to linked list.
    LList_push_front(list, *data);
    free(data);
}

/*
 * The function will find a x value in the linked list.
 * If find it out, then it should change the y value (add 1 for previous value).
 */
void find(struct LList *list, int x) {
    struct LList_data *data = (struct LList_data *) malloc(sizeof(struct LList_data));
    // If it can not create new memory unit, then return.
    if (data == NULL) {
        fprintf(stderr, "Out of memory!");
        return;
    }
    // Find x value from the linked list. If find, it will update y value.
    if (LList_find(list, x, data) == true) {
        struct LList_data *newData = (struct LList_data *) malloc(sizeof(struct LList_data));
        if (newData == NULL) {
            fprintf(stderr, "Out of memory!");
            return;
        }
        newData->x = data->x;
        newData->y = (data->y) + 1;
        // Called LList_update function to update y value in the linked list.
        LList_update(list, *newData);
        printf("%d, %d\n", newData->x, newData->y);
        free(newData);
        free(data);
    } else {
        free(data);
    }
}

/*
 * The function will remove a x value in the linked list.
 * If find it out, then it should remove the item from the linked list.
 */
void removeOne(struct LList *list, int x) {
    struct LList_data *data = (struct LList_data *) malloc(sizeof(struct LList_data));
    // If it can not create new memory unit, then return.
    if (data == NULL) {
        fprintf(stderr, "Out of memory!");
        return;
    }
    if (LList_remove(list, x, data) == true) {
        printf("%d, %d\n", data->x, data->y);
    }
    free(data);

}

/*
 * The main function will receive user's input.
 * First, it will create a empty linked list for user.
 */
int main() {

    char ch;
    int x;
    int y;
    int z;
    struct LList *list = LList_create();
    // If it can not create new memory unit, then return.
    if (list == NULL) {
        fprintf(stderr, "Out of memory!");
        return EXIT_FAILURE;
    }

    while (scanf("\n%c", &ch) != EOF) {
        if (ch == 'c' || ch == 'C') {
            /*
             * If the user inputs 'C' or 'c',
             * it will destroy the current linked list
             * (including freeing all memory allocated for that list) and create a new, empty list.
             */
            LList_destroy(list);
            list = LList_create();
        } else if (ch == 'a' || ch == 'A') {
            /*
             * If the user inputs 'A' or 'a', they will then enter an integer.
             * It should add a new entry to the head of the list where x = the integer they entered and y = 0.
             */
            int check = scanf("%d", &x);
            if (check != 1) {
                fprintf(stderr, "Invalid input\n");
                LList_destroy(list);
                return EXIT_FAILURE;
            }
            insert(list, x);
        } else if (ch == 'f' || ch == 'F') {
            /*
             * If the user inputs 'F' or 'f', they will then enter an integer.
             * It should search through the list and find the first entry for which x = the number they entered.
             * It should then increment y for that entry and write it back to the list. The entry should not change positions in the list;
             * it just want to update the value of y in place. It should then print out the updated value of x and y in the format "x, y\n" - so if x was 3 and y was 5 after it incremented it,
             * it would print "3, 5", followed by a new line. If it do not find a matching entry in the list, it should not print anything.
             */
            int check = scanf("%d", &y);
            if (check != 1) {
                fprintf(stderr, "Invalid input\n");
                LList_destroy(list);
                return EXIT_FAILURE;
            }
            find(list, y);
        } else if (ch == 'r' || ch == 'R') {
            /*
             * If the user inputs 'R' or 'r', they will then enter an integer.
             * It should remove the first entry from the list for which x equals the number they entered.
             * It should also print out the entry it removed in the format "x, y\n".
             * If there is no matching entry in the list, it should do nothing, and it shouldn't print out anything.
             */
            int check = scanf("%d", &z);
            if (check != 1) {
                fprintf(stderr, "Invalid input\n");
                LList_destroy(list);
                return EXIT_FAILURE;
            }
            removeOne(list, z);
        } else if (ch == 'p' || ch == 'P') {
            /*
             * If the user inputs 'P', or 'p',
             * it should print out the entire list, starting at the head.
             * It can use the LList_print function (described in llist.h) to do this.
             * llist.h describes the format that the list should be printed in.
             */
            LList_print(list);
        } else {
            /*
             * If the input is invalid at any point,
             * it prints an error to stderr and exit the program with a non-zero return value.
             */
            fprintf(stderr, "Invalid input\n");
            LList_destroy(list);
            return EXIT_FAILURE;
        }

    }

    LList_destroy(list);

    return EXIT_SUCCESS;
}
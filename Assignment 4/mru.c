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
 * The function will add a element to the linked list.
 * If it found x value in the linked list, then update y value.
 * If it not found x value in the linked list, add new x value to the linked list.
 */
void addElement(struct LList *list, int x) {
    struct LList_data *data = (struct LList_data *) malloc(sizeof(struct LList_data));
    // If it can not create new memory unit, then return.
    if (data == NULL) {
        fprintf(stderr, "Out of memory!");
        return;
    }
    data->x = x;
    data->y = 1;
    // Find x value from the linked list. If find, it will update y value.
    if (LList_find(list, x, data) == true) {
        LList_remove(list, x, data);
        data->y = (data->y) + 1;
        LList_push_front(list, *data);
        free(data);
    } else {
        // Called LList_push_front function to insert element to linked list.
        LList_push_front(list, *data);
        free(data);
    }
}

/*
 * The main function will receive user's input.
 * First, it will create a empty linked list for user.
 */
int main() {

    int x;
    int check;
    struct LList *list = LList_create();
    // If it can not create new memory unit, then return.
    if (list == NULL) {
        return EXIT_FAILURE;
    }

    while ((check = scanf("\n%d", &x)) != EOF) {
        if (check != 1) {
            fprintf(stderr, "This program only accepts integers as input.\n");
            LList_destroy(list);
            return EXIT_FAILURE;
        }
        addElement(list, x);
    }

    LList_print(list);

    LList_destroy(list);
    return EXIT_SUCCESS;
}
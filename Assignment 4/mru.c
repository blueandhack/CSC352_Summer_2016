#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "llist.h"

void addElement(struct LList *list, int x) {
    struct LList_data *data = (struct LList_data *) malloc(sizeof(struct LList_data));
    if (data == NULL) {
        return;
    }
    data->x = x;
    data->y = 1;
    if (LList_find(list, x, data) == true) {
        LList_remove(list, x, data);
        data->y = (data->y) + 1;
        LList_push_front(list, *data);
    } else {
        LList_push_front(list, *data);
    }
}


int main() {

    int x;
    int check;
    struct LList *list = LList_create();
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
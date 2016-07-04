#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "llist.h"

void insert(struct LList *list, int x) {
    struct LList_data *data = (struct LList_data *) malloc(sizeof(struct LList_data));
    if (data == NULL) {
        return;
    }
    data->y = 0;
    data->x = x;
    LList_push_front(list, *data);
}

void find(struct LList *list, int x) {
    struct LList_data *data = (struct LList_data *) malloc(sizeof(struct LList_data));
    if (data == NULL) {
        return;
    }
    if (LList_find(list, x, data) == true) {
        struct LList_data *newData = (struct LList_data *) malloc(sizeof(struct LList_data));
        if (newData == NULL) {
            return;
        }
        newData->x = data->x;
        newData->y = (data->y) + 1;
        LList_update(list, *newData);
        printf("%d, %d\n", newData->x, newData->y);
        free(newData);
    } else {
        free(data);
    }
}

void removeOne(struct LList *list, int x) {
    struct LList_data *data = (struct LList_data *) malloc(sizeof(struct LList_data));
    if (data == NULL) {
        return;
    }
    if (LList_remove(list, x, data) == true) {
        printf("%d, %d\n", data->x, data->y);
    }
    free(data);

}

int main() {

    char ch;
    int x;
    int y;
    int z;
    struct LList *list = LList_create();
    if (list == NULL) {
        return EXIT_FAILURE;
    }

    while (scanf("\n%c", &ch) != EOF) {
        if (ch == 'c' || ch == 'C') {
            LList_destroy(list);
            list = LList_create();
        } else if (ch == 'a' || ch == 'A') {
            scanf("%d", &x);
            insert(list, x);
        } else if (ch == 'f' || ch == 'F') {
            scanf("%d", &y);
            find(list, y);
        } else if (ch == 'r' || ch == 'R') {
            scanf("%d", &z);
            removeOne(list, z);
        } else if (ch == 'p' || ch == 'P') {
            LList_print(list);
        } else {
            fprintf(stderr, "Invalid input\n");
            LList_destroy(list);
            return EXIT_FAILURE;
        }

    }

    LList_destroy(list);

    return EXIT_SUCCESS;
}
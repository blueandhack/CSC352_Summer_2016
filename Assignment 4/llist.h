#ifndef LLIST_H
#define LLIST_H

/*
 * This struct holds the data stored in each node of the list.  Every node stores
 * two integers, named x and y.  When searching through the list, you will use x
 * as the "key": you will be provided an integer to search for, and you will search
 * for the first node where x matches the integer you are searching for.
 */
struct LList_data {
  int x;
  int y;
};

struct LList {
  // You must fill in this struct with any data you need to maintain a linked
  // list.  You may need to create additional structs as well.
    struct LList_data data;
    struct LList *next;
};

/*
 * This function creates an empty linked list.  It takes no parameters and returns
 * a pointer to a newly allocated struct LList.
 */
struct LList * LList_create();

/*
 * This function adds the provided element to the front (head) of the linked list.
 *
 * Parameters:
 * list - the list to add the element to
 * data - the element to add to the list
 */
void LList_push_front(struct LList * list, struct LList_data data);

/*
 * This function finds an element in the linked list.  It searches for the first element
 * whose data.x value matches the x value passed to the function.
 *
 * Parameters:
 * list - the list to search in
 * x - the number to search for.  This function searches for the first element in the
 *     list such that the x value stored in that node equals this number.
 * data - a pointer to a struct LList_data.  This will be populated with the data from the
 *        node that matches x, if one is found.  If x is not found in the list, data is
 *        not changed.
 *
 * Returns: 1 if the element was found in the list, and 0 if it was not.
 */
int LList_find(struct LList * list, int x, struct LList_data * data);

/*
 * Updates an element in the list in place.  Nothing is added or removed from the list.
 * This function searches through the list to find the first element such that element.x
 * equals newData.x.  If it finds such an element, that element is set to the value of
 * newData.  The element should not change positions in the list; it should be updated
 * where it is, without moving it.
 *
 * Parameters:
 * list - the list to update
 * newData - the element to update.  This function will update the first element such
 *           that newData.x equals the x stored in that element.  The element will be
 *           updated to have the same x and y values as newData.
 *
 * Returns: 1 if the list was updated (newData.x was found), 0 if the list was not updated.
 */
int LList_update(struct LList * list, struct LList_data newData);

/*
 * Removes the first element of the list whose x value equals the x passed to this function.
 *
 * Parameters:
 * list - the list to remove the element from
 * x - the element to remove.  This function will remove the first element whose x value matches
 *     this number.
 * data - a pointer to a struct LList_data.  If an element is removed from the list, its data
 *        will be stored here.  Otherwise, data will be unchanged.
 *
 * Returns: 1 if an element was removed from the list, and 0 if an element was not removed from the list.
 */
int LList_remove(struct LList * list, int x, struct LList_data * data);

/*
 * Destroys a list.  Every node in the list will be deallocated, along with the list itself.
 *
 * Parameters:
 * list - the list to destroy
 */
void LList_destroy(struct LList * list);

/*
 * Prints out the data stored in the list.  Starting at the head of the list, each element
 * is printed in the format "x, y" on a separate line (there is a newline after each element).
 * For example, in a two element list where the first node contained data.x = 1, data.y = 2
 * and the second node contained data.x = 7, data.y = 8, this function would print:
 *
 * (1, 2)
 * (7, 8)
 *
 * Parameters:
 * list - the list to print
 */
void LList_print(struct LList * list);

#endif

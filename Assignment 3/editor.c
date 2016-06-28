/*
 * CSc 352 Summer 2016, Assignment 3
 *
 * Author: Yujia Lin
 *
 * Instructor: Lee Savoie
 *
 * ---
 */
#include <stdio.h>
#include <stdlib.h>

#define LENGTH (100)

/*
 * The function is will read newStr array and put newStr's data to str array.
 * After is will print out the string.
 */
void fillOut(char newStr[], char str[]) {
    int i;
    for (i = 0; i < LENGTH; ++i) {
        if (str[i] == '\0') {
            newStr[i] = '\0';
            break;
        }
        str[i] = newStr[i];
    }
    for (i = 0; i < LENGTH; ++i) {
        if (str[i] == '\0') {
            break;
        }
        printf("%c", str[i]);
    }
    printf("\n");
}

/*
 * The function will delete a character from a string, and store the new string to a new array.
 * After call fillOut function.
 */
void deleteMode(char str[]) {
    char key;
    char newStr[LENGTH];
    int i, j, flag = -1;
    scanf("\n%c", &key);
    for (i = 0; i < LENGTH; ++i) {
        if (str[i] == '\0') {
            break;
        }
        if (str[i] == key) {
            flag = i;
            break;
        }
    }
    for (i = 0, j = 0; i < LENGTH; ++i) {
        if (i != flag) {
            newStr[j] = str[i];
            j++;
        }
    }
    fillOut(newStr, str);
}

/*
 * The function will replace a character to a new character from a string.
 * After print out the array.
 */
void replaceMode(char str[]) {
    char key;
    char ch;

    int i;
    scanf("\n%c %c", &key, &ch);
    for (i = 0; i < LENGTH; ++i) {
        if (str[i] == key) {
            str[i] = ch;
            break;
        }
    }

    for (i = 0; i < LENGTH; ++i) {
        if (str[i] == '\0') {
            break;
        }
        printf("%c", str[i]);
    }
    printf("\n");
}

/*
 * The function will reverse the string, and it put the new string to a new array.
 * After call fillOut function.
 */
void reverseString(char str[]) {
    int i, j;
    int lastIndex = 0;
    char newStr[LENGTH];
    for (i = 0; i < LENGTH; ++i) {
        if (str[i] == '\0') {
            lastIndex = i;
            break;
        }
    }

    for (i = lastIndex - 1, j = 0; i >= 0; --i, j++) {
        newStr[j] = str[i];
    }
    newStr[j] = '\0';
    fillOut(newStr, str);
}

/*
 * The main function will read user's input. The user should input a string and select a mode.
 */
int main() {
    char str[LENGTH];
    char key;
    scanf("%[^\n]", str);
    while (scanf("\n%c", &key) != EOF) {

        if (key == 'q') {
            break;
        }
        else if (key == '-') {
            deleteMode(str);
        }
        else if (key == '~') {
            replaceMode(str);
        }
        else if (key == '^') {
            reverseString(str);
        } else {
            fprintf(stderr, "Invalid choice");
            break;
        }
    }
    if (key != 'q') { fprintf(stderr, "Could not read user choice."); }


    return EXIT_SUCCESS;
}
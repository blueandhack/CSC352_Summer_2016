#include <stdio.h>
#include <stdlib.h>

/*
 * The function will allow the user to print a shape in asterisks. The function should not print out anything except the shape.
 * And the function can allow user print a square, a triangle and a rectangle. Also, it can print out a parallelogram.
 * If the user enters 's', the function print out a square.
 * The number following the 's' indicates the size of the square.
 * If the user enters 't', the function should print out a triangle.
 * The number following the 't' indicates the size of the triangle.
 * If the user enters 'r', the function should print out a rectangle.
 * The two numbers following the 'r' indicate the height and width of the rectangle, in that order.
 * After printing the shape, the function print a new line and then print the main menu again.
 * If the user inputs an incorrect entry (a character other than 's', 't', or 'r', a number less than or equal to zero, etc.),
 * the function print an error message to stderr and then print the main menu.
 */

void ShapePrinter() {
    char ch;
    int i = 0;
    int j = 0;
    scanf("\n%c", &ch);
    if (ch == 's') {
        int line = 0;
        scanf("%d", &line);
        if (line <= 0) {
            fprintf(stderr, "Invalid size: (%d)\n", line);
        } else {
            for (i = 0; i < line; i++) {
                for (j = 0; j < line; j++) {
                    printf("*");
                }
                printf("\n");
            }
        }
    } else if (ch == 't') {
        int line = 0;
        scanf("%d", &line);
        if (line <= 0) {
            fprintf(stderr, "Invalid size: (%d)\n", line);
        } else {
            for (i = 0; i < line; i++) {
                for (j = 0; j <= i; j++) {
                    printf("*");
                }
                printf("\n");
            }
        }
    } else if (ch == 'r') {
        int height = 0;
        int width = 0;
        scanf("%d %d", &height, &width);
        if (height <= 0 || width <= 0) {
            fprintf(stderr, "Invalid size: (%d, %d)\n", height, width);
        } else {
            for (i = 0; i < height; i++) {
                for (j = 0; j < width; j++) {
                    printf("*");
                }
                printf("\n");
            }
        }
    } else if (ch == 'p') {
        int height = 0;
        int width = 0;
        int k = 0;
        scanf("%d %d", &height, &width);
        if (height <= 0 || width <= 0) {
            fprintf(stderr, "Invalid size: (%d, %d)\n", height, width);
        } else {
            for (i = 0; i < height; i++) {
                for (k = 0; k < i; ++k) {
                    printf(" ");
                }
                for (j = 0; j < width; j++) {
                    printf("*");
                }
                printf("\n");
            }
        }
    } else {
        fprintf(stderr, "Invalid shape selection: %c\n", ch);
    }
}

/*
 * For the function, the user will enter a char and the function will print the entire alphabet or number set,
 * in continuous order until the function would return to the specified char.
 * After doing this, the function should print out a newline and then return to the main menu.
 * If the user types something other than a letter or number, the function print an error message to stderr and return to the main menu.
 */

void CircularChars() {
    char ch;
    int i = 0;
    int j = 0;
    scanf("\n%c", &ch);
    if (ch < 58 && ch > 47) {
        for (i = ch; i < 58; i++) {
            printf("%c", i);
        }
        for (j = 48; j < ch; j++) {
            printf("%c", j);
        }
        printf("\n");
    } else if (ch < 91 && ch > 64) {
        for (i = ch; i < 91; i++) {
            printf("%c", i);
        }
        for (j = 65; j < ch; j++) {
            printf("%c", j);
        }
        printf("\n");
    } else if (ch < 123 && ch > 96) {
        for (i = ch; i < 123; i++) {
            printf("%c", i);
        }
        for (j = 97; j < ch; j++) {
            printf("%c", j);
        }
        printf("\n");
    } else {
        fprintf(stderr, "Invalid character: %c\n", ch);
    }
}

/*
 * For the function, the user will enter two numbers and the function should print all numbers between the two numbers that have exactly two distinct factors.
 * This search should be inclusive, meaning the two numbers the user enters should be checked, along with the numbers between them.
 * The function should ignore those two factors.
 * The function looking for distinct factors, meaning that if a number can be divided by one of its factors multiple times,
 * that factor only counts once (for example, 4 can be divided by 2 twice, but 2 only counts as one factor).
 */

void Factors() {
    int a, b = 0;
    int i, j = 0;
    scanf("%d %d", &a, &b);
    if ((a <= 0 && b <= 0) || a < 0 || a > b) {
        fprintf(stderr, "Invalid entry.\n");
    } else {
        int flag = 0;
        for (i = a; i <= b; ++i) {
            for (j = 2; j < i; ++j) {
                if (i % j == 0) {
                    flag++;
                }
            }
            if (flag == 2) {
                printf("%d\n", i);
            }
            flag = 0;
        }
    }
}

/*
 * The function is main function. It will print main menu.
 * When the program starts, it should display the following menu to the user.
 * If the user selects 1, 2, or 3, the program should transition to the corresponding function above.
 * If the user enters 4, or if there is no more input, the program should exit.
 * If the user enters anything else, the program should print an error message to stderr and display the menu again.
 */

int main() {

    int userNumber = 0;

    printf("1. Shape Printer\n");
    printf("2. Circular Chars\n");
    printf("3. Factors\n");
    printf("4. Exit\n");
    printf("What would you like to do? \n");

    while (scanf("%d", &userNumber) != EOF) {

        if (userNumber == 1) {
            ShapePrinter();
        } else if (userNumber == 2) {
            CircularChars();
        } else if (userNumber == 3) {
            Factors();
        } else if (userNumber == 4) {
            break;
        } else {
            fprintf(stderr, "Invalid choice.\n");
        }

        printf("1. Shape Printer\n");
        printf("2. Circular Chars\n");
        printf("3. Factors\n");
        printf("4. Exit\n");
        printf("What would you like to do? \n");
    }
    return EXIT_SUCCESS;
}




#include <stdio.h>
#include <stdlib.h>

void ShapePrinter();

void CircularChars();

void Factors();

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
        int i = 0;
        int j = 0;
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
    } else {
        fprintf(stderr, "Invalid shape selection: %c\n", ch);
    }
}

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


#include <stdio.h>
#include <stdlib.h>

// Write a C program to get the C version you are using

void drawBox(char inChar, int mWidth, int mHeight) {
    for (int i = 0; i < mHeight; i++) {
        for (int j = 0; j < mWidth; j++) {
            if ((j > 0) && (j < mWidth - 1) && (i > 0) && (i < mHeight - 1))
                printf(" ");
            else
                printf("%c", inChar);
        }
        printf("\n");
    }
}

void drawRightTriangle(char inChar) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%c", inChar);
            if (j >= i)
                break;
        }
        printf("\n");
    }
}

void drawPyramid(char inChar, int area) {
    int rightArea = area / 2;
    int leftArea = area / 2;

    for (int i = 0; i <= area / 2; i++) {
        if (i > 0) {
            rightArea -= 1;
            leftArea += 1;
        }
        for (int j = 0; j <= area; j++) {
            if ((j <= (leftArea)) && (j >= (rightArea)))
                printf("%c", inChar);
            else
                printf(" ");
        }
        printf("\n");   
    }
}

void drawLetterF(char inChar) {
    for (int i = 0; i < 7; i++) {
        switch (i) {
        case 0: {
            for (int j = 0; j < 6; j++)
                printf("%c", inChar);
            printf("\n");
            break;
        }
        case 3: {
            for (int j = 0; j < 5; j++)
                printf("%c", inChar);
                printf("\n");
            break;
        }
        default:
            printf("%c\n", inChar);
            break;
        }
        
    }
}

void drawLetterC(char inChar) {
    for (int i = 0; i < 9; i++) {
        switch (i) {
        case 0: {
            for (int j = 0; j < 11; j++)
                (j < 3 || j > 8) ? printf(" ") : printf("%c", inChar);
            printf("\n");
            break;
        }
        case 1: {
            for (int j = 0; j < 11; j++)
                ((j > 0 && j < 3) || j > 8) ? printf("%c", inChar) : printf(" ");
            printf("\n");
            break;
        }
        case 7: {
            for (int j = 0; j < 11; j++)
                ((j > 0 && j < 3) || j > 8) ? printf("%c", inChar) : printf(" ");
            printf("\n");
            break;
        }
        case 8: {
            for (int j = 0; j < 11; j++)
                (j < 3 || j > 8) ? printf(" ") : printf("%c", inChar);
            printf("\n");
            break;
        }
        default:
            printf("%c\n", inChar);
            break;
        }
    }
}

int main(void) {
    drawPyramid('#', 12);

    return 0;
}
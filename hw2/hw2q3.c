/*-------------------------------------------------------------------------
  Include files:
--------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>



/*=========================================================================
  Constants and definitions:
==========================================================================*/

/* put your #defines and typedefs here*/



/*-------------------------------------------------------------------------
  The main program. (describe what your program does here)
 -------------------------------------------------------------------------*/

char get_character ();
char get_axis ();
void up (char character, int grades[]);
void down (char character, int grades[]);
void right (char character, int grades[]);
void left (char character, int grades[]);
void udrl (char axis, char character, int grades[]);

int main()
{
    char character = get_character();
    char axis = get_axis();
    printf("Please enter grades:\n");
    int grades[10] = {0}; // the index represents the grade
    int grade;
    while (scanf("%d", &grade) != EOF) {
        grades[grade]++; // counts the number of times of the grade
    }
    for (int i=1 ; i<10 ; i++) {
        if (grades[i] > grades[0]) {
            grades[0] = grades[i]; // grades[0] is the max value of grades
        }
    }
    printf("Histogram:\n");
    udrl(axis, character, grades); // activates the axis form

    return 0;
}

char get_character () { // asks for a character and gets one
    printf("Please enter a character:\n");
    char character;
    scanf(" %c", &character);
    return character;
}

char get_axis () {//asks for an axis, gets one and asks again when invalid
    printf("Please enter histogram axis:(U/D/R/L)\n");
    char axis;
    scanf(" %c", &axis);
    while (axis != 'U' && axis != 'D' && axis != 'R' && axis != 'L') {
        printf("Wrong direction, try again!\n");
        printf("Please enter histogram axis:(U/D/R/L)\n");
        scanf(" %c", &axis);
    }
    return axis;
}

void up (char character, int grades[]) {
    printf("1 2 3 4 5 6 7 8 9\n"); // first, is prints the grade scale
    for (int n=1 ; n<=grades[0] ; n++) { // n represents the row number
        for (int i=1 ; i<=9 ; i++) { // i represents the column number
            if (i < 9) {
                if (grades[i] >= n) {
                    printf("%c ", character);
                } else {
                    printf("  ");
                }
            } else { // when arrives to the last column
                if (grades[i] >= n) {
                    printf("%c\n", character);
                } else {
                    printf(" \n");
                }
            }
        }
    }

}

void down (char character, int grades[]) {
    for (int n=1 ; n<=grades[0] ; n++) { // n represents the row number
        for (int i=1 ; i<=9 ; i++) { // i represents the column number
            if (i < 9) {
                if  (grades[i] + (n-1) >= grades[0]) {
                                // n-1 because the initial value of n is 1
                    printf("%c ", character);
                } else {
                    printf("  ");
                }
            } else { // when arrives to the last column
                if (grades[i] + (n-1) >= grades[0]) {
                    printf("%c\n", character);
                } else {
                    printf(" \n");
                }
            }
        }
    }
    printf("1 2 3 4 5 6 7 8 9"); // in the end it prints the grade scale
}

void right (char character, int grades[]) {
    for (int i=1 ; i<=9 ; i++) { // i represents the rows
        for (int n=1 ; n<=grades[0] ; n++) { // n represents the columns
            if (grades[0] - n > 0) {
                if (grades[i] + (n-1) >= grades[0]) {
                                // n-1 because the initial value of n is 1
                    printf("%c ", character);
                } else {
                    printf("  ");
                }
            } else { // when arrives to the last column
                if (grades[i] + (n-1) >= grades[0]) {
                    printf("%c %d\n", character, i); //at last, the grade
                } else {
                    printf("  %d\n", i);
                }
            }
        }
    }
}

void left (char character, int grades[]) {
    for (int i=1 ; i<=9 ; i++) { // i represents the rows
        printf("%d ", i); // at first, the grade
        for (int n=1 ; n<=grades[0] ; n++) { // n represents the columns
            if (n < grades[0]) {
                if (grades[i] >= n) {
                    printf("%c ", character);
                } else {
                    printf("  ");
                }
            } else { // when arrives to the last column
                if (grades[i] >= n) {
                    printf("%c\n", character);
                } else {
                    printf(" \n");
                }
            }
        }
    }
}

void udrl (char axis, char character, int grades[]) {
    switch (axis) { // unites all the four of the axis functions into one
    case 'U':
        up(character, grades);
        break;
    case 'D':
        down(character, grades);
        break;
    case 'R':
        right(character, grades);
        break;
    case 'L':
        left(character, grades);
        break;
    }
}

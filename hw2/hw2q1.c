/*-------------------------------------------------------------------------
  Include files:
--------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdbool.h>



/*=========================================================================
  Constants and definitions:
==========================================================================*/

/* put your #defines and typedefs here*/

#define N 4

/*-------------------------------------------------------------------------
  The main program. (describe what your program does here)
 -------------------------------------------------------------------------*/

int is_strong(), space_rank();

int main()
{
    int mat[N][N];
    int strong_counter = 0, space_rank_counter = 0;
    printf("Please enter a matrix:\n");
    for (int i=0 ; i<N ; i++) { // i is the rows
        for (int j=0 ; j<N ; j++) { // j is the columns
            scanf("%d", &mat[i][j]); // gets the value from the user
        }
    }
    for (int i=0 ; i<N ; i++) {
        for (int j=0 ; j<N ; j++) {
            strong_counter += is_strong(mat, i, j); // sums the strongs
            space_rank_counter += space_rank(mat, i, j);//sums the  spaces
        }
    }
    printf("Strong elements: %d\n", strong_counter);
    printf("Space rank: %d\n", space_rank_counter);
    return 0;
}

int is_strong (int mat[N][N], int row, int column) {
    bool smaller_surrounding;
    smaller_surrounding =
    // an edge automatically returns 1, otherwise it checks the conditions
    ((row == 0) || (mat[row][column] > mat[row-1][column])) &&
    ((row == N-1) || (mat[row][column] > mat[row+1][column])) &&
    ((column == 0) || (mat[row][column] > mat[row][column-1])) &&
    ((column == N-1) || (mat[row][column] > mat[row][column+1]));
    return smaller_surrounding;
    }

int space_rank (int mat[N][N], int row, int column) {
    int difference;
    int abs_diff;
    bool not_last_column = (column != N-1); // 0 when it's last column
    difference= (mat[row][column] - mat[row][column+not_last_column]);
    //calculates the difference and in the last column it subtracts itself
    abs_diff = ((difference < 0) * difference * (-1)) +
    // 1 * negative * (-1) goes to positive
    ((difference >= 0) * difference);
    // 1 * positive stays positive
    return abs_diff;
    }

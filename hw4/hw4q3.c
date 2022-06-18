/*-------------------------------------------------------------------------
  Include files:
--------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>



/*=========================================================================
  Constants and definitions:
==========================================================================*/

/* put your #defines and typedefs here*/

#define N 5
#define INITIAL_VALUE -1

void enter_values (int matrix_a[N][N]);
void initialize_arr (int arr[], int n);
bool legal (int job_employee[N], int matrix_a[N][N], int index, int j);
int possible_option (int job_employee[N], int matrix_a[N][N], int index);

/*-------------------------------------------------------------------------
  The main program. (describe what your program does here)
 -------------------------------------------------------------------------*/
int main()
{
    int matrix_a[N][N];
    enter_values(matrix_a);
    int job_employee[N];
    initialize_arr(job_employee, N);
    int the_result;
    the_result = possible_option(job_employee, matrix_a, 0);
    printf("The result is %d\n", the_result);

    return 0;
}
// enters values from the user into the matrix
void enter_values (int matrix_a[N][N]) {
    printf("Enter the matrix:\n");
    for (int i=0 ; i<N ; i++) {
        for (int j=0 ; j<N ; j++) {
            scanf("%d", &matrix_a[i][j]);
        }
    }
}
// initializes the array to values of -1
void initialize_arr (int arr[], int n) {
    for (int i=0 ; i<n ; i++) {
        arr[i] = INITIAL_VALUE;
    }
}

// j represents job_employee[index]
bool legal (int job_employee[N], int matrix_a[N][N], int index, int j) {
    bool once = true;
    for (int i=0 ; i<index ; i++) {
        if (j == job_employee[i]) {
            once = false;
        }
    }
    if (once == false) {
        return false;
    }
    if (matrix_a[j][index] == 0) {
        return false;
    }
    return true;
}
// the backtracking counts the number of all the possible options
int possible_option (int job_employee[N], int matrix_a[N][N], int index) {
    if (index >= N) {
        return 1;
    }
    int counter = 0;
    for (int j=0 ; j<N ; j++) {
        if (legal(job_employee, matrix_a, index, j) == true) {
            job_employee[index] = j;
            index++;
            counter += possible_option(job_employee, matrix_a, index);
            index--;
        }
    }
    return counter;
}

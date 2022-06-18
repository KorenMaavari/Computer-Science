/*-------------------------------------------------------------------------
  Include files:
--------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>



/*=========================================================================
  Constants and definitions:
==========================================================================*/

/* put your #defines and typedefs here*/

#define INITIAL_VALUE -1

int get_len_of_arr ();
void enter_values_into_arr (int arr[], int len_of_arr);
void merging (int arr_a[], int len_of_arr_a, int arr_b[], int len_of_arr_b, int arr_c[]);
void pre_merge_sort (int arr[], int len_of_arr, int aux_arr[]);
void merge_sort (int arr[], int len_of_arr);
void what_is_x (int arr[], int len_of_arr);

/*-------------------------------------------------------------------------
  The main program. (describe what your program does here)
 -------------------------------------------------------------------------*/
int main()
{
    int len_of_arr = get_len_of_arr();
    int *arr = malloc(len_of_arr * sizeof(int));
    if (arr == NULL) {
        printf("Error!\n");
    }
    enter_values_into_arr(arr, len_of_arr);
    merge_sort(arr, len_of_arr);
    what_is_x(arr, len_of_arr);
    free(arr);

    return 0;
}
// gets the length of array from the user
int get_len_of_arr () {
    int input;
    printf("Enter the length of the array:\n");
    scanf("%d", &input);
    return input;
}
// enters the values from the user into the array
void enter_values_into_arr (int arr[], int len_of_arr) {
    printf("Enter the array:\n");
    for (int i=0 ; i<len_of_arr ; i++) {
        scanf("%d", &arr[i]);
    }
}
// does the merge function
void merging (int arr_a[], int len_of_arr_a, int arr_b[], int len_of_arr_b, int arr_c[]) {
    int index_a = 0, index_b = 0, index_c = 0;
    while ((index_a<len_of_arr_a) && (index_b<len_of_arr_b)) {
        if (arr_a[index_a] < arr_b[index_b]) {
            arr_c[index_c] = arr_a[index_a];
            index_a++;
        } else {
            arr_c[index_c] = arr_b[index_b];
            index_b++;
        }
        index_c++;
    }
    while (index_a<len_of_arr_a) {
        arr_c[index_c] = arr_a[index_a];
        index_a++;
        index_c++;
    }
    while (index_b<len_of_arr_b) {
        arr_c[index_c] = arr_b[index_b];
        index_b++;
        index_c++;
    }
}
// divides the array repeatedly until the merge is valid
void pre_merge_sort (int arr[], int len_of_arr, int aux_arr[]) {
    if (len_of_arr<2) {
        return;
    }
    pre_merge_sort(arr, len_of_arr/2, aux_arr);
    pre_merge_sort(arr+(len_of_arr/2), len_of_arr-(len_of_arr/2), aux_arr);
    merging(arr, len_of_arr/2, arr+(len_of_arr/2), len_of_arr-(len_of_arr/2), aux_arr);
    memcpy(arr, aux_arr, len_of_arr * sizeof(int));
}
// does the merge sort
void merge_sort (int arr[], int len_of_arr) {
    int *temp_arr = malloc(len_of_arr * sizeof(int));
    if (temp_arr == NULL) {
        printf("Error!\n");
    }
    pre_merge_sort(arr, len_of_arr, temp_arr);
    free(temp_arr);
}
// finds the value of x if it exists
void what_is_x (int arr[], int len_of_arr) {
    int x = INITIAL_VALUE;
    for (int i=0 ; i <= arr[len_of_arr-1] ; i++) {
        int counter = 0;
        for (int j=0 ; j<len_of_arr ; j++) {
            if (arr[j] >= i) {
                counter++;
            }
        }
        if (i == counter) {
            x = i;
            break;
        }
    }
    if (x == INITIAL_VALUE) {
        printf("The array is not recommended\n");
    } else {
        printf("The array is recommended and x = %d\n", x);
    }
}

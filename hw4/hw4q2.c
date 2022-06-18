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

int get_len_of_arr (int len_of_arr);
void enter_values_into_arr (int len_of_arr, char *arr);
bool is_it_palindrome (int len_of_arr, char *arr, int index, bool res);

/*-------------------------------------------------------------------------
  The main program. (describe what your program does here)
 -------------------------------------------------------------------------*/
int main()
{
    int len_of_arr = 0;
    len_of_arr = get_len_of_arr(len_of_arr);
    char *arr = malloc(len_of_arr * sizeof(char));
    enter_values_into_arr(len_of_arr, arr);
    if (is_it_palindrome(len_of_arr, arr, len_of_arr-1, true) == true) {
        printf("A palindrome\n");
    } else {
        printf("Not a palindrome\n");
    }
    free(arr);

    return 0;
}
// gets the length of the array
int get_len_of_arr (int len_of_arr) {
    printf("Enter the length of the array:\n");
    int len;
    scanf("%d", &len);
    len_of_arr = len;
    return len_of_arr;
}
// enters the values from the user into the array
void enter_values_into_arr (int len_of_arr, char *arr) {
    printf("Enter the array:\n");
    for (int i=0 ; i<len_of_arr ; i++) {
        scanf(" %c", (arr+i));
    }
}
// decides if it is a palindrome
bool is_it_palindrome (int len_of_arr, char *arr, int index, bool res) {
    if (index < 0) {
        return true;
    }
    res = is_it_palindrome(len_of_arr, arr, index-1, res);
    if (*(arr+index) != *(arr+len_of_arr-1-index)) {
        res *= false;
    }
    return res;
}

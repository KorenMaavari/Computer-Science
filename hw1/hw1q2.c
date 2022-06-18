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
int main()
{
    char letter;
    char sequence;
    int counter;

    sequence = 0;
    counter = 0;

    printf("Enter letter to count:\n");
    scanf(" %c", &letter);
    if ((65 <= letter && letter <= 90) ||
        (97 <= letter && letter <= 122)) //alphabet letters
    {
        if (65 <= letter && letter <= 90)
        {
            letter += 'a'-'A'; //capital letter to small letter
        }
        printf("Enter the char sequence:\n");
        while (sequence != '#')
        {
            scanf(" %c", &sequence);
            if (65 <= sequence && sequence <= 90)
            {
                sequence += 'a'-'A'; //all capital letters to small letters
            }
            if (sequence == letter)
            {
                counter++;
            }
        }
        printf("The letter appeared %d times\n", counter);
    }

    return 0;

    }

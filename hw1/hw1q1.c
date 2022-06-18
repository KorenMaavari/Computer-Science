/*-------------------------------------------------------------------------
  Include files:
--------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>



/*=========================================================================
  Constants and definitions:
==========================================================================*/

/* put your #defines and typedefs here*/

#define EPS 0.000001

/*-------------------------------------------------------------------------
  The main program. (describe what your program does here)
 -------------------------------------------------------------------------*/
int main()
{
    double a, b, c;
    double discri;
    do { //takes three parameters
        printf("Enter the coefficients of a polynomial:\n");
        scanf(" %lf %lf %lf", &a, &b, &c);
    } while (-EPS < a && a < EPS);
    discri = (b * b) - (4 * a * c);
    if (discri < -EPS) { //only real numbers
        printf("There are no roots\n");
    } else if (-EPS < discri && discri < EPS) { //almost zero
        double the_root = -b / (2 * a);
        printf("The root is %.3f\n", -EPS < the_root && the_root < EPS ?
               0 : the_root);
    } else { //the two answers
        double first_root = (-b - sqrt(discri)) / (2 * a);
        double second_root = (-b + sqrt(discri)) / (2 * a);
        printf("The roots are %.3f, %.3f\n",
               -EPS < first_root && first_root < EPS ? 0 : first_root,
               -EPS < second_root && second_root < EPS ? 0 : second_root);
    }
    return 0;
}

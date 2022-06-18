/*-------------------------------------------------------------------------
  Include files:
--------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdbool.h>
#include <math.h>



/*=========================================================================
  Constants and definitions:
==========================================================================*/

/* put your #defines and typedefs here*/

#define MAXIMAL_NUM_OF_GRADES 50
#define MAXIMAL_STD_DEV 10.0

/*-------------------------------------------------------------------------
  The main program. (describe what your program does here)
 -------------------------------------------------------------------------*/
double minMaxGrades (double grades[], int num_of_grades, bool t_is_min);
double meanGrades (double grades[], int num_of_grades);
double stdGrades (double grades[], int num_of_grades,
                  double vrg_of_grades);
int printGrades (double grades[], int num_of_grades);
int updateGrades (double grades[], int num_of_grades,
                  double expected_average, double maximal_std_dev);
void printGradesOpening ();
void printOldGrades (double grades[], int num_of_grades);
void printOldGradesStatistics (double min, double max,
                               double mean, double std);
void printNewGrades (double grades[], int num_of_grades);
void printNewGradesStatistics (double min, double max,
                               double mean, double std);
void prints(double grades[], int num_of_grades, double expected_average);

int main()
{
    printGradesOpening();
    double grades[MAXIMAL_NUM_OF_GRADES+1+1+1]; // 1=average, 1=EOF, 1=-1
    for (int i=0 ; i<(MAXIMAL_NUM_OF_GRADES+1+1+1) ; i++) {
        grades[i] = -1.0; // -1.0 indicates "unwanted values"
    }
    int i = 0;
    while (scanf("%lf", &grades[i])!= EOF) { // gets a value and check it
        i++; // continues to the next index
    }
    int num_of_grades;
    double expected_average;
    for (int i=0 ; grades[i]!=-1.0 ; i++) {
        num_of_grades = i; // counts the total number of grades
        expected_average = grades[i]; // at last, it'll be the last input
    }
    prints(grades, num_of_grades, expected_average);

    return 0;
}

double minMaxGrades (double grades[], int num_of_grades, bool t_is_min) {
    int i;
    double max = 0.0;// (initial) it must be greater than or equal to 0.0
    double min = 100.0;//(initial) it must be less than or equal to 100.0
    for (i=0 ; i<num_of_grades ; i++) {
        if (grades[i] > max) {
            max = grades[i];
        }
        if (grades[i] < min) {
            min = grades[i];
        }
    }
    double res; // res will be min or max depending on the input
    if (t_is_min == true) {
        res = min;
    } else {
        res = max;
    }
    return res;
}

double meanGrades (double grades[], int num_of_grades) {
    int i;
    double sum = 0.0; // initial value
    for (i=0 ; i<num_of_grades ; i++) {
        sum += grades[i];
    }
    double average = sum / num_of_grades;
    return average;
}

double stdGrades (double grades[], int num_of_grades,
                  double vrg_of_grades) {
    // calculates according to the formula
    int i;
    double sigma = 0.0; // initial value
    for (i=0 ; i<num_of_grades ; i++) {
        double difference = grades[i]-vrg_of_grades;
        double square = difference * difference;
        sigma += square;
    }
    double inverse = (1.0/num_of_grades);
    double multiplicate = inverse * sigma;
    double root = sqrt(multiplicate);
    return root;
}

int printGrades (double grades[], int num_of_grades) {
    int i;
    for (i=0 ; i<num_of_grades ; i++) {
        printf("%.1f ", grades[i]);
    }
    printf("\n"); // at last, it descends a row
    return 0;
}

int updateGrades (double grades[], int num_of_grades,
                  double expected_average, double maximal_std_dev) {
    // updates the variables according to the conditions
    double cur_std_dev = stdGrades(grades, num_of_grades,
                                   meanGrades(grades, num_of_grades));
    if (cur_std_dev > maximal_std_dev) {
        for (int i=0 ; i<num_of_grades ; i++) {
            grades[i] *= (maximal_std_dev / cur_std_dev);
        }
    }
    double cur_average = meanGrades(grades, num_of_grades);
    double vrg_diff = cur_average - expected_average;
    if (vrg_diff < 0) { // "absolute value"
        vrg_diff = -vrg_diff;
    }
    if (vrg_diff > 1.0) {
        for (int i=0 ; i<num_of_grades ; i++) {
            grades[i] = grades[i] - cur_average + expected_average;
        }
    }
    return 0;
}

void printGradesOpening () {
    printf("Please enter the grades of the examinees");
    printf(" followed by the expected mean\n");
}

void printOldGrades (double grades[], int num_of_grades) {
    printf("Old grades: ");
    printGrades(grades, num_of_grades);
}

void printOldGradesStatistics (double min, double max,
                               double mean, double std) {
    printf("Old minimum grade: %.1f\n", min);
    printf("Old maximum grade: %.1f\n", max);
    printf("Old mean: %.1f\n", mean);
    printf("Old standard deviation: %.1f\n",std);
}

void printNewGrades (double grades[], int num_of_grades) {
    printf("New grades: ");
    printGrades(grades, num_of_grades);
}

void printNewGradesStatistics (double min, double max,
                               double mean, double std) {
    printf("New minimum grade: %.1f\n", min);
    printf("New maximum grade: %.1f\n", max);
    printf("New mean: %.1f\n", mean);
    printf("New standard deviation: %.1f\n", std);
}

void prints (double grades[], int num_of_grades, double expected_average){
    //unites all of the print functions into one
    printOldGrades(grades, num_of_grades);
    printOldGradesStatistics(minMaxGrades(grades, num_of_grades, 1),
                             minMaxGrades(grades, num_of_grades, 0),
                             meanGrades(grades, num_of_grades), stdGrades
                             (grades, num_of_grades, meanGrades
                              (grades, num_of_grades)));
    updateGrades(grades, num_of_grades, expected_average,
                 MAXIMAL_STD_DEV);
    printNewGrades(grades, num_of_grades);
    printNewGradesStatistics(minMaxGrades(grades, num_of_grades, 1),
                             minMaxGrades(grades, num_of_grades, 0),
                             meanGrades(grades, num_of_grades), stdGrades
                             (grades, num_of_grades, meanGrades
                              (grades, num_of_grades)));
}

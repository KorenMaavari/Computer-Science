/*-------------------------------------------------------------------------
  Include files:
--------------------------------------------------------------------------*/

#include <stdio.h>
#include <math.h>


/*-------------------------------------------------------------------------
  Constants and definitions:
--------------------------------------------------------------------------*/

#define N 50
#define M 50
#define RECT 4


/* put your #defines and typedefs here*/
void compute_integral_image(int image[][M], int n, int m, int integral_image[][M]);
int sum_rect(int integral_image[][M], int rect[RECT]);
void sliding_average(int integral_image[][M], int n, int m, int h, int w, int average[][M]);
void print_array(int a[N][M], int n, int m);


/*-------------------------------------------------------------------------
  Your implementation of the functions (describe what each function does)
 -------------------------------------------------------------------------*/

//gets n*m grayscale picture and calculates the summed space table of it into "integral_image"
void compute_integral_image(int image[][M], int n, int m, int integral_image[][M]) {
    for (int i=0 ; i<n ; i++) {
        for (int j=0 ; j<m ; j++) {
            int on_the_top = (i != 0) ? integral_image[i-1][j] : 0;
            int on_the_left = (j != 0) ? integral_image[i][j-1] : 0;
            int on_the_top_left = ((i != 0) && (j != 0)) ? integral_image[i-1][j-1] : 0;
            integral_image[i][j] = on_the_top + on_the_left - on_the_top_left + image[i][j];
        }
    }
}

//calculates the sum_rect according to the given formula
int sum_rect(int integral_image[][M], int rect[RECT]) {
    int on_the_top = (rect[0] != 0) ? integral_image[rect[0]-1][rect[3]] : 0;
    int on_the_left = (rect[1] != 0) ? integral_image[rect[2]][rect[1]-1] : 0;
    int on_the_top_left = ((rect[0] != 0) && (rect[1] != 0)) ? integral_image[rect[0]-1][rect[1]-1] : 0;
    int res = integral_image[rect[2]][rect[3]] - on_the_top - on_the_left + on_the_top_left;
    return res;
}

/*the function gets the n*m summed space table (integral_image) and calculates into "average" the average by the h*w sliding window of the values in
the original picture
the (i,j) number in "average" (average[i][j]) will be the average value in the rectangle in the original picture that its center is in the pixel (i,j)
and its size is h*w*/
void sliding_average(int integral_image[][M], int n, int m, int h, int w, int average[][M]) {
    for (int i=0 ; i<n ; i++) {
        for (int j=0 ; j<m ; j++) {
            int rect[RECT];
            if ((i-(h/2)) >= 0) {
                rect[0] = i-(h/2);
            } else {
                rect[0] = 0;
            }
            if ((j-(w/2)) >= 0) {
                rect[1] = j-(w/2);
            } else {
                rect[1] = 0;
            }
            if ((i+(h/2)) <= (n-1)) {
                rect[2] = i+(h/2);
            } else {
                rect[2] = n-1;
            }
            if ((j+(w/2)) <= (m-1)) {
                rect[3] = j+(w/2);
            } else {
                rect[3] = m-1;
            }
            average[i][j] = round((double)(sum_rect(integral_image, rect))/(h*w));
        }
    }
}

void print_array(int a[N][M], int n, int m) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            printf("%d", a[i][j]);
            if (j != m-1) {
                printf(" ");
            }
        }
        printf("\n");
    }
}

/*-------------------------------------------------------------------------
  The main program
 -------------------------------------------------------------------------*/

int main() {
    int n = 0, m = 0;
    printf("Enter image dimensions:\n");
    scanf("%d%d", &n, &m);

    int image[N][M] = {{0}};
    printf("Enter image:\n");
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf("%d", &image[i][j]);
        }
    }

    int h = 0, w = 0;
    printf("Enter sliding window dimensions:\n");
    scanf("%d%d", &h, &w);

    int integral_image[N][M];
    compute_integral_image(image, n, m, integral_image);
    printf("Integral image is:\n");
    print_array(integral_image, n, m);

    int average[N][M];
    sliding_average(integral_image, n, m, h, w, average);
    printf("Smoothed image is:\n");
    print_array(average, n, m);

    return 0;
}

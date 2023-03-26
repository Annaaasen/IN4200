#include <stdlib.h> // standard library 
#include <stdio.h> // standard input/output "printf"
#include <math.h> 
#include <time.h> // clock_t clock()

int main(){
    // Creating timing variables 
    clock_t start, timer_rows, timer_cols;

    // Initializing a matrix 
    int m, n;
    m = n = 10000;

    double **A; // A is now a pointer to a pointer (?)
    A = (double **)malloc(m * sizeof(double *));
    
    for (int i = 0; i < m; i++) {
        A[i] = (double *)malloc(n * sizeof(double));
    }

    // Starting with the rows;
    start = clock(); 

    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++) {
            A[i][j] = i + j;
        }
    }

    timer_rows = clock() - start;


    // Starting with the columns  
    start = clock(); 

    for (int j = 0; j < n; j++){
        for (int i = 0; i < m; i++) {
            A[i][j] = i + j;
        }
    }

    timer_cols = clock() - start;

    // Printing results
    printf("rows: %lu ms, columns: %lu ms", 1000*timer_rows/CLOCKS_PER_SEC, 1000*timer_cols/CLOCKS_PER_SEC);

    // Freeing memory for the second version
    for (int j = 0 ; j < n; j++){
        free(A[j]);
    }
    free(A);

    return 0;
}
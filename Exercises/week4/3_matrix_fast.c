#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "week4.h"

// Want to time the mat_mult vs mat_mult_fast

int main(int narg, char **args){
    
    // 2D arrays with underlying 1D storage 
    int m = 1000;
    int n = 1000; 
    int p = 1000;

    double *A = malloc(m * n * sizeof *A);
    double *B = malloc(n * p * sizeof *B);
    double *C = calloc(m * p,  sizeof *C);  

    // inserting random numbers
    int min = 0; 
    int max = 10;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            *(A + i*n + j) = restricted_rand(min, max);
            // Could also write: A[i*n + j];
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<p; j++){
            *(B + i*p + j) = restricted_rand(min, max);
        }
    }

    // The matrix-matrix multiplication
    double start1 = clock();
    mat_mult(A, B, C, m, n, p);
    double end1 = clock();
    double time_slow = 1000*(end1 - start1)/CLOCKS_PER_SEC;

    // Now fast
    double *D = calloc(m * p,  sizeof *D);

    double start2 = clock();
    mat_mult_fast(A, B, D, m, n, p);
    double end2 = clock();
    double time_fast = 1000*(end2 - start2)/CLOCKS_PER_SEC;

    printf("\nWithout unrolling:%.3f ms\n", time_slow);
    printf("\nWith unrolling:%.3f ms\n", time_fast);
    
    free(A);
    free(B);
    free(C);
    free(D);

    return 0;

}
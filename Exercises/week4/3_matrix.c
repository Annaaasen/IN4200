#include <stdio.h>
#include <stdlib.h>

#include "week4.h"

int main(int narg, char **args){
    
    // 2D arrays with underlying 1D storage 
    int m = 20;
    int n = 30; 
    int p = 30;

    double *A = malloc(m * n * sizeof *A);
    double *B = malloc(n * p * sizeof *B);
    double *C = calloc(m * p,  sizeof *C);
    double *D = calloc(m * p,  sizeof *D);


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

    printf("\nA\n");
    print_mat(A, m, n);
    printf("\nB\n");
    print_mat(B, n, p);

    // The matrix-matrix multiplication
    mat_mult(A, B, C, m, n, p);

    printf("\nC\n");
    print_mat(C, m, p);

    mat_mult_fast(A,B,D,m,n,p);

    printf("\nD\n");
    print_mat(D, m, p);

    free(A);
    free(B);
    free(C);
    free(D);

    return 0;

}
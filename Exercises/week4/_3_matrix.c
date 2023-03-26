#include <stdio.h>
#include <stdlib.h>

#include "week4.h"

int main(int narg, char **args){
    // Right now it only works with quadratic matrices

    if(narg < 2){
        printf("Insert #rows/#cols");
        return 1;
    }
    
    // 2D arrays with underlying 1D storage 
    int m = atoi(args[1]);

    double *A = malloc(m * m * sizeof *A);
    double *B = malloc(m * m * sizeof *B);
    double *C = malloc(m * m * sizeof *B);

    // inserting random numbers
    int min = 0; 
    int max = 10;
    for(int i=0; i<m; i++){
        for(int j=0; j<m; j++){
            *(A + i*m + j) = restricted_rand(min, max);
            *(B + i*m + j) = restricted_rand(min, max);
            *(C + i*m + j) = 0;
        }
    }

    // The matrix-matrix multiplication
    mat_mult(A, B, C, m);

    if(m==2){
        printf("\nA");
        printf("\n%.5f %.5f\n", *(A), *(A+1));
        printf("%.5f %.5f\n", *(A+2), *(A+3));

        printf("\nB");
        printf("\n%.5f %.5f\n", *(B), *(B+1));
        printf("%.5f %.5f\n", *(B+2), *(B+3));

        printf("\nC");
        printf("\n%.5f %.5f\n", *(C), *(C+1));
        printf("%.5f %.5f\n", *(C+2), *(C+3));
    }


    free(A);
    free(B);
    free(C);

    return 0;

}
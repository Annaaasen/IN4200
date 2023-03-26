#include <stdlib.h>
#include <stdio.h>

int main() {

    // initializing the array 
    int n_x, n_y, n_z; 
    // n_x = n_y = n_z = 3;
    n_x = 3;
    n_y = 4;
    n_z = 4;

    double ***A;
    A = (double ***)malloc(n_x * sizeof(double**));

    for (int i = 0; i < n_y; i++) {
        A[i] = (double **)malloc(n_y * sizeof(double*));
        for (int j = 0; j < n_z; j++) {
            A[i][j] = (double *)malloc(n_z * sizeof(double));
        }
    }


    // Fill in elements 
    for (int i = 0; i < n_x; i++){
        for (int j = 0; j < n_y; j++) {
            for (int k = 0; k < n_z; k++) {
                A[i][j][k] = n_x*i + n_y*j + n_z*k*k;
                // printf("(%d, %d, %d) : %.0f", i,j,k, A[i][j][k]);
                printf("%.0f ", A[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }


    for (int i = 0 ; i < n_x; i++){
        for (int j = 0; j < n_y; j++) {
            printf("%.0f\n", A[i][j][0]);
            free(A[i][j]);
        }
    }

    free(A);

    return 0; 
}
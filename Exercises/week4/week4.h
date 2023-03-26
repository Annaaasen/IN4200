// This is my first real attempt at creating a header file :)

#include <stdio.h>
#include <stdlib.h>

double restricted_rand(double min, double max){
    
    double range = (max - min);
    double div = RAND_MAX/range; 
    return min + (rand()/div);

}

//matrix multiplication
void mat_mult(double *A, double *B, double *C, int m, int n, int p){
    for(int i=0; i<m; i++){
        for(int j=0; j<p; j++){
            for(int k=0; k<n; k++){ //This is a summation variable which loops over the col/row elements
                C[i*p + j] += A[i*n + k] * B[k*p + j]; 
                // *(C + i*p + j) += *(A + i*n +k) * *(B + k*p + j);
                // should be like C[i][j] += A[i][k]*B[k][j];
            }
        }
    }

}

//Matrix multiplication, but now with loop-unrolling 
void mat_mult_fast(double *A, double *B, double *C, int m, int n, int p){
    
    int stride = 4; 
    double rest = p%stride;

    for(int i=0; i<m; i++){
        for(int j=0; j<p-rest; j+=stride){
            for(int k=0; k<n; k++){ 
                C[i*p + j] += A[i*n + k] * B[k*p + j];
                C[i*p + j+1] += A[i*n + k] * B[k*p + j+1];
                C[i*p + j+2] += A[i*n + k] * B[k*p + j+2];
                C[i*p + j+3] += A[i*n + k] * B[k*p + j+3];
            }
        }

        //rest loop 
        for (int j=p-rest; j<p; j++){
            for(int k=0; k<n; k++){
                C[i*p + j] += A[i*n + k] * B[k*p + j];
            }
        }
    }
}

void print_mat(double *A, int m, int n){
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            printf("%.3f  ", *(A + i*n + j));
        }
        printf("\n");
    }

}
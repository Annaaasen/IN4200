#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int narg, char **args){

    int N = atoi(args[1]);

    double *y = malloc(N * sizeof(double));
    double *B = malloc(N * sizeof(double));

    double **A = malloc(N * sizeof(double *));
    for (int i=0; i<N; i++){
        A[i] = (double*)malloc(N * sizeof(double));
    }

    for (int j=0; j<N; j++){
        for (int i=0; i<N; i++){
            A[j][i] = j + i;
        }
        B[j] = j; //Only works bc j and i goes to N (square matrix)
    }

    double start1 = clock();
    for (int j=0; j<N; j++){
        for (int i=0; i<N; i++){
            y[j] += A[j][i] * B[i]; 
        }
        // printf("%.3f\n", y[j]);
    }
    double end1 = clock();
    double time1 = (end1 - start1)/CLOCKS_PER_SEC;


    //Unroll and jam:
    int stride = 4;
    int rest = N%stride;

    double *y1 = malloc(N * sizeof(double)); 

    double start2 = clock();
    for (int j=0; j<N-rest; j+=stride){
        for (int i=0; i<N; i++){
            y1[j] += A[j][i] * B[i]; 
            y1[j+1] += A[j+1][i] * B[i];
            y1[j+2] += A[j+2][i] * B[i];
            y1[j+3] += A[j+3][i] * B[i];
        }
    }
    //rest: 
    for (int j=N-rest; j<N; j++){
        for (int i=0; i<N; i++){
            y1[j] += A[j][i] * B[i]; 
        }
    }
    double end2 = clock();
    double time2 = (end2 - start2)/CLOCKS_PER_SEC;

    printf("T1:%.fms \nT2:%.fms\n", time1*1000, time2*1000);




    return 0;
}
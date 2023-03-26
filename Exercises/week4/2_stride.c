#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int narg, char **args){
    
    if(narg < 3){
        printf("Need to submit length of arrays and stride");
        return 1;
    }

    int N = atoi(args[1]);
    int stride = atoi(args[2]);
    int s = 2;

    double *A = malloc(N * sizeof *A);
    double *B = malloc(N * sizeof *A);

    for(int i=0; i<N; i++){
        A[i] = rand();
        B[i] = rand();
    }

    double start = clock();
    for(int i=0; i<N; i+=stride){
        A[i] = s*B[i];
    }
    double end = clock();

    double total_time = (end - start)/CLOCKS_PER_SEC;
    double total_bytes = 2*N/stride * sizeof *A;
    double total_flops = N/stride;
    double bandw = total_bytes / total_time;

    printf("\nTotal time: \n%fs\n", total_time);
    printf("\nTotal number of bytes loaded: \n%f\n", total_bytes);
    printf("\nBandwidth (bytes/sec): \n%f\n", bandw);
    printf("\nFLOPS/sec: \n%f\n", N/stride/total_time);

    free(A);
    free(B); 

    return 0;
}
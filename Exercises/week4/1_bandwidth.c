#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(int narg, char **args) {
    
    if (narg < 2){
        printf("Need to submit lenght of arrays");
        return 1; 
    }

    int N = atoi(args[1]);
    int s = 2; 

    double *A = malloc(N * sizeof(double)); 
    double *B = malloc(N * sizeof(double));

    // Asigning random numbers to the arrays
    for (int i=0; i<N; i++){
        A[i] = rand();
        B[i] = rand();
    }

    double start = clock();
    for (int i=0; i<N; i++){
        A[i] = s*B[i];
    }
    double end = clock();
    
    double total_time = (end - start)/CLOCKS_PER_SEC;

    double total_bytes = 2 * N * sizeof *A;
    // This feels like we only account for only retrieving the memory. 
    // NB! We do not need to retrieve A[i], only save 

    double bandw = total_bytes / total_time;

    printf("\nTotal time: \n%fs\n", total_time);
    printf("\nTotal number of bytes loaded: \n%f\n", total_bytes);
    printf("\nBandwidth (bytes/sec): \n%f\n", bandw);
    printf("\nFLOPS/sec: \n%f\n", N/total_time);

    free(A);
    free(B);

    return 0; 

}
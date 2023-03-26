#include <stdio.h>
#include <stdlib.h>
// #include </opt/homebrew/Cellar/libomp/15.0.7/include/omp.h>
#include <omp.h>

double randfrom(double min, double max)
{
    double range = (max - min);
    double div = RAND_MAX / range;
    return min + (rand() / div);
}

double* oneD_arr(int N){
    // returning an array with random elements (doubles)
    double *a = malloc(N * sizeof(double));

#pragma omp parallel for
    for (int i=0; i<N; i++){
        a[i] = randfrom(0, 10);
    }

    return a;
}

void print_threads(){
    printf("I'm the master thread, I'm alone\n");

#pragma omp parallel
{
    int num_threads, thread_id; 
    thread_id =  omp_get_thread_num();
    num_threads = omp_get_num_threads();

    printf("Hello world from id %d / %d\n" , thread_id, num_threads);
}
}

int main (int narg, char **args){

    int N = 10000000;
    double *a = malloc(N * sizeof(double));
    double *b = oneD_arr(N);
    double *c = oneD_arr(N);


#pragma omp parallel for 
    for (int i=0; i<N; i++){
        a[i] = b[i] + c[i];
    }


    free(a); free(b); free(c);

    return 0;
}
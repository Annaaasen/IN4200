#include <stdlib.h>
#include <stdio.h>
#include <omp.h> 

int main(){
    
    printf("Hello world, I'm the Master thread, I'm alone\n");

#pragma omp parallel
{
    int num_threads, thread_id;
    num_threads = omp_get_num_threads();
    thread_id = omp_get_thread_num();

    printf("Hello world, I'm thread %d out of %d\n", thread_id, num_threads);
}

    return 0;
}


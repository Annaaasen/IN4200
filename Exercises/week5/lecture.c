#include <stdio.h>
#include <stdlib.h>
// #include </opt/homebrew/Cellar/libomp/15.0.7/include/omp.h>
#include <omp.h>

int main (int narg, char **args){

#pragma omp parallel
{
    printf("Hello world\n");
}

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef int my_type; 

int main(){

    clock_t start, t_loop, t_memcpy;

    int n = 100000;
    my_type * a = malloc(n * sizeof(my_type));
    my_type * b = malloc(n * sizeof(my_type));

    for (int i=0; i<n; i++) a[i] = i;

    // For memcpy: 
    start = clock();
    memcpy(b, a, n*sizeof(my_type));
    t_memcpy = clock() - start;

    // For loop: 
    start = clock();
    for(int i=0; i<n; i++) {
        b[i] = a[i];
    }
    t_loop = clock()- start;

    printf("Time elapsed using loop: %lu microsec.\n", 1000000*t_loop/CLOCKS_PER_SEC);
    printf("Time elapsed using memcpy: %lu microsec.\n", 1000000*t_memcpy/CLOCKS_PER_SEC);

    return 0;
}

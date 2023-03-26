#include <stdlib.h> // standard library 
#include <stdio.h> // standard input/output "printf"
#include <math.h> // "fabs"

int main(int narg, char ** args){
    // first command line argument (after filename) should be length of 1d array n

    if (narg < 2) {
        printf("Commandline arguments are needed. Insert length of array after filename");
        return EXIT_FAILURE;
    }

    int n = atoi(args[1]);

    if (n <= 0) {
        printf("Length of array must be a positive integer larger than zero");
        return EXIT_FAILURE;
    }

    // Creating the dynamic random array 
    int *rand_arr;
    rand_arr = (int*)malloc(n * sizeof(int)); // sizeof(int) refers to the size an integer takes

    for (int i = 0; i<n; i++) {
        rand_arr[i] = rand();
        printf("%d \n", rand_arr[i]);
    }

    // Finding the maximum and minimum values: 
    int min, max; 
    min = max = rand_arr[0];
    for (int i = 1; i<n; i++) {
        if (rand_arr[i] < min){
            min = rand_arr[i];
        }

        if (rand_arr[i] > max) {
            max = rand_arr[i];
        }
    }
    printf("min: %d, max: %d \n", min, max);

    
    // Final step: deallocate the array! Don't forget this part.
    free(rand_arr);

    return 0;
}
#include <stdlib.h>
#include <stdio.h>

int *getMax(int *m, int *n) {
/* if the value pointed by pointer m is greater than n
* then, return the address stored in the pointer variable m.
* the * infront of 'getMax' means it returns a pointer; either m or n */ 
    if (*m > *n) {
        return m;
    }
    else {
        return n;
    }
}

int main(int argc, char** argv){

    // print sizeof 
    printf("Storage size of int: %lu\n", sizeof(int));

    // creating variable
    int x = 4;

    // creating a pointer
    int * pX = &x;
    int y = *pX;

    printf("x = %d\n", x); 

    // printing multiple variables
    x = 5; 
    printf("x = %d and y = %d \n", x, y);
    printf("Value of x is %d \n", *pX);

    // creating and printing array
    int* arr = malloc(sizeof(int)*11);

    for (int i = 0; i < 11; ++i){
        arr[i] = i;
    }

    for (int i = 0; i < 11; ++i){
        printf("%d\n",arr[i]);
    }

    // Creating a pointer to the 4th element in arr: 
    int* p = arr + 3;
    printf("value at p: %d\nvalue at arr[3]: %d\n", *p, arr[3]);
    // The above is weird... At what point did arr stop being a pointer? I think, when you insert an index

    printf("Address remembered by p: %p\nAddress remembered by arr: %p", p, arr);

    
    free(arr);

    return 0;
}




// Notes:
// C is case-sensitive 
// memory can be allocated either through heap (can vary and needs to be cleared) or stack(static and naive)
// &x refers to the address of x 
// type *pt creates a pointer, while just *pt retrieves the value at which the pointer points;) 








#include <stdlib.h> // standard library 
#include <stdio.h> // standard input/output "printf"
#include <math.h> // "fabs"

int main(){

    int num_its, i;

    num_its = 40;
    i = 0;

    double true_val, threshold, current, add; 

    true_val = 4./5.;
    threshold = 1e-12;
    current = add = 1;

    while (i++ < num_its && fabs(true_val - current) > threshold){
        add *= - 1./4.;
        current += add;

        printf("%d %.13f \n", i, fabs(true_val - current));
    }

    return 0;
}
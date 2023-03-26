// Want to find out how costly a division operation is 

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
// #include <intrin.h> 


double numerical_integration (double x_min, double x_max, int slices){
    double delta_x = (x_max-x_min)/slices;
    double x, sum = 0.0;
    for (int i=0; i<slices; i++) {
        x = x_min + (i+0.5)*delta_x;
        sum = sum + 4.0/(1.0+x*x);
    }
    return sum*delta_x;
}

int main(void){
    int x_min, x_max, slices, i; 
    double threshold, area; 

    threshold = 1e-6;
    area = 0;

    x_min = 0; x_max = 1; 
    slices = 1000; 
    i = 0;

    while(i++ < slices && fabs(area - M_PI) > threshold){
        area = numerical_integration(x_min, x_max, i);
        printf("%f   %d\n", area, i);
    }

    // // counting cycles.
    // unsigned long long start = __rdtsc();
    // double value = numerical_integration(0, 1, 10000);
    // unsigned long long end = __rdtsc();

    // double avg = (double)(end - start)/10000;

    // printf("Average number of cycles: %lf\n", avg);

    return 0;
}

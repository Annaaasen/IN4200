#include <stdlib.h>
#include <stdio.h>

#include "Ex2a_common.h"


void readfile(char *filename, temperature_data *data) {
    // creating a pointer to the opened datafile
    FILE *datafile;
    datafile = fopen(filename, "r");

    fscanf(datafile, "%d\n", &data->data_points); 
    // printf("%d\n", data->data_points);

    data->times = (char *)malloc(5 * sizeof(char) * data->data_points);
    data->temps = (double *)malloc(sizeof(double) * data->data_points); 

    for (int i = 0 ; i < data->data_points; i++){
        fscanf(datafile, "%5s %lf\n", &data->times[5*i], &data->temps[i]);
    }

    // printf("%c \n%c\n", data->times[5], data->times[2]);
    // printf("%f\n",  data->temps[6]);
    // printf("%.5s\n", &data->times[25]);

}

void max_idx(double *arr, int len, int *p_idx){
    // double max_ = arr[*p_idx]; 
    for(int i = 0; i <len; i++){
        if(arr[i]>arr[*p_idx]){
            // arr[*p_idx] = arr[i];
            *p_idx = i;
        }
    }   
}

int max_idx2(double *arr, int len){
    // Takes in an array, the length of the array, and returns the index which holds the maximum value
    int _idx = 0;
    for(int i = 0; i <len; i++){
        if(arr[i]>arr[_idx]){
            _idx = i;
        }
    }  

    return _idx; 
}



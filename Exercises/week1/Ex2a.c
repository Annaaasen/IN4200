#include <stdlib.h>
#include <stdio.h>

#include "Ex2a_common.h"

int main(int narg, char **args) {

    if (narg < 2){
        printf("Filename must be submitted.");
        return EXIT_FAILURE; 
    }

    // create object to contain data (imported structure from above)
    temperature_data *data;  
    data = (temperature_data *)malloc(sizeof(temperature_data));

    // printf("%s\n", args[1]);
    // data->data_points = 100;
    // printf("%d\n", data->data_points);

    readfile(args[1], data);

    int max_temp_idx = 4; 
    printf("%d\n", max_temp_idx);
    int *p_max_temp_idx = &max_temp_idx;
    max_idx(data->temps, data->data_points, p_max_temp_idx);
    printf("%d\n", max_temp_idx);

    printf("%d\n", max_idx2(data->temps, data->data_points));
    printf("Time: %.5s\n", &data->times[5 * max_idx2(data->temps, data->data_points)]);
    printf("Temp: %.2lf\n", data->temps[max_idx2(data->temps, data->data_points)]);

    free(data->temps); 
    free(data->times);

    return 0; 
}


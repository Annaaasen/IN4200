// define the structure "temperature data"

typedef struct {

    int data_points;    //bæsj
    char *times;
    double *temps;
    int max_temp_idx;

}temperature_data;

void readfile(char *filename, temperature_data *data);

void max_idx(double *arr, int len, int *p_idx);

int max_idx2(double *arr, int len);
#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include <stdbool.h>

#define clock2ms(t) (double)(t*1000.0)/CLOCKS_PER_SEC 

// double sign = xarr[1] > xarr[0] ? 1.0 : -1.0;  //A way of making a defalt argument?

// Create FILE object for writing open and close and then create one for reading 
// To open / close file fopen(filemane, mode) / fclose(file)
// ASCII: to write fprintf
// ASCII: to read fscanf, need address to malloc 
// For ASCII you need to do it in a loop 
// Binary: to write fwrite and fread, not in a loop 

void using_ASCII(int n){
    //Creating variables to take the time
    double start, t_writing, t_reading;  

    // Creating arrays to read/be read into the files
    // int n = 100;
    double *writing, *reading;
    writing = malloc(n*sizeof(double));
    reading = malloc(n*sizeof(double));

    for(int i=0; i<n; i++){
        writing[i] = i;
    }
    
    //Opening and writing a file 
    FILE *openfile; 
    start = clock();
    openfile = fopen("dummy.txt", "w");
    for(int i=0; i<n; i++) {
        fprintf(openfile, "%.2f\n", writing[i]);
    }
    fclose(openfile);
    t_writing = clock2ms((clock() - start)); 

    //Opening and reading a file 
    FILE *readfile;
    start = clock();
    readfile = fopen("dummy.txt", "r");
    for (int i=0; i<n; i++){
        fscanf(readfile, "%lf\n", &reading[i]); //BC when working with a function, to change a variable you need to send in its pointer
    }
    fclose(readfile);
    t_reading = clock2ms((clock() - start));

    //Printing results: 
    printf("ASCII: Writing an array of %d elements takes %f ms\n", n, t_writing);
    printf("ASCII: Reading an array of %d elements takes %f ms\n", n, t_reading);
    printf("\nSanity check:\n%f\n%f\n\n", writing[10], reading[10] );

}

void using_BIN(int n){
    //Creating variables to take the time
    double start, t_writing, t_reading;  

    // Creating arrays to read/be read into the files
    double *writing, *reading;
    writing = malloc(n*sizeof(double));
    reading = malloc(n*sizeof(double));

    for(int i=0; i<n; i++){
        writing[i] = i;
    }
    
    //Opening and writing a file 
    FILE *openfile; 
    start = clock();
    openfile = fopen("dummy.txt", "wb");
    fwrite(writing, sizeof(double), n, openfile);
    fclose(openfile);
    t_writing = clock2ms((clock() - start)); 

    //Opening and reading a file 
    FILE *readfile;
    start = clock();
    readfile = fopen("dummy.txt", "rb");
    fread(reading, sizeof(double), n, readfile);
    fclose(readfile);
    t_reading = clock2ms((clock() - start));

    //Printing results: 
    printf("Binary: Writing an array of %d elements takes %f ms\n", n, t_writing);
    printf("Binary: Reading an array of %d elements takes %f ms\n", n, t_reading);
    printf("\nSanity check:\n%f\n%f\n", writing[10], reading[10] );

}


int main(int narg, char **argv){ 
    if(narg<2){
        printf("Need to insert number of elements in array");
        exit(0);
    }

    using_ASCII(atoi(argv[1]));
    using_BIN(atoi(argv[1]));
    return 0;
}




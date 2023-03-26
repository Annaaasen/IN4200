#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void foo(int N, double **mat, double **s, int *v){
    double val;

    for (int j=0; j<N; j++){
        for (int i=0; i<N; i++){
            val = v[j]%256;
            mat[i][j] = s[i][j]*(sin(val)*sin(val) - cos(val)*cos(val));
        }
    }

}

void foo2(int N, double **mat, double **s, int *v){
    double val;

    for (int j=0; j<N; j++){
        val = cos(2*v[j]%256);
        for (int i=0; i<N; i++){
            mat[i][j] = s[i][j]*val;
        }
    }
}



int main(int narg, char **args){

    if(narg < 2){
        printf("You need to submit length of arrays, N\n");
        return 1;
    }
    
    int N = atoi(args[1]);

    int *v = malloc(N * sizeof(int));
    double **mat = malloc(N * sizeof(double*));
    double **s = malloc(N * sizeof(double*));

    for (int i=0; i<N; i++){
        mat[i] = (double*)malloc(N * sizeof(double));
        s[i] = (double*)malloc(N * sizeof(double));
    }

    for (int j=0; j<N; j++){
        for (int i=0; i<N; i++){
            s[j][i] = j + i;
        }
        v[j] = j; //Only works bc j and i goes to N (square matrix)
        // printf("%.f\n", v[j]);
    }

    double start1 = clock();
    foo(N, mat, s, v);
    double end1 = clock();
    double time1 = 1000*(end1 - start1)/CLOCKS_PER_SEC;

    double start2 = clock();
    foo2(N, mat, s, v);
    double end2 = clock();
    double time2 = 1000*(end2 - start2)/CLOCKS_PER_SEC;

    printf("T1:%.fms \nT2:%.fms\n", time1, time2);

    
    free(v);
    for (int i=0; i<N; i++){
        free(mat[i]);
        free(s[i]);
    }
    free(mat);
    free(s);

    return 0; 
}
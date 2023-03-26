#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define PI 3.14159265359

void solver(){

}

int main(){
    int nx = 80, ny=90, nz=100; 
    // nx = ny = nz = 100;

    //Allocate memory for two 3D-arrays:
    double ***v = (double ***)malloc(nx * sizeof(double**));
    double ***u = (double ***)malloc(nx * sizeof(double**));
    for (int i=0; i<nx; i++){
        v[i] = (double **)malloc(ny * sizeof(double*));
        u[i] = (double **)malloc(ny * sizeof(double*));
        for (int j=0; j<ny; j++){
            v[i][j] = (double *)malloc(nz * sizeof(double));
            u[i][j] = (double *)malloc(nz * sizeof(double));
        }
    }

    // Fill in values of v: 
    for (int i=0; i<nx; i++){
        for (int j=0; j<ny; j++){
            for (int k=0; k<nz; k++){
                v[i][j][k] = 2 + sin(i*j*k*M_PI/((nx-1)*(ny-1)*(nz-1)));
                // v[i][j][k] = 2 + sin(i*j*k*PI/((nx-1)*(ny-1)*(nz-1)));
            }
        }
    }

    // printf("%f\n", u[1][8][9]);
    // // // Fill in values of u: Might not be necessary? All elements are already 0. 
    // for (int i=0; i<nx; i++){
    //     for (int j=0; j<ny; j++){
    //         memset(u[i][j], 0, nz*sizeof(u[i]));
    //         break;
    //     }
    //     break;
    // }

    printf("%f\n%f", v[0][0][0], u[19][89][99]);

    //Deallocate: 
    for (int i = 0 ; i < nx; i++){
        for (int j = 0; j < ny; j++) {
            free(v[i][j]);
            free(u[i][j]);
        }
        free(v[i]);
        free(u[i]);
    }
    free(v);
    free(u);    
}
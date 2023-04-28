#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
#include <math.h>

#define Pi M_PI

double all_compute_numerical_error (int my_rank, int my_offset, int P, int nx, int my_ny,
                                    double dx, double dy, double t_value, double **my_u)
{

// Remember to use the correct y-value (i=0 til my_ny), but NB remember ghost points! Use my_offset 
 
    int has_neighbour_below = (my_rank>0) ? 1 : 0;

    double y, x, u_true, err; 
    int i, j;

    // int i_stop = (my_rank==0) ? my_ny : my_ny+1; 

    double pi_t = cos(Pi * t_value);
    double sum = 0;


    for (i=0; i<my_ny; i++){
        y = (i + my_offset)*dy; //This needs i to go from 0
        for (j=0; j<nx-1; j++){
            x = j*dx;
            u_true = cos(2*Pi*x) * cos(2*Pi*y) * pi_t; 
            sum += (u_true - my_u[i+has_neighbour_below][j])*(u_true - my_u[i+has_neighbour_below][j]); //However, this needs to avoid the ghost points at i==0
        }
        // if(my_rank==1){
        //     printf("u_true = %f  my_u = %f, i=%d, j=%d, myo=%d, y=%f\n", u_true, my_u[i+has_neighbour_below][j], i, j, my_offset, y);
        // }
    }


    err = sqrt(dx * dy * sum);

    return err;

}
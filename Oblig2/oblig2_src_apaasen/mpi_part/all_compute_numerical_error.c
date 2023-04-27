#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
#include <math.h>

#define Pi M_PI

double all_compute_numerical_error (int my_rank, int my_offset, int P, int nx, int my_ny,
                                    double dx, double dy, double t_value, double **my_u)
{

// Remember to use the correct y-value (i=0 til my_ny), but NB remember ghost points! Use my_offset 
 
    double y, x, u_true, err; 
    int i, j;

    int i_start = (my_rank==0) ? 0 : 1;
    int i_stop = (my_rank==0) ? my_ny : my_ny+1; 

    double pi_t = cos(Pi * t_value);
    double sum = 0;

    for (i=i_start; i<i_stop; i++){
        y = (i + my_offset)*dy;
        for (j=0; j<nx-1; j++){
            x = j*dx;
            u_true = cos(2*Pi*x) * cos(2*Pi*y) * pi_t; 
            sum += (u_true - my_u[i][j])*(u_true - my_u[i][j]);
        }
    }

    // if(my_rank==2){
    //     printf("u_true = %f  my_u = %f\n", u_true, my_u[-1][-1]);
    // }

    err = sqrt(dx * dy * sum);

    return err;

}
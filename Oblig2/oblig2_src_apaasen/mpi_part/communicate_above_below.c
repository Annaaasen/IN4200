#include <mpi.h>
#include <stdlib.h>
#include <stdio.h>

MPI_Status status;
// Motive of this funciton: 
// Let each process receive from its two neighbours (above and below) needed ont the ghost layer of points
// And send 
// NB! Process 0 and P-1 only have one neighbour

void communicate_above_below (int my_rank, int P, int nx, int my_ny, double **my_u)
{
    //The goal is that each process receives data which is placed in their respective ghost points 
    //And send data from their outer rows (ghost_points rows excluded) 

    int above = my_rank + 1;
    int below = my_rank - 1;

    int ghost_top = (my_rank==0) ? my_ny : my_ny+1;         //Will not be used for P-1
    int ghost_bottom = 0;                                   //Will not be used for 0        
    int non_ghost_top = (my_rank==0) ? my_ny-1 : my_ny;
    int non_ghost_bottom = 1;

    if(my_rank==0){
        // printf("%f\n", my_u[ghost_top][505]);
        MPI_Send(&(my_u[non_ghost_top][0]), nx, MPI_DOUBLE, above, 0, MPI_COMM_WORLD);          //to above
        MPI_Recv(&(my_u[ghost_top][0]), nx, MPI_DOUBLE, above, 0, MPI_COMM_WORLD, &status);   //from above
        // printf("%f\n", my_u[ghost_top][505]);
        // printf("0: %d\n", my_rank);
    }

    else if(my_rank==P-1){
        //Whether this sends or receives first depends on the number of processes 
        if (my_rank%2==1){
            MPI_Recv(&(my_u[ghost_bottom][0]), nx, MPI_DOUBLE, below, 0, MPI_COMM_WORLD, &status);      //from below
            MPI_Send(&(my_u[non_ghost_bottom][0]), nx, MPI_DOUBLE, below, 0, MPI_COMM_WORLD);         //to below
        }
        else{
            MPI_Send(&(my_u[non_ghost_bottom][0]), nx, MPI_DOUBLE, below, 0, MPI_COMM_WORLD);         //to below 
            MPI_Recv(&(my_u[ghost_bottom][0]), nx, MPI_DOUBLE, below, 0, MPI_COMM_WORLD, &status);      //from below
        }
        // printf("last: %d\n", my_rank);
    
    }

    else if(my_rank%2==1){ //Odd numbers (it gives either 0 or 1 depending on whether there is a rest)
        // printf("%f\n", my_u[non_ghost_bottom][505]);
        MPI_Recv(&(my_u[ghost_bottom][0]), nx, MPI_DOUBLE, below, 0, MPI_COMM_WORLD, &status); //from below 
        MPI_Recv(&(my_u[ghost_top][0]), nx, MPI_DOUBLE, above, 0, MPI_COMM_WORLD, &status); //from above 
        MPI_Send(&(my_u[non_ghost_bottom][0]), nx, MPI_DOUBLE, below, 0, MPI_COMM_WORLD);    //to below
        MPI_Send(&(my_u[non_ghost_top][0]), nx, MPI_DOUBLE, above, 0, MPI_COMM_WORLD);    //to above
        // printf("odd: %d\n", my_rank);

    }

    else if(my_rank%2==0){ //Even numbers
        MPI_Send(&(my_u[non_ghost_top][0]), nx, MPI_DOUBLE, above, 0, MPI_COMM_WORLD);    //to above
        MPI_Send(&(my_u[non_ghost_bottom][0]), nx, MPI_DOUBLE, below, 0, MPI_COMM_WORLD);    //to below
        MPI_Recv(&(my_u[ghost_top][0]), nx, MPI_DOUBLE, above, 0, MPI_COMM_WORLD, &status); //from above 
        MPI_Recv(&(my_u[ghost_bottom][0]), nx, MPI_DOUBLE, below, 0, MPI_COMM_WORLD, &status); //from below 
        // printf("even: %d\n", my_rank);
    }



}

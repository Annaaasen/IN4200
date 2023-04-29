#include <mpi.h>
#include <stdlib.h>
#include <stdio.h>

MPI_Status status;

void communicate_above_below (int my_rank, int P, int nx, int my_ny, double **my_u)
{
    //The goal is that each process receives data from their neighbours and place this data in their respective ghost points 
    //In addition each process will send data from their outer rows (ghost_points rows excluded) 
    //To avoid a dead lock, a shift of send/recv-order depending on even/odd numbers is employed. 

    int above = my_rank + 1;
    int below = my_rank - 1;

    //Indices: 
    int ghost_top = (my_rank==0) ? my_ny : my_ny+1;         //Will not be used for P-1
    int ghost_bottom = 0;                                   //Will not be used for 0        
    int non_ghost_top = (my_rank==0) ? my_ny-1 : my_ny;
    int non_ghost_bottom = 1;

    if(my_rank==0){
        MPI_Send(&(my_u[non_ghost_top][0]), nx, MPI_DOUBLE, above, 0, MPI_COMM_WORLD);          //to above
        MPI_Recv(&(my_u[ghost_top][0]), nx, MPI_DOUBLE, above, 0, MPI_COMM_WORLD, &status);   //from above
    }

    else if(my_rank==P-1){
        //Whether this sends or receives first depends on the total number of processes 
        if (my_rank%2==1){
            MPI_Recv(&(my_u[ghost_bottom][0]), nx, MPI_DOUBLE, below, 0, MPI_COMM_WORLD, &status);      //from below
            MPI_Send(&(my_u[non_ghost_bottom][0]), nx, MPI_DOUBLE, below, 0, MPI_COMM_WORLD);         //to below
        }
        else{
            MPI_Send(&(my_u[non_ghost_bottom][0]), nx, MPI_DOUBLE, below, 0, MPI_COMM_WORLD);         //to below 
            MPI_Recv(&(my_u[ghost_bottom][0]), nx, MPI_DOUBLE, below, 0, MPI_COMM_WORLD, &status);      //from below
        }
    }

    else if(my_rank%2==1){ //Odd number processes
        MPI_Recv(&(my_u[ghost_bottom][0]), nx, MPI_DOUBLE, below, 0, MPI_COMM_WORLD, &status); //from below 
        MPI_Recv(&(my_u[ghost_top][0]), nx, MPI_DOUBLE, above, 0, MPI_COMM_WORLD, &status); //from above 
        MPI_Send(&(my_u[non_ghost_bottom][0]), nx, MPI_DOUBLE, below, 0, MPI_COMM_WORLD);    //to below
        MPI_Send(&(my_u[non_ghost_top][0]), nx, MPI_DOUBLE, above, 0, MPI_COMM_WORLD);    //to above
    }

    else if(my_rank%2==0){ //Even number processes
        MPI_Send(&(my_u[non_ghost_top][0]), nx, MPI_DOUBLE, above, 0, MPI_COMM_WORLD);    //to above
        MPI_Send(&(my_u[non_ghost_bottom][0]), nx, MPI_DOUBLE, below, 0, MPI_COMM_WORLD);    //to below
        MPI_Recv(&(my_u[ghost_top][0]), nx, MPI_DOUBLE, above, 0, MPI_COMM_WORLD, &status); //from above 
        MPI_Recv(&(my_u[ghost_bottom][0]), nx, MPI_DOUBLE, below, 0, MPI_COMM_WORLD, &status); //from below 
    }

}

#include <stdio.h> 
#include <mpi.h> 

int main (int narg, char** args){
    int size, my_rank;
    MPI_Init (&narg, &args);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
    printf("Hello World, I have rank %d out of %d processes\n", my_rank, size);
    MPI_Finalize();
    return 0;
}

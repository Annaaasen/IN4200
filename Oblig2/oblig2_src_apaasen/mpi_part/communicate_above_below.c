// Motive of this funciton: 
// Let each process receive from its two neighbours (above and below) needed ont the ghost layer of points
// And send 
// NB! Process 0 and P-1 only have one neighbour

void communicate_above_below (int my_rank, int P, int nx, int my_ny, double **my_u)
{
    // has_neigh_below = (my_rank>0) ? 1 : 0;

    // QUESTION: What is best? explicit ring-shift, MPI_Sendrecv, linear shift or other? 
    // Linear shift 
    // Dele inn i 4; topp, bunn og partall/oddetall i mellom (bruk motsatt send/receive)

    //Should have blocking send/recv (could end up calculating with different time steps if everything is not sent)

    //MPI_Send(&(my_u[out_idx_above][0], nx, MPI_Double, above, 0, MPI_COMM_WORLD))



}

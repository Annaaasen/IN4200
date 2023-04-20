// Motive of this funciton: 
// Let each process receive from its two neighbours (above and below) needed ont the ghost layer of points
// And send 
// NB! Process 0 and P-1 only have one neighbour

void communicate_above_below (int my_rank, int P, int nx, int my_ny, double **my_u);

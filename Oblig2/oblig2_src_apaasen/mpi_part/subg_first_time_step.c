// Motive of this function:
// Let's each process compute the first time step

void subg_first_time_step (int my_rank, int P, int nx, int my_ny, double dx, double dy, double dt, 
                            double **my_u, double **my_u_prev);
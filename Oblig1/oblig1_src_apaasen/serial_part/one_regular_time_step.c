void one_regular_time_step (int nx, int ny, double dx, double dy, double dt,
                            double **u_new, double **u, double **u_prev)
{
  // Want to calculate the first time step for every point 
  
  int j_left, j_right, i_above, i_below;
  
  double fact_x = dt*dt / (8 * dx*dx);
  double fact_y = dt*dt / (8 * dy*dy);

  //Inner square:            
  for (int i=0; i<ny; i++){    
    if (i==0)     i_below = 1;
    else          i_below = i-1;

    if (i==ny-1)  i_above = ny-2;
    else          i_above = i+1;

    for (int j=0; j<nx; j++){

      if (j==0)   j_left = 1;
      else        j_left = j-1;
      
      if (j==nx-1)j_right = nx-2;
      else        j_right = j+1;

      u_new[i][j] = 2*u[i][j]  
                + fact_x * (u[i][j_left] - 2*u[i][j] + u[i][j_right]) 
                + fact_y * (u[i_below][j] - 2*u[i][j] + u[i_above][j])
                - u_prev[i][j]; 
    }
  }
}

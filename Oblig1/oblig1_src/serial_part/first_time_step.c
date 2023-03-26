void first_time_step (int nx, int ny, double dx, double dy, double dt,
                      double **u, double **u_prev)
{
  // Want to calculate the first time step for every point 
  double fact_x = dt*dt / (16 * dx*dx);
  double fact_y = dt*dt / (16 * dy*dy);

  //Inner square:            
  for (int i=1; i<ny-1; i++){    
    for (int j=1; j<nx-1; j++){
      u[i][j] = u_prev[i][j]  
                + fact_x * (u_prev[i][j-1] - 2*u_prev[i][j] + u_prev[i][j+1]) 
                + fact_y * (u_prev[i-1][j] - 2*u_prev[i][j] + u_prev[i+1][j]); 
    }
  }

  //Boundries (colums without corners)
  for (int i=1; i<ny-1; i++){
    u[i][0] = u_prev[i][0]  
                + fact_x * (u_prev[i][1] - 2*u_prev[i][0] + u_prev[i][1]) 
                + fact_y * (u_prev[i-1][0] - 2*u_prev[i][0] + u_prev[i+1][0]); //left column
    u[i][nx-1] = u_prev[i][nx-1]  
                + fact_x * (u_prev[i][nx-2] - 2*u_prev[i][nx-1] + u_prev[i][nx-2]) 
                + fact_y * (u_prev[i-1][nx-1] - 2*u_prev[i][nx-1] + u_prev[i+1][nx-1]); //right column
  }

  //Boundries (rows without corners)
  for (int j=1; j<nx-1; j++){
    u[0][j] = u_prev[0][j]
              + fact_x * (u_prev[0][j-1] - 2*u_prev[0][j] + u_prev[0][j+1])
              + fact_y * (u_prev[1][j] - 2*u_prev[0][j] + u_prev[1][j]); //bottom row
    u[ny-1][j] = u_prev[ny-1][j]
              + fact_x * (u_prev[ny-1][j-1] - 2*u_prev[ny-1][j] + u_prev[ny-1][j+1])
              + fact_y * (u_prev[ny-2][j] - 2*u_prev[0][j] + u_prev[ny-2][j]); //top row
  }

  //Corners
  u[0][0] = u_prev[0][0]  
                + fact_x * (u_prev[0][1] - 2*u_prev[0][0] + u_prev[0][1]) 
                + fact_y * (u_prev[1][0] - 2*u_prev[0][0] + u_prev[1][0]);


  u[ny-1][nx-1] = u_prev[ny-1][nx-1]  
                + fact_x * (u_prev[ny-1][nx-2] - 2*u_prev[ny-1][nx-1] + u_prev[ny-1][nx-2]) 
                + fact_y * (u_prev[ny-2][nx-1] - 2*u_prev[ny-1][nx-1] + u_prev[ny-2][nx-1]); 

  u[ny-1][0] = u_prev[ny-1][0]  
          + fact_x * (u_prev[ny-1][1] - 2*u_prev[ny-1][0] + u_prev[ny-1][1]) 
          + fact_y * (u_prev[ny-2][0] - 2*u_prev[ny-1][0] + u_prev[ny-2][0]);
  
  u[0][nx-1] = u_prev[0][nx-1]  
                + fact_x * (u_prev[0][nx-2] - 2*u_prev[0][nx-1] + u_prev[0][nx-2]) 
                + fact_y * (u_prev[1][nx-1] - 2*u_prev[0][nx-1] + u_prev[1][nx-1]); 


}

void subg_one_fast_time_step (int my_rank, int P, int nx, int my_ny, double dx, double dy, double dt,
                            double **my_u_new, double **my_u, double **my_u_prev){

    double fact_x = dt*dt / (8 * dx*dx);
    double fact_y = dt*dt / (8 * dy*dy);

    int i, j;
    int i_stop = (my_rank==0) || (my_rank==P-1) ? my_ny : my_ny+1;


    for (i=1; i<i_stop; i++){
        //left column
        my_u_new[i][0] = 2*my_u[i][0]  
                    + fact_x * (my_u[i][1] - 2*my_u[i][0] + my_u[i][1]) 
                    + fact_y * (my_u[i-1][0] - 2*my_u[i][0] + my_u[i+1][0])
                    - my_u_prev[i][0]; 

        //Inner square  
        for (j=1; j<nx-1; j++){
            my_u_new[i][j] = 2*my_u[i][j]  
                    + fact_x * (my_u[i][j-1] - 2*my_u[i][j] + my_u[i][j+1]) 
                    + fact_y * (my_u[i-1][j] - 2*my_u[i][j] + my_u[i+1][j])
                    - my_u_prev[i][j];
        } 

        //right column
        my_u_new[i][nx-1] = 2*my_u[i][nx-1]  
                    + fact_x * (my_u[i][nx-2] - 2*my_u[i][nx-1] + my_u[i][nx-2]) 
                    + fact_y * (my_u[i-1][nx-1] - 2*my_u[i][nx-1] + my_u[i+1][nx-1])
                    - my_u_prev[i][nx-1]; 
    }

   
    if(my_rank==0){
        //the lower corners + lower row
        // Bottom left corner: 
        my_u_new[0][0] = 2*my_u[0][0]  
                        + fact_x * (my_u[0][1] - 2*my_u[0][0] + my_u[0][1]) 
                        + fact_y * (my_u[1][0] - 2*my_u[0][0] + my_u[1][0])
                        - my_u_prev[0][0];
        
        // Bottom row (wo/corners):
        for (int j=1; j<nx-1; j++){
            my_u_new[0][j] = 2*my_u[0][j]
                        + fact_x * (my_u[0][j-1] - 2*my_u[0][j] + my_u[0][j+1])
                        + fact_y * (my_u[1][j] - 2*my_u[0][j] + my_u[1][j])
                        - my_u_prev[0][j]; 
        }

        // Bottom right corner: 
        my_u_new[0][nx-1] = 2*my_u[0][nx-1]  
                            + fact_x * (my_u[0][nx-2] - 2*my_u[0][nx-1] + my_u[0][nx-2]) 
                            + fact_y * (my_u[1][nx-1] - 2*my_u[0][nx-1] + my_u[1][nx-1])
                            - my_u_prev[0][nx-1]; 

    }

    if(my_rank==P-1){
        // Top left corner:
        my_u_new[my_ny][nx-1] = 2*my_u[my_ny][nx-1]  
                        + fact_x * (my_u[my_ny][nx-2] - 2*my_u[my_ny][nx-1] + my_u[my_ny][nx-2]) 
                        + fact_y * (my_u[my_ny-1][nx-1] - 2*my_u[my_ny][nx-1] + my_u[my_ny-1][nx-1])
                        - my_u_prev[my_ny][nx-1]; 

        //Top row (wo/corners): 
        for (int j=1; j<nx-1; j++){
            my_u_new[my_ny][j] = 2*my_u[my_ny][j]
                    + fact_x * (my_u[my_ny][j-1] - 2*my_u[my_ny][j] + my_u[my_ny][j+1])
                    + fact_y * (my_u[my_ny-1][j] - 2*my_u[my_ny][j] + my_u[my_ny-1][j])
                    - my_u_prev[my_ny][j]; 
        }

        //Top  right corner: 
        my_u_new[my_ny][0] = 2*my_u[my_ny][0]  
                + fact_x * (my_u[my_ny][1] - 2*my_u[my_ny][0] + my_u[my_ny][1]) 
                + fact_y * (my_u[my_ny-1][0] - 2*my_u[my_ny][0] + my_u[my_ny-1][0])
                - my_u_prev[my_ny][0];
    
    
    }


}
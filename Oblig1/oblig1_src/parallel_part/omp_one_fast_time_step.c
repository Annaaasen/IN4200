#include <omp.h>

void omp_one_fast_time_step (int nx, int ny, double dx, double dy, double dt,
			     double **u_new, double **u, double **u_prev)
{
    int i, j, i_below, i_above, j_left, j_right; 

    double fact_x = dt*dt / (8 * dx*dx);
    double fact_y = dt*dt / (8 * dy*dy);

    //Inner square 
    #pragma omp parallel for collapse(2)
    for (i=1; i<ny-1; i++){
        for (j=1; j<nx-1; j++){
            u_new[i][j] = 2*u[i][j]  
                    + fact_x * (u[i][j-1] - 2*u[i][j] + u[i][j+1]) 
                    + fact_y * (u[i-1][j] - 2*u[i][j] + u[i+1][j])
                    - u_prev[i][j];
        } 
    }

    //Boundries (colums without corners)
    #pragma omp parallel for
    for (i=1; i<ny-1; i++){
        //left column
        u_new[i][0] = 2*u[i][0]  
                    + fact_x * (u[i][1] - 2*u[i][0] + u[i][1]) 
                    + fact_y * (u[i-1][0] - 2*u[i][0] + u[i+1][0])
                    - u_prev[i][0]; 
        
        //right column
        u_new[i][nx-1] = 2*u[i][nx-1]  
                    + fact_x * (u[i][nx-2] - 2*u[i][nx-1] + u[i][nx-2]) 
                    + fact_y * (u[i-1][nx-1] - 2*u[i][nx-1] + u[i+1][nx-1])
                    - u_prev[i][nx-1]; 
    }

    //Boundries (rows without corners)
    #pragma omp parallel for
    for (j=1; j<nx-1; j++){
        //bottom row
        u_new[0][j] = 2*u[0][j]
                    + fact_x * (u[0][j-1] - 2*u[0][j] + u[0][j+1])
                    + fact_y * (u[1][j] - 2*u[0][j] + u[1][j])
                    - u_prev[0][j]; 

        //top row
        u_new[ny-1][j] = 2*u[ny-1][j]
                    + fact_x * (u[ny-1][j-1] - 2*u[ny-1][j] + u[ny-1][j+1])
                    + fact_y * (u[ny-2][j] - 2*u[ny-1][j] + u[ny-2][j])
                    - u_prev[ny-1][j]; 
    }

    //Corners
    u_new[0][0] = 2*u[0][0]  
                + fact_x * (u[0][1] - 2*u[0][0] + u[0][1]) 
                + fact_y * (u[1][0] - 2*u[0][0] + u[1][0])
                - u_prev[0][0];


    u_new[ny-1][nx-1] = 2*u[ny-1][nx-1]  
                    + fact_x * (u[ny-1][nx-2] - 2*u[ny-1][nx-1] + u[ny-1][nx-2]) 
                    + fact_y * (u[ny-2][nx-1] - 2*u[ny-1][nx-1] + u[ny-2][nx-1])
                    - u_prev[ny-1][nx-1]; 

    u_new[ny-1][0] = 2*u[ny-1][0]  
                    + fact_x * (u[ny-1][1] - 2*u[ny-1][0] + u[ny-1][1]) 
                    + fact_y * (u[ny-2][0] - 2*u[ny-1][0] + u[ny-2][0])
                    - u_prev[ny-1][0];
    
    u_new[0][nx-1] = 2*u[0][nx-1]  
                    + fact_x * (u[0][nx-2] - 2*u[0][nx-1] + u[0][nx-2]) 
                    + fact_y * (u[1][nx-1] - 2*u[0][nx-1] + u[1][nx-1])
                    - u_prev[0][nx-1]; 

}


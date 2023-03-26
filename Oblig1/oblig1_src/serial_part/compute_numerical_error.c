#include <math.h>
#define Pi M_PI

double compute_numerical_error (int nx, int ny, double dx, double dy,
                                double t_value, double **u)
{
  double y, x, u_true; 

  double pi_t = cos(Pi * t_value);
  double sum = 0;

  for (int i=0; i<ny-1; i++){
    y = i*dy;
    for (int j=0; j<nx-1; j++){
      x = j*dx;
      u_true = cos(2*Pi*x) * cos(2*Pi*y) * pi_t; 
      sum += (u_true - u[i][j])*(u_true - u[i][j]);
    }
  }

  double err = sqrt(dx * dy * sum);

  return err;
}

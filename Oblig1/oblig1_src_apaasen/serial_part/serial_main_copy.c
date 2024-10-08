#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "functions.h"

#define Pi M_PI

int main (int nargs, char **args)
{
  int nx = 1001, ny = 1001; // default values of nx and ny
  double T = 2.0;

  int i,j;
  double dx, dy, dt, t;
  double **u, **u_new, **u_prev, **tmp_ptr;

  if (nargs>1)  // if a new value of nx is provided on the command line
    nx = ny = atoi(args[1]);

  if (nargs>2)  // if a new value of T is provided on the command line
    T = atof(args[2]);

  allocate_2D_array (&u,nx,ny);
  allocate_2D_array (&u_new,nx,ny);
  allocate_2D_array (&u_prev,nx,ny);

  dx = 1.0/(nx-1);
  dy = 1.0/(ny-1);
  dt = 2.0*dx;  // maximum value allowed for the time step size

  // set initial condition
  for (i=0; i<ny; i++)
    for (j=0; j<nx; j++)
      u_prev[i][j] = cos(2.0*Pi*j*dx)*cos(2.0*Pi*i*dy);


  // compute the first time step, that is, compute u using u_prev values
  first_time_step (nx, ny, dx, dy, dt, u, u_prev);

  double start1 = clock();
  // compute the remaining time steps
  t = dt;
  while (t<T) {
    t += dt;
    // compute u_new using u and u_prev
    one_regular_time_step (nx, ny, dx, dy, dt, u_new, u, u_prev);
    /* pointer swaps */
    tmp_ptr = u_prev; //now they point to the same address
    u_prev = u;
    u = u_new;
    u_new = tmp_ptr;
  }
  double end1 = clock();
  printf("%.f\n", 1000*(end1-start1)/CLOCKS_PER_SEC);

  printf("nx=%d, ny=%d, T=%g, dt=%g, error=%e\n",nx,ny,t,dt,
	 compute_numerical_error(nx,ny,dx,dy,t,u)); 

  // ---- recompute the numerical solution using a faster implementation of each time step ----

  // set initial condition
  for (i=0; i<ny; i++)
    for (j=0; j<nx; j++)
      u_prev[i][j] = cos(2.0*Pi*j*dx)*cos(2.0*Pi*i*dy);

  // compute the first time step, that is, compute u using u_prev values
  first_time_step (nx, ny, dx, dy, dt, u, u_prev);

  double start2 = clock(); 
  // compute the remaining time steps using a faster implementation
  t = dt;
  while (t<T) {
    t += dt;
    // compute u_new using u and u_prev
    one_fast_time_step (nx, ny, dx, dy, dt, u_new, u, u_prev);
    /* pointer swaps */
    tmp_ptr = u_prev;
    u_prev = u;
    u = u_new;
    u_new = tmp_ptr;
  }
  double end2 = clock();
  printf("%.f\n", 1000*(end2-start2)/CLOCKS_PER_SEC);

  printf("nx=%d, ny=%d, T=%g, dt=%g, error=%e\n",nx,ny,t,dt,
	 compute_numerical_error(nx,ny,dx,dy,t,u));

  deallocate_2D_array (u_new);
  deallocate_2D_array (u);
  deallocate_2D_array (u_prev);

  return 0;
}

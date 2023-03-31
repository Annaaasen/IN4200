#include <stdlib.h>

void allocate_2D_array (double ***array_ptr, int nx, int ny)
{
  // As we want to change the doulbe pointer array_ptr, we need to send in its pointer@
  *array_ptr = malloc(ny * sizeof(*array_ptr));
  (*array_ptr)[0] = malloc(ny * nx * sizeof((*array_ptr)[0])); //This is a 1D array
  for (int i=1; i<ny; i++){
    (*array_ptr)[i] = &((*array_ptr)[0][nx * i]); //This is the address of the i'th row
  }
}

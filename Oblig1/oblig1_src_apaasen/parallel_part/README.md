# IN4200 - First Obligatory Assignment - Parallel Part

### About the Project
This folder contains code parallelized through OpenMP to compute the numerical solution of a 2D wave equation over a certain time interval. The calculations are done in a "regular" way, containing if-statements, and a "fast" way, avoiding such statements; presumably making the code easier to parallelize. One of the objectives of this assignment is to compare the calculation time of these two manners of calculations. 
 


### Running the Code
The folder contains a makefile which simplify the compiling and running of the code. In the terminal one can write either 
```
make compile
make run
```

or 
```
make all
```

The output in the terminal should be:
```
gcc-12 -fopenmp -o para_main.o \
	../serial_part/allocate_2D_array.c \
	../serial_part/deallocate_2D_array.c \
	omp_compute_numerical_error.c \
	omp_first_time_step.c \
	omp_one_regular_time_step.c \
	omp_one_fast_time_step.c \
	para_main.c  
./para_main.o 
Regular time step: 
nx=1001, ny=1001, T=2, dt=0.002, error=2.996852e-15, calculation time=1.590e+00s
Fast time step: 
nx=1001, ny=1001, T=2, dt=0.002, error=2.996852e-15, calculation time=1.571e+00s
```


To remove all of the executable files in the folder simple run the command

```
make clean
```
It should be mentioned that this code has been tested on a Mac with M1 chip and gcc-version 12 (the gcc-version is specified in the makefile to avoid clang being run instead of gcc). 
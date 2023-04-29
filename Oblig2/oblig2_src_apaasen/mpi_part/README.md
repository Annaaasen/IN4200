# IN4200 - Second Obligatory Assignment - MPI Parallelisation 

## About the Project
This folder contains the parallel code to compute the numerical solution of a 2D wave equation over a certain time interval. The calculations are done in a similar way as the first project, but now the method of parallelisation is MPI (as apposed to OpenMP). This is a form of distributed memory parallel programming. 
 

## Running the Code
The folder contains a makefile which simplify the compiling and running of the code. In the terminal one can write either 
```
make compile
make run
```

or 
```
make all
```
The output in the terminal should then be 
```
mpicc mpi_main.c -o mpi_main.o \
	../serial_part/allocate_2D_array.c \
	../serial_part/deallocate_2D_array.c \
	subg_first_time_step.c \
	communicate_above_below.c \
	subg_one_fast_time_step.c \
	all_compute_numerical_error.c \
	-Wall
mpirun -np 4 ./mpi_main.o
my_rank=1, nx=1001, my_ny=250, T=2, dt=0.002, error=1.575691e-15
my_rank=2, nx=1001, my_ny=250, T=2, dt=0.002, error=1.522565e-15
my_rank=3, nx=1001, my_ny=251, T=2, dt=0.002, error=1.473711e-15
my_rank=0, nx=1001, my_ny=250, T=2, dt=0.002, error=1.422142e-15
The process took 1.562824 seconds to run
```
Where the number and order of lines starting with "my_rank" might vary. 

To alter the number of processes being used (no more that 5/6, at least on a similar computer as Macbook Air M1), simply run
```
make all n_processes = 
```
an fill in with the wanted number of processes. 

To remove all of the executable files in the folder simple run the command

```
make clean
```
It should be mentioned that this code has been tested on a Mac with M1 chip and mpicc.

## Interpreting the results
We can see that each process yields a very small error, summing to a total error in the same range as the serial code in project 1. This indicates that the calculations have been done correctly. 

By trial, we found that the number of processes yielding the shortest running time was 4 with ≈1.6 seconds. Compared to the serial part of project 1, with ≈6 seconds running time, this was a considerable improvement. However, the employment of more than 4 processes seemed to slow down the calculation rather than speeding it up. This could eg. be due to an overhead from communication between the processes.


## Comments on the code
At one point in ```mpi_main.c``` the function ```MPI_Barrier()``` is called. The idea behind this was to make sure all threads had printed their results before the time was measured and printed. However, it does not work as intended. Often the print statement about running time comes before each rank's error. Although, neither did it appear to slow down the running time. 

In ```communicate_above_below.c``` the function MPI_Sendrecv() could have been employed, but to fully understand the processes behind, a shift of the send/recv-order depending on odd/even numbers was employed instead. 
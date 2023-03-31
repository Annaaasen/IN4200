# IN4200 - First Obligatory Assignment - Serial Part

### About the Project
This folder contains the serial code to compute the numerical solution of a 2D wave equation over a certain time interval. The calculations are done in a "regular" way, containing if-statements, and a "fast" way, avoiding such statements.
 

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
The output in the terminal should the be 
```
gcc -o serial_main.o \
	allocate_2D_array.c \
	deallocate_2D_array.c \
	compute_numerical_error.c \
	first_time_step.c \
	one_regular_time_step.c \
	one_fast_time_step.c \
	serial_main.c 
./serial_main.o 
nx=1001, ny=1001, T=2, dt=0.002, error=2.996852e-15
nx=1001, ny=1001, T=2, dt=0.002, error=2.996852e-15
```


To remove all of the executable files in the folder simple run the command

```
make clean
```
It should be mentioned that this code has been tested on a Mac with M1 chip and gcc-version 12 (the gcc-version is specified in the makefile to avoid clang being run instead of gcc). 
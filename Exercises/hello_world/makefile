all: all_mpi all_openmp


all_mpi: compile_mpi run_mpi 

compile_mpi:
	mpicc hello_world_mpi.c -o hello_world_mpi.o

run_mpi: 
	mpirun -np 4 ./hello_world_mpi.o



all_openmp: compile_openmp run_openmp 

compile_openmp:
	gcc-12 -fopenmp hello_world_openmp.c -o hello_world_openmp.o

run_openmp:
	./hello_world_openmp.o



clean: 
	rm *o
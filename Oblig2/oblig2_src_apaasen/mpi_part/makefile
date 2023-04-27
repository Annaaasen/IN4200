all: compile run

compile:
	mpicc mpi_main.c -o mpi_main.o \
	../serial_part/allocate_2D_array.c \
	../serial_part/deallocate_2D_array.c \
	subg_first_time_step.c \
	communicate_above_below.c \
	-Wall

run: 
	mpirun -np 4 ./mpi_main.o

clean: 
	rm *o
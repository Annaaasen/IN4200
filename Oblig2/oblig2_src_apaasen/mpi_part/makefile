CC = mpicc
FLAGS = -Wall

n_processes ?= 4

all: compile run

compile:
	$(CC) \
	mpi_main.c \
	../serial_part/allocate_2D_array.c \
	../serial_part/deallocate_2D_array.c \
	subg_first_time_step.c \
	communicate_above_below.c \
	subg_one_fast_time_step.c \
	all_compute_numerical_error.c \
	-o mpi_main.o \
	$(FLAGS)

run: 
	mpirun -np $(n_processes) ./mpi_main.o

clean: 
	rm *.o
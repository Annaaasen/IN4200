all: compile run 

compile:
	gcc-12 -fopenmp -o para_main.o \
	../serial_part/allocate_2D_array.c \
	../serial_part/deallocate_2D_array.c \
	omp_compute_numerical_error.c \
	omp_first_time_step.c \
	omp_one_regular_time_step.c \
	omp_one_fast_time_step_revised.c \
	para_main.c \
	-Wall 

run:
	./para_main.o 

clean: 
	rm *o 
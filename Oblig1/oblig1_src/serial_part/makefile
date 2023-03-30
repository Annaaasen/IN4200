
all: compile run 

compile:
	gcc -o serial_main.o \
	allocate_2D_array.c \
	deallocate_2D_array.c \
	compute_numerical_error.c \
	first_time_step.c \
	one_regular_time_step.c \
	one_fast_time_step.c \
	serial_main_copy.c 
	

run:
	./serial_main.o 

clean: 
	rm *o 
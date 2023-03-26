FLAGS = -Wall  -fsanitize=undefined -fsanitize=address -lm -Wextra -Wfloat-equal -Wconversion -O3  -g
CC := gcc-12


PROJ = test
OBJS = test.c

all:  $(PROJ) $(OBJS) test run 

test: $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $@.x 

run:
	./test.x

obj-clean:
	$(RM) *.o

exec-clean:
	$(RM) *.x

autosave-clean:
	$(RM) *~

clean:
	$(MAKE) obj-clean
	$(MAKE) exec-clean
	$(MAKE) autosave-clean
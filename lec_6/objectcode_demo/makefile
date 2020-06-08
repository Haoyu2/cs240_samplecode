client = client
objects = string.o math.o client.o
FLAGS = -Wall


$(client) : $(objects)
	gcc $(FLAGS) $^ -o $@
%.o : %.c
	gcc -c $(FLAGS) $< -o $@
clean:
	rm $(client) $(objects)

mylib :  $(objects)
	ar crs libmylib.a *.o
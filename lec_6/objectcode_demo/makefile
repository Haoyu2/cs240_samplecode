client = client
objects = string.o math.o 
FLAGS = -Wall


$(client) : $(objects)
	gcc $(FLAGS) client.c -o $@ $^
%.o : %.c
	gcc -c $(FLAGS) $< -o $@ 
clean:
	rm $(client) $(objects)

run :$(client)
	

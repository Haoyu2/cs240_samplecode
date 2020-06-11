client = client
objects = Client.o  Recursion.o Sort.o
FLAGS = -Wall





all: $(client) 
	./client

$(client) : $(objects)
	gcc $(FLAGS) $^ -o $@

objs/%.o : %.c 
	gcc -c $(FLAGS) $< -o $@
	
clean: $(client) 
	rm $(client) $(objects)

mylib :  $(objects)
	ar crs libmylib.a *.o
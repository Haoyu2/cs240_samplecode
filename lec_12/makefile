client = client
objects = Client.o  Recursion.o Sort.o Random.c pointer.o
FLAGS = 





all: $(client) 
	./client

$(client) : $(objects)
	gcc $(FLAGS) $^ -o $@

%.o : %.c 
	gcc -c $(FLAGS) $< -o $@
	
clean: $(client) 
	rm -f $(client) $(objects)

mylib :  $(objects)
	ar crs libmylib.a *.o
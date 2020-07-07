client = client
objects = Client.o  Recursion.o Sort.o Random.o pointer.o \
			DynamicAllocation.o FunctionPointer.o Struct.o \
			Array.o Stack.o

FLAGS = 





all: $(client) 
	./client

$(client) : libmylib.a
	gcc $(FLAGS) $^ -o $@

%.o : %.c 
	gcc -c $(FLAGS) $< -o $@
	
clean: $(client) 
	rm -f $(client) $(objects)

libmylib.a :  $(objects)
	ar crs  $@ *.o
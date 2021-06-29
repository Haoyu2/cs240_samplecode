client = client
objects = Client.o  pointer.o
FLAGS = 



clean: all 
	@rm -f $(client) $(objects)

all: $(client) 
	./client

$(client) : $(objects)
	@gcc $(FLAGS) $^ -o $@

%.o : %.c 
	@gcc -c $(FLAGS) $< -o $@
	


mylib :  $(objects)
	@ar crs libmylib.a *.o
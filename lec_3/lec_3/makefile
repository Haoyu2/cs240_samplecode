
exe = main.exe

exe-debug = main-debug.exe

srcs = *.c


all : clean
run : $(exe)
	./$(exe)

$(exe) : $(srcs)
	gcc $^ -o $@ 

clean : run
	rm $(exe)


debug : $(exe-debug)
	./$(exe-debug)
	rm $(exe-debug)

$(exe-debug) :  $(srcs)
	gcc $^ -o $@ -D DEBUG=10
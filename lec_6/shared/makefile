
 

run: test
	LD_LIBRARY_PATH=$(shell pwd):$(LD_LIBRARY_PATH) ./test

test : main.c libfoo.so
	gcc -Wall -o $@ @< -lfoo -L .

libfoo.so:
	gcc -Wall -shared -fpic foo.c -o libfoo.so




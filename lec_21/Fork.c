#include <unistd.h>

#include "lec8.h"
#include "pointer.h"
#include "Array.h"

#include <errno.h>








// we program binary executable
// fork many process of the same program
// within each process it may have multi threads

void testFork()
{

	// // system("ls");
	// printf("Hello World!\n");

	// int this_pid = fork();// the child process will execute the statment differently
	// // for the child process, this_pid will be zero, for the parent this_pid will be the 
	// // pid of the child process.
	
	// // the fork here will create a child process

	// if (this_pid <0) exit(EXIT_FAILURE);
	
	// printf("Current pid:%d\t this_pid:%d\n", getpid(),this_pid);
	
	// if(this_pid)
	// 	printf("In parent process:%d\n", getpid());
	// else
	// 	printf("In child process:%d\n", getpid());

	
	// printf("%d\n", EXIT_FAILURE);

	// printf("Hello, this is a snippet.\n");
}
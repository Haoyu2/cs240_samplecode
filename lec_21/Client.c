/* 
* Author : Haoyu Wang
* Description:
*	
*/

#include "lec8.h"
#include "pointer.h"
#include "Array.h"
#include <stdlib.h>
#include <errno.h>

// argv is array of char pointer

int main(int argc, char *argv[])
{

 	// testStack();

	// testStruct();
	// testFP();
	// testPadding();
	// testFork();


	testLL();







	// for(int i=0;i<10;i++,errno=i){
	// 	fprintf(stderr,"Errno %2u in ", errno);
	// 	perror("main:");
	// }

	// errno = 22;
	// perror("");// perror print out human readable error message coresponds to the errno
	// printf("----------\n");


	// for(int i=0;i<10;i++,errno=i){
	// 	fprintf(stderr,"In main: Strerror:%s\n",
	// 	strerror(errno));
	// }


	// printf("there is an error  like this:%s\n", strerror(32));
	// return 0;






	return EXIT_SUCCESS;
}
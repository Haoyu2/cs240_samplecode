// 
// 
#include <stdio.h>


// 1 byte = 8 bits
//  8 bits is: 
// for unsigned [0, 2^8 -1]
// for signed it is 
//  1 1 1 1 1 1 1 1 




int main(int argc, char const *argv[])
{

	// sizeof function will receive a data type
	// return its memery usage in bytes in unsign long
	printf("char data type %lu byte\n",  sizeof(char));

	printf("long data type %lu byte\n", sizeof(long));	
	printf("int data type %lu bytes\n", sizeof(int));
	return 0;
}
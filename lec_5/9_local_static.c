/* 
* Author : Haoyu Wang
* Description:
*	
*/

#include <stdio.h>


int counter(){
	
	// non-static local variable will initilized for
	// every funcion call.
	// int counts = 0;


	static int counts = 0;
	// The static local variables will only
	// be initilized once for the whole program
	// and will retain the value after each function call


	return ++counts;
}

int main(int argc, char *argv[])
{
	register int counts;
	for(int i=0;i< 10;i++){
		counts = counter();
	}
	printf("%d\n",counts);

	// register int i;
	// int *p=&i ;

	return 0;
}
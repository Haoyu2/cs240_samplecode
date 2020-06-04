/* 
* Author : Haoyu Wang
* Description:
*
* local variable if not defined locally then goes to the external variable
*
*/
#include <stdio.h>

extern float pi;
int add(int , int );

int main(int argc, char *argv[])
{
	

	// Can we print pi here ?

	printf("%g\n", pi);

	// can we redefine pi here ?
	float pi;
	pi = 3.1;
	printf("%g\n", pi);	

	
	return 0;
}
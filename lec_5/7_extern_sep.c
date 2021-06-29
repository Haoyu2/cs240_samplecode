/* 
* Author : Haoyu Wang
* Description:
*
* local variable if not defin\ed locally then goes to the external variable
*
*/
#include <stdio.h>

extern float *pi_a;
float pi;
int add(int , int );

int main(int argc, char *argv[])
{
	

	// Can we print pi here ?


	extern float pi;
	printf("%g\n", pi);
	printf("0 file PI:%p\n",&pi);

	printf("1 File PI:%p\n",pi_a);

	// can we redefine pi here ?
	// float pi;
	// pi = -3.1;
	// printf("%g\n", pi);	
	// printf("Local PI:%p\n", &pi);


	
	return 0;
}

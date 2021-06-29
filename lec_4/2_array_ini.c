
/* 
* Author : Haoyu Wang
* Description:
*
*
*/
#include <stdio.h>
#include <string.h>


void f(int a[], int len){

	int b[3];
	// printf("%ld\n",sizeof(a) );
	printf("%ld\n", sizeof(b));
}


int main(int argc, char *argv[])
{
	// int a[] = {1,2,3};
 //    int b[5] = {1,2,3}; 
 //    int c[5] = {[1]=-1,[4]=-2};
 //    // after c99; designated initializer

 //    printf("b[4] %d\n", b[4]);
	// printf("c[4] %d\n", c[4]);

	// printf("the length of a is  %lu\n", sizeof(a)/sizeof(int));

	// printf("%ld\n", sizeof(a));

	// int d[3];
	// for (int i=0;i<3;i++){
	// 	d[i] = a[i];
	// }

	printf("%s\n", "\"Hello\"");

	printf("Null character: %d\n", '\0');

	char str[] = "hello\n";

	printf("size of the str: %lu\n", sizeof(str));

	if (!'\0') printf("True\n");
	printf("%d\n", !'\0');

	int c;
	if (c=9)printf("True\n");
	// this is valid statements
	// and it prints for ever. c=9 evaluates to 9

	// 9 = c;// this is illegal

	return 0;
}
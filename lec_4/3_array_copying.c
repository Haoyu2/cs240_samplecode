
/* 
* Author : Haoyu Wang
* Description:
*
*
*/
#include <stdio.h>
#include <string.h>


int main(int argc, char *argv[])
{
	int a[] = {1,2,3}, b[3], *p;
	// b = a;
	// p=a;
	// for (int i=0;i<3;i++)
	// 	b[i] = a[i];


	// memcpy(b,a, sizeof(a));

	// for (int i=0;i<3;i++)
	// 	printf("%d\t", b[i]);
	// printf("\n");

	// int c=1,d=0;

	// // d = c;
	// printf("%d\n", d);
	// // memcpy(c,d,sizeof(c));
	// memcpy(&c,&d,sizeof(c));
	// printf("%d\n", c);

	// a+1 <==> &a[1]
	// a <==> a+0 <==> &a[0]
	// memmove(a+1,a, 2*sizeof(int));
	// for (int i=0;i<3;i++)
	// 	printf("%d\t", a[i]);
	// printf("\n");
		// printf("%s\thello\n","good" );

	int arr[] = {1,2,3};
	char s1[] = { 'h', 'e','e', 'l', 'o',0};
	char s[] = "heelo"; // '\0' == 0;
	


	printf("%ld\n", sizeof(s));
	printf("%ld\n", sizeof(s1));

	printf("%s\n", s);
	printf("%s\n", s1);

	if (1) printf("heelo\n");


	int x=0,y;

	// the expression will assume the value of the left of the equal sign
	printf("%d\n",  x=10 );

// while (x=10)  <==> while (10)  while is a endless loop.




	return 0;
}
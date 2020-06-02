
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

	// int i;

	// char s1[4];
	// s1[1] =1;

// 0x7fff1a9a596b	0000 0000
// 0x7fff1a9a596a
// 0x7fff1a9a5969
// 0x7fff1a9a5968   0000 0001   &a




// arr[1]   // 0x7fff1a9a5970
// arr[0]	// 0x7fff1a9a596f   0000 0000
			// 0x7fff1a9a596e 
			// 0x7fff1a9a596d 
			// 0x7fff1a9a596c   0000 0001    arr (3*4) 12 bytes

	int a,arr[3];
	a=1;

	printf("%p\n", &a);
	printf("%d\n", a);



	printf("%p\n", arr);
	printf("%p\n", &arr);
	printf("%d\n", arr[0]);


	// printf("%d\n", arr[4]);




	return 0;
}
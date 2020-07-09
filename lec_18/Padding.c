/* 
* Author : Haoyu Wang
* Description:
*	
*/

#include "lec8.h"
#include "pointer.h"
#include "Array.h"
#include <stdint.h>




typedef struct {
	char *p;  /* 8 bytes */
	char c;   /* 1 byte */ // here the c ompiler padded extra 7 bytes
	long x;   /* 8 bytes */
} foo;


typedef struct __attribute__((__packed__)){
	char *p;	/* 8 bytes */
	char c;		/* 1 byte */
	long x;		/* 8 bytes */
}foo1;

typedef struct {
	int i;  //4
	short j; //2  2 padded
	int k;  // 4
} Foo2;

typedef struct {
	int i; //4
	short j;  // 2 2 padded
	long k; // 8 
} foo3;





void  testEndianess()
{


	int i = 0x12345678; // i takes 4 bytes

	// 0111 1000  0101 0110 0011 0100 0001 0010  little 
	// 	  7    8     5    6    3    4    1    2

	// 0001 0010  0011 0100 0101 0110 0111 1000  big
//0x//    1    2     3    4	   5    6    7    8	


// unsigned char <==> uint8_t
	uint8_t *p = (uint8_t *) &i;

	for (int i = 0; i < 4; ++i)
	{
		printf("%x\t", p[i]);
	}
	 

	int j = 1;

	// 0000 0001  0000 0000 0000 0000 0000 0000  little 
	// 0000 0000  0000 0000 0000 0000 0000 0001  big

	uint8_t *p1 = (uint8_t *) &j;
	if (*p1==1)
		printf("little endianess\n");
	else
		printf("big endianess\n");


}





void testPadding()
{

	// printf("%ld\n", sizeof(foo));
	// printf("%ld\n", sizeof(foo1));
	// printf("%ld\n", sizeof(Foo2));
	// printf("%ld\n", sizeof(foo3));

	testEndianess();



}
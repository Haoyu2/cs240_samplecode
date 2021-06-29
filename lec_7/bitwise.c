/* 
* Author : Haoyu Wang
* Description:
*	
*/

#include <stdio.h>



void getBinary(unsigned num)
{
	int j=1; int k=1;
	for(int i=sizeof(num)*8-1;i>=0;i--){
		
		if (num & j<<i) 
			putchar('1');
		else
			putchar('0');

		if ((k++ % 8)==0)  putchar(' ');
	}
	printf("\n");
}


//  i = 252 , n = 4
// 00000000 00000000 00000000 11111100
// 00000000 00000000 00000000 00001111  &
// 00000000 00000000 00000000 00001100

// left shit pad the lower bit with 0


// because bitwise operation donot append 1's
// so we get all 1's first and then shift and append 0's
//
// 11111111 11111111 11111111 11111111   ~0
// 11111111 11111111 11111111 11110000   << 4                              
// 00000000 00000000 00000000 00001111　　~
				



unsigned getLower(unsigned i, int n)
{

	return i & (~ (~0 << n));

}


// 252 , 4
// 00000000 00000000 00000000 11111100
// 11110000 00000000 00000000 00000000  &
// 00000000 00000000 00000000 00001100

// left shit pad the lower bit with 0

// 11111111 11111111 11111111 11111111   ~0
// 11110000 00000000 00000000 00000000   << (32 - 4)                              
// 11110000 00000000 00000000 00000000　　~
	

unsigned getHigher(unsigned i, int n)
{

	return i &  (~0 << (sizeof(i)*8-n));

}


// 11111111 11111111 11111111 11111111   ~0
// 00001111 11111111 11111111 11111111   4 >>                             
// 11110000 00000000 00000000 00000000　　~

// right shift with usigned integer is implementation based
// be careful.  Use unisgied integer it is universal  e.g. 0u.

unsigned getHigher1(unsigned i, int n)
{

	getBinary((~0u)>>n);
	return i & (~ ((~0u)>>n));

}



int main(int argc, char *argv[])
{


	// getBinary(15);	
	// getBinary(31);
	// getBinary(252);


	// unsigned i = 15;
	// unsigned j = ~15;
	// getBinary(~15);

	// getBinary(15 & (~15));
	// getBinary((~15) + 1); 

	// getBinary(((~15)) ^ 15);

	// getBinary(15 << 1);
	// printf("%d\n\n", 15<<1);
	// getBinary(8);
	// getBinary(8>>1);
	// printf("%d\n\n", 8<<1);

	// getBinary(15 >> 1);
	// printf("%d\n\n", 15>>1);


	// getBinary(1<<31);


	// for(int i=31;i>=0;i--){
		
	// 	getBinary(1<<i);
	// }



	printf("getLower 4\n");

	getBinary(252);
	getBinary(getLower(252,4));

	getBinary(getHigher(~0,4));
	printf("\n");

	getBinary(~0);
	getBinary(getHigher1(~0,4));

	// printf("%ld\n", sizeof(unsigned));


	// printf("%d\n",0xcc );

	// //0xcc   a 10 b 11 c 12
	// // 12*16 + 12 = 204

	// // 067
	// // 6*8 + 7 = 48 + 7 = 55
	// printf("%d\n",067 );


	return 0;
}
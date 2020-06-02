/* Project: lec3
 * Name   : Haoyu Wang
 * Date   : 01/03/2020
 */
#include <stdio.h>
#include <float.h>
#include <limits.h>
#include <math.h>

void bin_char(unsigned char n) 
{ 
    printf("%11d\t:\t",(signed char) n );
    unsigned i, j=0; 
    for (i = 1 << 7; i > 0; i = i / 2) {
        (n & i)? printf("1"): printf("0"); 

    }
    printf("\n");
}

void bin(unsigned n) 
{ 
    printf("%11d\t:\t",n );
    unsigned i, j=0; 
    for (i = 1 << 31; i > 0; i = i / 2) {
        (n & i)? printf("1"): printf("0"); 
        if( (j+1) % 8==0) printf(" ");
        j++;
    }
    printf("\n");
}

int main(void)
{


    // bin(INT_MIN);
    // bin_char(CHAR_MIN);
    // printf("%g\n",fabs(CHAR_MIN) );

    char c = 2;

    bin_char(c);

    // unsigned char 8 bits for value
    // for signed char 7 bits for value the most left bit is signed bit. 0 indicates positive and 1 indicates negative numbers.
    // unsigned char [0, 2^8],  for signed char [-2^7-1, 2^7],

    char c1=-4;
    bin_char(c1);

    printf("%d\n",(unsigned char) c1 );

    // 11111100 = 252

    printf("%d\n", CHAR_MIN);
    printf("%d\n",CHAR_MAX );


    printf("%d\n", 077);
    // 077 is octal number


    // printf("%d\n", 0x10);

    // printf("%d\n", 0xa);

    // printf("%lld\n",(long long) 10 );


    

  return 0;
}
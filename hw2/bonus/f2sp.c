/*
 *
 * project: hw2_bonus Question
 * name:
 * account: 
 * date: 
 * file: 
 * notes:

0 00000000 00000000000000000000001 2^-149 

0 00000001 00000000000000000000000 2^-126

0 01111111 00000000000000000000000 1

0 00000000 00000000000000000000000 0

1 10000000 00000000000000000000000 -2

    char sm[33], com;
    char sc[33] ={
    '0','0','0','0','0','0',
    '0','0','0','0','0','0','0',
    '0','0','0','0','0','0','0',
    '0','0','0','0','0','0','0',
    '0','0','0','0','0'};
    float f=0.0f;
    bin_char(f, sm);
	print_sp(sm);
	com = !(strcmp(sm,sc));
	assert(com);

 */


#include <math.h>
#include <string.h>
#include <assert.h>
#include <stdio.h>

/* print out a char array of single-precision foramt of float*/
void print_sp(char s[]){
    int i=0;
    while(s[i]){
        if(1==i || 9==i)
            printf("%c",' ' );
        printf("%c", s[i++]);
    }
    printf("\n");
}

/* Read bits into a char array 
*  from memory of a 32-bit data type
*/
void bin_char(float f, char s[]) 
{ 
    unsigned n = *((unsigned *) &f);
    unsigned i, j=0; 
    for (i = 1 << 31; i > 0; i = i / 2) {
        s[j++] = (n & i)?  '1' : '0';
    }
    s[j] = 0;
}


/* Convert floats into binary char array
*  Uncomment this function and finish it 

void f2sp(float f, char f_sp[]){

}

*/




int main(void)
{

	char sm[33], sc[33], com;
    for (int i=-149; i<128;i ++) {

    	float f = pow(2,i);
        bin_char(f, sm);
        // bin_char(f, sc);
		f2sp(f, sc);
		com = !(strcmp(sm,sc));
		assert(com);    
    }
}




 

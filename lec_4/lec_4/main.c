#include <stdio.h>
#include <ctype.h>
#include <float.h>
#include <math.h>


/**
 * @brief gets the bits representation of 
 *    unsigned char in memory
 * @details [long description]
 * 
 * @param char [description]
 */
void bin_char(unsigned char n) 
{ 
    printf("%11d\t:\t",(signed char) n );
    unsigned i, j=0; 
    for (i = 1 << 7; i > 0; i = i / 2) {
        (n & i)? printf("1"): printf("0"); 

    }
    printf("\n");
}

/**
 * @brief gets the bits representation of an 
 * 		unsigned	integer in memory
 * @details [long description]
 * 
 * @param n [description]
 */
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



void demo3(){
	printf("%c\n", 67);
	printf("%d\n", isdigit('1'));
	printf("%d\n", ('\n'));
	printf("%d\n", '0');
	printf("%d\n", 0);
	printf("%s\n", "0");


	printf("%d\n", 10);
	printf("%d\n", 010); // 010 is octal integer 
	                     // 1*8 + 0 * 8 = 8
	printf("%d\n", 010); // 010 is octal integer 

	printf("%d\n", 0x10); // 0x10 is hex integer 
						 //  1 * 16 + 0 * 16 = 16

	printf("%ld\n", 10l);

	printf("%x\n", 16);
	printf("%x\n", 15); // x is hex format of a integer value

	printf("Octal: %o\n", 8);
	// printf("Octal %o\n", 080); be careful the error

	printf("%d\n", 15u);

	printf("g: %g\n", 3.14111111);
	printf("e: %10g\n", 3.14111111);
	printf("e: %10.10g\n", 3.14111111);
}

	// 1000,0000 -0 
	// 1111,1111 1'
 //   10000,0000 2'


/**
 * @brief 2's com form turns substraction into addition for cpu
 * @details [long description]
 */
void demo4(){

	// char c = -2; // without 2's   1000, 0010
	// 						//	  1111, 1101 1' 	

	// bin_char((unsigned) c);// 	  1111, 1110 2'

	// unsigned int a = 1000;
	// signed int b = -1;

	//  1111, 1111 1111, 1111 1111, 1111 1111, 1111 
	// implicit typecast convert signed integer into
	// unsigned integer, 
	// 
	// the reason implicit typecast will convert signed
	// to unsigned it because the unsigned has one more
	// value bit, one more value bit mean one more precision
	// but this oftens cause error when underflow and overflow 
	// happens
	//
	// if (a > b) 
	// printf("a is more than b\n");
	// else
	// printf("a is less or equal than b\n");

	// if ((signed) a >  b) 
	// printf("a is more than b\n");
	// else
	// printf("a is less or equal than b\n");

	// printf("%u\n", b);


	float n = 0.1;
	double a = 0.1;
	float epsilon_f = 1.0/pow(10.0,(double) FLT_DIG);
	double epsilon_d = 1.0/pow(10.0,(double) DBL_DIG);

	// // printf("float as double n: %g\n", n);


	// if (n == 0.1)
	// 	printf("it’s all right\n");
	// else
	// 	printf("Wierd\n");
	// if (a + a + a + a + a + a + a + a + a + a == 1.0)
	// printf("10 * 0.1 is indeed 1.0. \n");
	// else
	// printf("Wierd, This is not guaranteed in the general c\n");

	

	// if ( fabs(n - 0.1) < epsilon_f)
	// 	printf("it’s all right\n");
	// else
	// 	printf("Wierd\n");
	// if (fabs(a + a + a + a + a + a + a + a + a + a -1.0)
	// < epsilon_d)
	// 	printf("10 * 0.1 is indeed 1.0. \n");
	// else
	// 	printf("Wierd, This is not guaranteed in the general
	// 	case.\n");

}

void demo44(){
	float epsilon_f = 1.0/pow(10.0,(double) FLT_DIG);
    double epsilon_d = 1.0/pow(10.0,(double) DBL_DIG);

    printf("epsilon_f: %1.56f\n", epsilon_f);
    printf("epsilon_d: %1.56f\n", epsilon_d);
    float n=0.1;
    double a = 0.1;

    if ( fabs(n -0.1) < epsilon_f) 
        printf("it's all right\n");
    else 
        printf("Wierd\n");

    if (fabs(a + a + a + a + a + a + a + a + a + a -1.0)<epsilon_d) 
        printf("10 * 0.1 is indeed 1.0. \n");
    else 
        printf("Wierd, This is not guaranteed in the general case.\n");
}


// this dangerous for not pass the length of the array for parameter
// void printL(int arr[]){
// 	printf("size of int arr of: %lu\n", sizeof(arr));

// }


void demo5(){
	int arr[3];

	for (int i = 0; i < 3; ++i)
	{
		printf("%d\n", arr[i]);	/* code */
	}

	printf("%d\n", arr[10]);// pass the compling but, dangerous
							// we have to be careful

	int a=0;
	printf("%d\n", a=6);

	printf("size of int arr of length 3: %lu\n", sizeof(arr));
	printf("length of int arr: %lu\n", sizeof(arr)/sizeof(int));
	// this can only be performed with its own function domain
	// when the array passed into another funtion the length and size
	// information is lost

	// printL(arr);

}


int main(int argc, char const *argv[])
{
	
	demo5();



	return 0;
}
/* 
* Author : Haoyu Wang
* Description:
*	
*/

#include "pointer.h"



// pointer as reference to primitive data types
void eg1()
{

	char c = 'A'; int a = 'A'; float f = 1.0f;	
	char *cp = &c; int*ap = &a; float *fp = &f;

}



void eg2()
{

	int a[] = {1,2,3};// 3* 4 12 bytes
	char s[] = "Hello, this is a snippet.";

	char s1[] = {'A', 'B', 'C'};// 4 bytes

	//how many memory allocated for s1


	char *sp = "Hello, this is a snippet.";

	printf("%p\n", a);
	printf("%p\n", s1);
	printf("%p\n", s);


	char *sp1 = malloc(10);


	printf("%p\n", sp);

	// sp[1] = 'c';

	printf("%p\n",sp1 );


}


// const key word 
// 

void eg3()
{
	const int a=1;
	int const b=2;

	// a = 2;
/*
		3, for pointer variable the const keyword acts in three ways:
	
	*/

	//1. const pointer vaiable

	int c=-1, d=-2;

	int * const pc=&c;
	// pa =&d;
	*pc = 2;
	printf("c%d\n", c);

	//2 const pointer variable reference

	int const *p = &d;//*p is immutable
	// *p = 2;// wrong
	d = 2;
	printf("*p%d\n", *p);

	// *p = a;// wrong


	// const pointer variable and its reference

	int const * const pa=&d;

	// pa = //wrong
	// *pa = //wrong

	// pa is immutable and *pa is also immutable


	// peculiar example

	// int *pp = &a;
	// *pp= -2;
	// printf("a%d\n", a);




}





// Pointer arithmetic
void eg4()
{

	int a, *pa;
	pa = &a;

	// pa = pa + 1;
	//1. this will points to the next sizeof(datatype)-th address and get this data type
	// vaule of the sizeof(datatype) bytes.
	//2. the next value has to be legal for using to avoid crashing the program

	printf("%p\n",pa);
	printf("%p\n",pa+1);

	// 4 bytes

	// what is the difference of this two address value


	long b;
	long *pb = &b;

	printf("\n%p\n",pb);
	printf("%p\n",pb+1);

	//(ox) b0 - a8 = b*16-a*16 - 8 = 16 - 8 =8

	char c;
	char *pc = &c;

	printf("\n%p\n",pc);
	printf("%p\n",pc+1);
	// 1 bytes

}




// Array pointers


void eg5()
{
	int *p[3];

/*	
	1. 	According to precedence table, which operation goes first 
		starting from the variable name?
		[] comes first that *
		so p is first an array and then pointers



	2.	How to read this declaration? 
		
		So p is an array of 3 pointers

	3.	How much memory will be owned to the variable p
		
		3 * sizeof(int *)  = 3 * 8 = 24	
	

	4. 	How to legally initialize this variable

*/ 

	int a[3] = {1,2,3};

	*p = a;// the address of a
	// *p <==> p[0] p[1] p[2]

	p[1] = &a[1];
	p[2] = a+2;

	*(p+1) = &a[1];

	printf("%d\n", **(p+2));

}



//Pointer to arrays

void eg6()
{

	int (*p)[3];
	/*	
	1. 	According to precedence table, which operation goes first 
		starting from the variable name?
		() comes first that []
		so p is first an pointere and then array



	2.	How to read this declaration? 
		
		So p is a pointer to an array of 3 int

	3.	How much memory will be owned to the variable p
		
		3 * sizeof(int )  = 3 * 4 = 12	
	

	4. 	How to legally initialize this variable

*/ 

	int a[2][3] ={
		{ 1,2,3},
		{ 4,5,6}
	};
// <==> (*a)[3]

	 

	p = a;
	printf("%p\n",p );
	printf("%p\n",p+1);
	//68 - 5c  = 16 + 8 - 12 =  12  3*sizeof(int) = 12 bytes

	printf("%d\n", (*p)[1]);

	printf("%d\n", (*(p+1))[2] );// 4


}

// The highest dimension does not matter for data type compatability
// the rest of dimension has to be the same (the bounds have to be clear)
void helper(int (*a)[2][3])
{
	printf("%d\n", a[0][0][0]);
}


void eg7()
{

	int a[2][2][3] = {
		{{ 1,2,3},
		{ 4,5,6}},
		{{ 1,2,3},
		{ 4,5,6}}
	};

	helper(a);


}







void testingPointer(){

	eg7();
}
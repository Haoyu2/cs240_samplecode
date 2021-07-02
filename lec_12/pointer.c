/* 
* Author : Haoyu Wang
* Description:
*	
*/

#include "pointer.h"
#include <stdlib.h>
#include <string.h>


//How to return an array

// 1. we can not use int/char [] as return type syntactically rules

	// array will take stack memory 
	// then the array can be over-written when this function stack exits and
	// another function stack executes
	
// 1.1,  this is the another reason that c doesnot return array
        // this is also the motivation for heap memory management
// 

// Summary. we should not return an array
// Solutuion:
	//  1. Manipulate array in place
	//  2. Use heap memory for return an array
//
// for passing an array into a local function, wehave to use a seperate
// variable for its length
void printArray(int arr[], int len){
	for (int i = 0; i < len; ++i)
	{
		printf("%d\t", arr[i]);
	}
	printf("\n");
}


// 
// int [] eg01(int len){

// 	int a[len] = {1,2};
// 	return a;
// }


int * eg02(int len){


	// array will take stack memory 
	// then the array can be over-written when this function stack exits and
	// another function stack executes
	// the reason
	int a[len];
	a[0] = 1;
	a[1] = 2;
	a[2] = 3;
	int* ap = a;
	return ap;
	//return a;// we can not return an array, returns address of local variable
}
// this is the correct way to return an newly created array

int * eg03(int len){

	// this the heap memory
	// int * a = (int *) malloc(4*len);
	int * a = (int *) calloc(len, 4);
	// number of objects and the size of each object

	a[0] = 1;
	a[1] = 2;
	a[2] = 100;
	int* ap = a;

	printf("local a:\t\t%p\n", a);
	return a;
}



void helper_eg0(){
	int a[100];
	for (int i = 0; i < 100; ++i)
	{
		a[i] = -1;
	}
}

void eg01_test(){
	int len = 3;
	// eg01(len);
	// printArray(eg01(len), len);

	int* pa = eg02(len);
	printArray(pa, len); // this works but 
	helper_eg0();
	printArray(pa, len); // this works but 
	

}

void eg03_test(){
	int len = 3;
	// eg01(len);
	// printArray(eg01(len), len);

	int* pa = eg03(len);
	printArray(pa, len); // this works but 
	helper_eg0();
	printArray(pa, len); // this works but 
	printf("calling stack pa:\t%p\n", pa);


	free(pa); 
	// pa retain the address, however it is not legal safe anymore
	// the memory it owned now avaiable for other functions or programs
	printf("After free:\t%p\n", pa);

	printf("1%d", pa[0]);
	printArray(pa, len); 
	

}




void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void swap_test(){
	int a=1, b=2;
	printf("a:%d, b:%d\n", a, b);
	swap(&a, &b);
	printf("a:%d, b:%d\n", a, b);
}


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

	printf("len of s:%lu\t memory of s:%lu\n", strlen(s),sizeof(s));



	// char s1[] = {'A', 'B', 'C'};// 3 bytes and there is no '\0' and dangerous

	char s2[] = {'A', 'B', 'C', '\0'};
	char *p1 = malloc(strlen(s2) + 1); 

	// printf("%s\n", s1);

	printf("%s\n", s2);


	printf("%s\n", strcpy(p1, s2));


	// //how many memory allocated for s1



	char *sp = malloc(100);
	// heap being allocated to sp with 100 bytes
	// then sp gets updated to point to a const string pointer 
	// which is in the data segment

	// once you are trying update a heap pointer and the heap memory
	// is no longer used, we should free that memory before 
	// changing and updating the heap pointer. 

	// char *sp1 = sp;

	printf("stack address:\t%p\n", a);
	printf("heap address:\t%p\n", sp);
	free(sp);

	// will this string initial the sp memory
	sp = "Hello, this is a snippet.";
	// a constant string a const char pointer

	printf("data segment address:%p\n", sp);

	// sp[1] = 'M'; // this is updating a const string, will casuse crash



}

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

	// 1. const pointer vaiable

	int c=-1, d=-2;

	int * const pc=&c;

	// pc = &d;// verify if the pointer is const
	*pc = 2;// verify if the value is const
	printf("c:%d\n", c);

	//2  const values 

	int const *p = &d;//*p is immutable
	// *p = 2;// wrong
	// *p = a;// wrong
	d = 2;
	printf("*p:%d\n", *p);




	// 3 const pointer variable and its reference

	int const * const pa=&d;

	// pa = //wrong
	// *pa = //wrong

	// pa is immutable and *pa is also immutable


	// peculiar example

	// const int x = 10;

	// int *px = &x;
	// *px= -2;
	// // x = 11;// this is not working
	// printf("x: %d\n", x);

	// const int arr[] = {1,2,3}; 
	// const int arr1[] = {4,5,6};

	// const int * p_arr = arr;
	// p_arr = arr1;
	// // arr[1] = 2;
	// for (int i = 0; i < 3; ++i)
	// {
	// 	printf("%d\t", arr[i]);
	// }

	// for (int i = 0; i < 3; ++i)
	// {
	// 	printf("%d\t", p_arr[i]);
	// }


	// int * p_arr_mutablable = arr;
	// p_arr_mutablable[1] = 10;

	// printf("\n");
	// for (int i = 0; i < 3; ++i)
	// {
	// 	printf("%d\t", arr[i]);
	// }



	char ss1[20], ss2[] = "That great!";

	printf("ss1:%s\n", strncpy(ss1, ss2, 4)); 

	printf("ss1:%s\n", ss1); 
	printf("ss1+ss2:%s\n", strcat(ss1, ss2)); 





	// sss is asked for store a copy of concatenation of s1 s2
	//
	char *sss = calloc(sizeof(ss1) +sizeof(ss2), 1);



	printf("sss:%s\n", sss); 


	// cannot use when ss1 and ss2 is define in the argument
	// char *sss = malloc(strlen(ss1) + strlen(ss2) + 2);
	// this is safe statement but be careful about the null char

	strcat(sss, ss1);
	printf("sss:%s\n", strcat(sss, ss2));

	// sss is copy of the contenation of ss1 and ss2

	printf("ss2 starting with g:%s\n", strchr(ss2, 'g'));

	printf("%ld\n", strchr(ss2, 'g') - ss2);


	printf("\n=========\n");
	// s1 = "aaa"; res = "s"; delete all duplicates of letters
	// res = malloc(strlen(s1))
	// res1 = malloc(strlen(res))
	// free(res) return res1

	char *s1 = malloc(4);
	// s1 = "aaa"; // this wrong for string copy this rereference
	memcpy(s1, "aaa", 4);
	strcpy(s1, "aaa");

	printf("%s\n", s1);

	char *res = malloc(strlen(s1)+1);

	strcpy(res, "a");
	printf("%s\n", res);

	// realloc K&R stardard uses new memory, newer version 
	// uses the same meory, 
	printf("before realloc:%p\n", res);
	res = realloc(res, 2);
	printf("after: %p\n", res);


	//  "abc" 
	//   "c":  "abc"
	//   "b":   "ab"   

	printf("%lu\n", strspn("abc", "c"));
	printf("%lu\n", strspn("abc", "ab"));
	printf("%lu\n", strspn("abc", "d"));

// 
	printf("\n%lu\n", strcspn("abc", "c"));
	printf("%lu\n", strcspn("abc", "ab"));
	printf("%lu\n", strcspn("abc", "d"));

	printf("\n%s\n", strpbrk("abc", "c"));
	printf("%s\n", strpbrk("abc", "ab"));
	// printf("%s\n", strpbrk("abc", "d"));
	// for no occurences happens null pointer gets returned


	printf("%p\n", NULL);

	printf("%d\n", NULL == strpbrk("abc", "d"));

	printf("%lu\n",strlen(s1));

//      "abc, cba"

	// char *each;
	// char text[] = "abc, def, hijk";

	// char * text_copy = malloc(strlen(text) + 1);

	// strcpy(text_copy, text);


	// printf("%s\n",text);

	// // each=strtok(text, ",") ;


	// while ((text_copy=strtok(text_copy, ",")) != NULL)
	// 	printf("%s\n", text_copy);


	char arr1[4];
	memset(arr1, 1, 4);
	for (int i = 0; i < 4; ++i)
	 {
		printf("%d\t",arr1[i]);

	 } 

 	int arr2[4];
	memset(arr2, 1, 4*4);
	for (int i = 0; i < 4; ++i)
	 {
		getBinary(arr2[i]);
		printf("%d\t",arr2[i]);

	 } 


	 printf("\n%g\n", atof("-12.1"));
 	 printf("\n%d\n", atoi("ab-1a2b"));

}




void demo_strtok()
{
	char *each;
	char text[] = "abc, def, hijk";

	char * text_copy = malloc(strlen(text) + 1);

	strcpy(text_copy, text);
	// printf("%s\n", text_copy);


	printf("%s\n",text);

	each=strtok(text, ", ") ;
	printf("%s\n", each);


	while ((each=strtok(NULL, ", ")) != NULL)
		printf("%s\n", each);


	printf("%s\n",text); // original string gets modified

	// each=strtok("abc, def, hijk", ",") ;

	// printf("%s\n", text_copy);

	// while ((each=strtok(NULL, ",")) != NULL)
	// 	printf("%s\n", each);'

	printf("%x", -5);

}

// count how many lowercase letters for a string

// int arr[26]; 'a' : arr[0], 'b': arr[1],...,  

// 'a' : 'a'-'a'  (0)
// 'b' : 'b' - 'a' (1)





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

	//(ox) b0 - a8 = b*16-a*16 - 8 = 16 - 8 = 8

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

	demo_strtok();

	// eg3();
	// swap_test();
	// eg01_test();
	// eg03_test();
	// printf("Hello!\n");
	// eg7();
}
/* 
* Author : 
* Student Number:
* Description:
*	
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdarg.h>


/*
	Total time: 125 minutes. The 5 minutes are for wrapping up and submission.

	Way of submission:

	1.  Please submit all your files in a zip file named test2_[fullname] to the email address of cs240.umb@gmail.com.
		Note: only submit this source code.
	2.  The subject of the email should be test2_summer2020.


*/








// Q1
/*

A.   Write out each of their Postfix format. (10 Points)

    A.1	char (*(*(*ok)(int))[5])();

    A.2	float *(*(*right)())(int);

Your Answer:

	ok * (int) * [5] * () char
	right * () * (int) * float


B.	In the function q1B, please correctly initialize a1 and a2 using existing varibles.
	And explain what data types of these two variables. (10 Points)



Your Answer:

*/


void q1B(void)
{
	int i;//This is definition without ini
	int j = 1;// definition with init


	// float *(*(*right)())(int);
	// double *p =  right; // This init wrong, because data type of 
				// both sides are not compatable

	int a[2][3], b=1,c=2,d=3;




	int arr[] = {1,2,30};
	// int *a1[3] = {&b,&c,&d};
	int *a1[3] = {a[0],a[0]+1, a[0]+2};
	// Data Type of a1: a1 is array of 3 pointers to integer
	int (*a2)[3] = a+1;

	// Data Type of a2:  a2 is pointer to array of 3 integers
}





// Q2
/*

A.  Writing macros with arguments (10 Points)
	
	A.1	Define a macro to get the minimum value of two arguments.

	Your Answer:	

		#define MIN(X, Y) (X) < (Y) ? X : Y 
	
	A.2	Define a macro to get the cubic of one arguments
	Your Answer:	
		
		#define CUBIC(X) (X)*(X)*(X)

		CUBIC(1+1)  without paren 1+1 * 1 + 1　* 1 + 1　　


B. 	Given a constant string  parameter, the following function copy it into a newly 
	allocated memory and strips all non-alpha characters of it and returns it. (10 Points)
	
	For example,

	For s: "   That's  cool1!"

	"Thatscool" will be returned. 

*/

//  Q2.B

char* getAlpha(char const *s)
{
	int len = strlen(s);
	char *s1 = calloc(len, sizeof(char));
	// calloc will initialize very byte to be zero
	// such that we do not need to put a '\0'  at the end
	// 
	for (int i=0, j=0; i < len; ++i)
		if (isalpha(s[i])) s1[j++] = s[i];
	return s1;
}



// Q3 


typedef struct array
{
	int *a, len;
} Array;

typedef struct mat
{
	int **mat, rows, cols;
} Matrix;

// A. Complete these functions below (20 Points)

// This function takes an positive integer and created an Array variable with 
//  member of [len] equal that integer number and [a] points a dynamic allocated integer
// array of that length.  For each entry initialized to be zero

Array newArray(int len)
{
	Array arr = {NULL, len};
	arr.a = calloc(len, sizeof(int));
	return arr;
}

/*
	arr, itself has address vaule stack value
	arr members:
		(int *)	a: itself has address value   stack value
				   it holds a pointer value  integer  heap value
				len: itself has a stack address vaule
					it holds integer value in the stack 

	In a caller function:

		Array arr = newArray(3);

	In the caller function stack
		arr{
			a; // inited by value returned from newArray
			len; // inited by value returned from newArray




		}

	Array* newArrayP(int len)
	{
		Array *arr = malloc(sizeof(Array));
		arr members:
		(int *)	a: itself has address value   heap value
				   it holds a pointer value  integer  heap value
				len: itself has a stack address vaule
					it holds integer value in the heap 


				arr->a = calloc(len, sizeof(int));
				arr->len =
		return arr;
	}


*/


// Free the memory that are dynamically allocated
void deleteArray(Array arr)
{
	free(arr.a);
}


/*

	void deleteArrayP(Array * arr)
	{
		free(arr.a);
		free(arr);

	}

*/



// This function takes two positive integers and created an Matrix variable with 
//  that many rows and cols. The [mat] should points to dynamiclly allocated memory
//  For each entry initialized to be zero
Matrix newMatrix(int rows, int cols)
{
	Matrix mat = {NULL, rows, cols};
	mat.mat = (int**) malloc(rows*sizeof(int **));
	for (int i = 0; i < rows; ++i)
		mat.mat[i] = calloc(cols, sizeof(int));		
	return mat;
}



// Free the memory that are dynamically allocated
void deleteMatrix(Matrix mat)
{
	for (int i = 0; i < mat.rows; ++i)
		free(mat.mat[i]);
	free(mat.mat);
}





// Q4. Comparator Function


// A. Write a comparator Function compare two references of Array variables by their length
// of acsending order. (10 Points)
//
// Generrally, return -1 if less than
//			   return 0  if equal
// 			   return 1 if more than


int com_Array(const void *a, const void *b)
{
	return (((Array *)a)->len - ((Array *)b)->len );
}



/*
typedef enum {ONE_D=1,TWO_D} DIMENSION;

Complete the variadic function return a void reference to an Array or a Matrix.  

For the [dim]:

•If it is ONE_D, return an Array void reference, and the second argument is its length.
•If it is TWO_D, return a Matrix void reference, and the second and third arguments are 
 its number of rows and columns.

*/

typedef enum {ONE_D=1,TWO_D} DIMENSION;

void *q4(DIMENSION dim, ...) 
{
	va_list ap;va_start(ap,dim);// definition and init of pointer ap

	void *p;
	if ( dim==ONE_D)
	{
		int len = va_arg(ap,int); // parse values
		p = malloc(sizeof(Array)); // definition
		Array arr = newArray(len);
		memcpy(p,&arr, sizeof(Array)); // initializion 

		// or we can do p.a =... , p.len = len

		// But you can not return &arr
		// Beause arr is in stack
		// the vaule p holds is in heap
				
	}
	if (dim==TWO_D)
	{
		int rows = va_arg(ap, int);
		int cols = va_arg(ap, int);
		p = malloc(sizeof(Matrix));
		Matrix mat = newMatrix(rows,cols);
		memcpy(p, &mat, sizeof(Matrix));
	}

	return p;
}









// Q5 (20 Points)


typedef struct strings
{
	char **s;
	int n;
} SubStrings;



// Complete the function below such that a string s will be seperated into n substrings
// by the chararcter c and stored in a SubStrings variable
/*
For example,

s: "That looks nice",  c:' '

Then a SubStrings variables will be returned such that:

SubStrings vairable{
	s: {"That", "looks","nice"};	
	n: 3
}

*/




//s1:      That'\0'looks'\0'nice'\0';
// str.s[0] 


SubStrings split(const char*s, char c)
{

	SubStrings str = {NULL, 0};
	int len=strlen(s), out=1;
	char * s1 = malloc(len);
	strcpy(s1,s);
	len = 0;
	while(s1[len]!=0)
	{

		// if the current char is demilter we make it to be null char

		// testing the beginning of a new substring
		if(out && s1[len]!=c)
		{
			str.n++;
			str.s = realloc(str.s, str.n*sizeof(char*));
			str.s[str.n-1] = s1 + len;
			out = 0;
		}

		// the demiliter

		if (s1[len]==c)
		{
			out = 1;
			s1[len]=0;
		}
		len++;
	}

	return str;

}



void test2()
{
	char *s  = "   That's  cool1!";
	printf("%s\n", getAlpha(s));
}

void test3()
{	
	int len = 3, rows = 3, cols = 4;
	Array arr = newArray(len);
	for (int i = 0; i < arr.len; ++i)
		printf("%d\t", arr.a[i]);
	deleteArray(arr);
	printf("\n");

	Matrix mat = newMatrix(rows,cols);
	for (int i = 0; i < mat.rows; ++i)
	{
		for(int j = 0; j < mat.cols;j++)
			printf("%d\t",mat.mat[i][j]);
		printf("\n");
	}
	deleteMatrix(mat);
	

}


void test4()
{
	Array arr1 = newArray(4);
	Array arr2 = newArray(3);
	if (com_Array(&arr1,&arr2))
		printf("arr1 is longer than arr2\n");


	Array *arr = q4(1, 4);
	for (int i = 0; i < arr->len; ++i)
		printf("%d\t", arr->a[i]);
	deleteArray(*arr);
	free(arr);
	printf("\n");


	Matrix *mat = q4(2,4,3);
	for (int i = 0; i < mat->rows; ++i)
	{
		for(int j = 0; j < mat->cols;j++)
			printf("%d\t",mat->mat[i][j]);
		printf("\n");
	}
	deleteMatrix(*mat);
	free(mat);
}


void test5(char *s, char c)
{

	SubStrings str = split(s, c);
	for (int i = 0; i < str.n; ++i)
	{
		printf("%s\t", str.s[i]);
	}

	printf("\n");

}


int main(int argc, char *argv[])
{

	// test2();
	// test3();
	// test4();
	
	char *s = "That looks nice";
	test5(s,' ');

	test5(",123,,,,,,,4,,56,789", ',');


	return 0;
}
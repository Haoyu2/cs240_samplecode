#include "func_pointer.h"
#include <string.h>
#include <stdlib.h>



void demo_misuse_heap()
{
	int len = 4;
	int *arr = malloc(sizeof(int) * len);

/*
	1. misusage
	wrong because the arr has been updated for calling free
*/
	// arr[0] = 1;
	// arr[1] = 2;
	// arr++;
	// printf("arr[0]:%d\n", arr[0]);
	// free(arr);
/*

*/

	//  this is the correct way, but generally it is better to use index
	int *p_arr = arr;
	p_arr++;

	printf("* parr:%d\n", *p_arr);
	free(arr);

	/*
		2. misuage
		free twice of the same pointer
	*/

	// free(arr);




}



int fadd(int a, int b)
{
	return a+b;
}

int fmul(int a, int b)
{

	return a*b;

}


void f_eg2()
{

	int (*func)(int, int);

	func = fadd;

	printf("%d\n", func(1,2));


	func = fmul;

	printf("%d\n", func(1,2));

}



// array of function pointers

void f_eg3()
{

	// sytax for creating array of function pointers
	int (*func[2])(int, int);


	func[0] = fadd;
	func[1] = fmul;

	printf("%d\n", func[0](1,2));
	printf("%d\n", func[1](1,2));


}



/* void qsort(void *base, size_t n, size_t size, 
			int (*cmp) (const void *, const void *))

	qsort sorts into ascendingorder an array base [0 ]...base [n-1] of objectsof size
	size. The comparison function cmp is as in bsearch.

	Note,
	1, the size indicates the data type
	2, the n representes how many items of this data type that the base points to
	3, the cmp will compare the reference of each item in base
*/



// Write a comparator for integers

/*
	1. more than  return positive   1
	2. equal      return 0
	3. less than  return negative  -1

*/

int cmpInt(const void *a, const void *b)
{
	// int *a1 = (int *) a;
	// int *b1 = (int *) b;

	// return *a1 - *b1;

	return *(int *)a - * (int *) b;
}

int cmpInt_reverse(const void *a, const void *b)
{
	// int *a1 = (int *) a;
	// int *b1 = (int *) b;

	// return *a1 - *b1;

	return *(int *) b - * (int *) a;
}


void demo_cmpInt()
{
	int a=3, b = 2;
	// printf("%d", cmpInt(3, 2));// wrong, constant literal has no memery address

	 printf("%d", cmpInt(&a, &b));
}


void printIntArray(int *arr, int len)
{
	for (int i = 0; i < len; ++i)
	{
		printf("%d\t", arr[i]);		
	}
	printf("\n");
}

void demo_qsort_int(){

	int arr[] = {5,3,2,1,-1, 10};

	qsort(arr, 6, sizeof(int), cmpInt);
	printIntArray(arr, 6);

	qsort(arr, 6, sizeof(int), cmpInt_reverse);
	printIntArray(arr, 6);

}


// The comparator have to recive the references of the items to 
// be compared
// So for a char pointer (string), the reference is going to be
// a pointer to a char pointer
// char ** s
// based on the interpretation rule of complicated pointer decleration
// s is pointer to a pointer points to a char(char pointer) 
int cmpStringRef(const void *s1, const void *s2)
{	

	// printf("%d\n", strcmp(s1, s2));
	return strcmp( *(char**) s1,  *(char**) s2);

}


int cmpString(const void *s1, const void *s2)
{
	// printf("%d\n", strcmp(s1, s2));
	return strcmp(s1, s2);

}

void printStringArray(char **arr, int len)
{
	for (int i = 0; i < len; ++i)
	{
		printf("%s\t", arr[i]);		
	}
	printf("\n");
}
void demo_string_cmp()
{

	char s1[] = "ABC", s2[] = "abc";

	printf("%d\n", cmpString(s1, s2));


	// should not use 2d char array
	char *strings[] = {
		"c", "b", "a" 
	};

	// printf("=====%d\t", cmpString(strings[1], strings[0]));

	printStringArray(strings, 3);

	qsort(strings,3, sizeof(char *), cmpString);

	printStringArray(strings, 3);

	qsort(strings,3, sizeof(char *), cmpStringRef);
	printStringArray(strings, 3);

}

// void pointer data size doesnot know, cannot get the next ith item correctly
int getMax(void *base, int n, int size, int (*cmp) (const void *, const void *))
{

		// printArray((int *) base,n);

	if (n == 0) return -1;
	int max_index = 0;
	for (int i = 1; i < n; ++i)
	{
		// if (cmp( &base[max_index],&base[i] ) < 0) max_index = i; 
		if (cmp( base + max_index*size, base + i * size) < 0) max_index = i; 
			printf("max_index:%d\n", cmp( base + max_index*size, base + i * size));

	}

	return max_index;
}



void demo_getMax()
{
	int arr[] = {1,2,3};
	printf("max_index:%d\n", getMax(arr, 3, sizeof(int), cmpInt));
}



//
// int getMax(void *base, int n, int size, int (*cmp) (const void *, const void *))
// {

// 		// printArray((int *) base,n);


// 	int max_index = 0;
// 	for (int i = 0; i < n; i++)
// 	{
// 		//  base + i , base + max
// 		if (cmp(base + i*size,base + max_index*size) > 0) 
// 		// if (cmp(&base[i],&base[max]) > 0) 
// 			max_index = i;
// 	}

// 	return max_index;
// }



void f_eg4()
{

	int a = -1 , b = 1;
	printf("%d\n", cmpInt(&a, &b));

	int arr[] = {8,1,3,4,5,6,7};
	qsort(arr, 7, sizeof(int), cmpInt);

	// printArray(arr,7);

	// char *s[] = {
	// 	 "BC", "XY", "MP", "AB"
	// };

	// // printf("%d\n", strcmp(s[0], s[1]));

	// qsort(s, 4, sizeof(char *), cmpString);

	// printSS(s,4);

	int max = getMax(arr, 7, sizeof(int), cmpInt);
	printf("%d\n", arr[max]);

}


typedef struct Point{int x, y;} Point;

Point* makePoint(int x, int y) 
{
	// Point tmp;
	// Point* point = &tmp;  wrong

	Point * point = malloc(sizeof(Point));
	point->x = x;
	point->y = y;

	return point;
}
//avoid this style in K&R
Point makePoint1(int x, int y) {
	Point point = {x, y};
	return point;
}


void demo_makePoint()
{
	Point *point = makePoint(10, 10);
	printf("x:%d\ty:%d\n", point->x, point->y);
	printf("x:%d\ty:%d\n", point[0].x, point[0].y);


	Point point1 = makePoint1(20, 20);
	printf("x:%d\ty:%d\n", point1.x, point1.y);	


	Point points[] = {{1,1},{2,2}};


	printf("x:%d\ty:%d\n", points[1].x, points[0].y);	


	Point points1[] = {1,1,2,2};
	printf("x:%d\ty:%d\n", points1[1].x, points1[0].y);	

	typedef enum color{ RED, GREEN=200, BLUE } Color;

	printf("%d\t", RED);
	printf("%d\t", GREEN);
	printf("%d\t", BLUE);

	Color color1 = RED;

	printf("%d\t", color1);
	color1 = -1;
	printf("%d\t", color1);
}



void f_eg5()
{

	struct Point{int x, y;};

	struct Point point1 = {1,1};
	point1.x = 2;


	printf("%d\n", point1.x);
	printf("%d\n", point1.y);

	// Point point2;// wrong

	typedef struct Point Point;

	Point point2 = {-1,-1};



	typedef struct Student {char* name; int grades;} Student;

	Student mike = {"Mike", 1000};


	printf("%s\n", mike.name);
	printf("%d\n", mike.grades);

	typedef struct Mixed {
		struct Student student;
		Point point;
	} Mixed;

	Mixed mix = {{"Josh", 2000}, {1,1}};

	printf("%s\n", mix.student.name);
	printf("%d\n", mix.point.x);



	Point * pointer_point1 = &point1;

	printf("Pointer to structure:%d\n", (*pointer_point1).x);

	// printf("Pointer to structure:%d\n", *pointer_point1.x);// wrong

	printf("Pointer to structure:%d\n", pointer_point1->x);




	// printf("%d\n", point1 == point2);//sytactically wrong

	// printf("%d\n", mix.point.x);


	// Point p2 = {2,3,"world"};

	// printf("%s\n", p2.s);

	// p2.s = "Ok";
	// printf("%s\n", p2.s);



	// Point *pp = &p2;

	// printf("%s\n", (*pp).s);
	// printf("%s\n", pp->s);


}



// Point padd(Point p1)
// {

// 	p1.x = p1.x+p1.y;
// 	return p1;
// }

// void f_eg6()
// {


// 	Point p1 = {1,2};

// 	Point p2 = padd(p1);

// 	printf("%d\t%d\n",p1.x, p2.x);
// }







void testFP()
{

	// // float (*ptr[5])(int);

	// // float *(ptr1[5])(int); // wrong array of functions is wrong
	// // float (*ptr)[5](int);// wrong
	// // ptr * [5] (int)


	// float * (*f1[5])(int* (*f)(int, int), float);
	// // f1 [5] * (int* (*f)(int, int), float) * float



	// f_eg3();
	// demo_cmpInt();

	// demo_qsort_int();
	// demo_string_cmp();
	// demo_getMax();

	// f_eg5();
	demo_makePoint();
	// printf("Hello, this is a snippet.\n");

	// demo_misuse_heap();
}
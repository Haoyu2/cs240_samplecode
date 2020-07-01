/* 
* Author : Haoyu Wang
* Description:
*	
*/

#include "Array.h"


Array newArray(int capacity)
{
	Array arr;
	arr.capacity = capacity;
	arr.size = 0;
	arr.a = calloc( capacity, sizeof(int));
	arr.put = put;
	arr.remove = removeA;
	return arr;
}


//pass by value is not convient

// the value of arr.a and arr.size ..

Array put1(Array arr, int a)
{

	if(arr.size+1==arr.capacity){

		arr.capacity = 2*arr.capacity;
		arr.a = realloc(arr.a, arr.capacity*sizeof(int));
	}

	arr.a[arr.size++] = a;
	return arr;

}



// a reference data type is more efficient
// it will modiy the original data
// there is no local copy of that data created and destroyed
void put(Array *arr, int a)
{

	if(arr->size+1==arr->capacity){

		arr->capacity = 2*arr->capacity;
		arr->a = realloc(arr->a, arr->capacity*sizeof(int));
	}

	arr->a[arr->size++] = a;


}


int removeA(Array *arr)
{
	int i =  arr->a[arr->size];
	arr->size--;
	if(arr->size < arr->capacity/2){
		arr->capacity = arr->capacity/2;
		arr->a = realloc(arr->a, arr->capacity*sizeof(int));
	}
	return i;
}




void pArray(Array arr)
{

	for (int i = 0; i < arr.size; ++i)
	{
		printf("%d\t", arr.a[i]);
	}
	printf("\n");
}




ArrayG newArrayG(int capacity, int size)
{
	ArrayG arr;
	arr.capacity = capacity;
	arr.size = size;
	arr.size_n = 0;
	arr.a = calloc(capacity, size);
	return arr;
}


// for a struter pointer use arrow sign to get the member

void putG(ArrayG *arr, void *item)
{




	if(arr->size_n==arr->capacity){

		arr->capacity = 2*arr->capacity;
		arr->a = realloc(arr->a, arr->capacity* arr->size);
	}

	// printf("item value: %f\n", *(double*) item);

	int dis = (arr->size_n)*arr->size;

	// arr->a[arr->size++] = a;
	memcpy(arr->a+dis, item, arr->size);
	// printf("Copied %f\n", * (double *) (arr->a+dis) );
	arr->size_n++;

}




void testAGInteger()
{
	ArrayG arr = newArrayG(3, sizeof(int));

	for(int i=0;i<3;i++)
	{
		printf("%d\n",  * (int*) (arr.a+i));
	}

	printf("\n");

	int a[] = {-1,2,3};
	for(int i=0;i<3;i++)
	{	

		putG(&arr, (void*) (a+i));
	}

	for(int i=0;i<3;i++)
	{
		printf("%d\n",  * (int*) (arr.a+i*sizeof(int)));
	}


}



void testAGDOUBLE()
{


	ArrayG arr = newArrayG(3, sizeof(double));

	for(int i=0;i<3;i++)
	{
		printf("%f\n",  * (double*) (arr.a+i));
	}

	printf("\n");

	double aa[] = {-1.0,2.0,3.0};
	for(int i=0;i<3;i++)
	{	

		putG(&arr, (void*) (aa+i));
	}

	for(int i=0;i<3;i++)
	{
		printf("%f\n",  * (double*) (arr.a+i*sizeof(double)));
	}




}


void testAGStuct()
{

	typedef struct student
	{	
		char *name;
		char *id;
		double grades;
	} Student;


	Student students[] = {
		{ "Mike", "001", 90},
		{ "Josh", "002", 91},
		{ "John", "003", 92},
	};


	ArrayG arr = newArrayG(3, sizeof(Student));


	for(int i=0;i<3;i++)
	{	

		putG(&arr, (void*) (students+i));
	}

	for(int i=0;i<3;i++)
	{
		printf("%s\n",  ((Student*) (arr.a+i*sizeof(Student)))->name );
	}


}





void testArray()
{


	// testAGDOUBLE();
	// testAGInteger();
	testAGStuct();

}
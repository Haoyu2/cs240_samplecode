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




Array newArrayG(int capacity, int size)
{
	ArrayG arr;
	arr.capacity = capacity;
	arr.size = size;
	arr.size_n = 0;
	arr.a = calloc(capacity, size);
	return arr;
}
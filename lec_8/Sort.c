/* 
* Author : Haoyu Wang
* Description:
*	
*/

#include "lec8.h"


 
// 2 1 4 0 5

// 1 2 4 0 5
// 1 2 4 0 5

	// 1 2 0 4 5
	// 1 0 2 4 5
    // 0 1 2 4 5
// 0 1 2 4 5




void insertionSort(int a[], int len)
{

	for (int i = 1; i < len; ++i)
	{
		for (int j = i; j > 0 &&    
			a[j] < a[j-1]; --j)
		{
			swap(a, j,j-1);
		}
	}
}





// 1000000
// subarray 10000 [] id += id + 1000 the 1000 is gap make it to be h
// sort gap or 300 

// sort gap of 100


// sort gap of 1


// 2 1 4 3

// 1 2 4 3

// 1 2 4 3

void selectionSort(int a[],int len)
{

	for (int i = 0; i < len - 1 ; ++i)
	{
		int id = i;
		for (int j = i; j < len; ++j)
		{
			if (a[j] < a[id])
				id = j;
		}
		swap(a, id, i);
	}
}


void swap(int a[], int i, int j)
{
	int temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}


void printArray(int a[], int len)
{
	for (int i = 0; i < len; ++i)
	{
		printf("%d\t",a[i]);
	}
	printf("\n");
}


void testingSort()
{

	int a[] = {7 ,3, 4, 2, 1 ,6};

	// selectionSort(a, 6);
	insertionSort(a,6);
	printArray(a,6);
}
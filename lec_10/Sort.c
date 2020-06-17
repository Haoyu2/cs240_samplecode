/* 
* Author : Haoyu Wang
* Description:
*	
*/

#include "lec8.h"



int charToInt(char s[])
{
	int num=0;
	for(int i=0;s[i]!=0;i++)
	{
		if(s[i]>='0' && s[i]<='9')
			num = num*10 +s[i] -'0';
	}
	return num;
}

 
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


// h = 3*h+1;
void shellSort(int a[], int len)
{
	int h = 1; 
	while (h <= len/3) h = 3*h +1;

	while(h>=1)
	{
		for (int i = 0; i < len; i+=h)
		{
			for (int j = i; j>=h &&
				a[j]<a[j-h]; j-=h)    // j-=h <==> j=j-h;
			{
				swap(a,i, j);
			}
		}

		h /= 3;
	}

}



// a = {1,3,5, 0,2,4 }
// will merge itno {0 ,1, 2,3 ,4,5}

void merge(int a[], int aux[], int start, int mid, int end)
{
	
	for (int i = start; i <= end; ++i)
	{
		aux[i] = a[i];
	}

	// printArray(aux,6);
	int i=start, j=mid+1;
	for (int k = start; k <=end; ++k)
	{	
		if(i>mid) 
		{
			a[k] = aux[j++];
			continue;
		}
		if(j>end) 
		{
			a[k] = aux[i++];
			continue;
		}
		a[k] = aux[i] < aux[j] ? aux[i++]: aux[j++];
		// printf("k:%d,%d\t",k, a[k]);
	}

}



void mHelper(int a[], int aux[], int start, int end)
{
	if (start>=end) return;
	int mid = start + (end-start) / 2;

	mHelper(a, aux, start,mid);

	mHelper(a, aux, mid+1, end);

	if(aux[mid+1] > aux[mid]) return;
	merge(a, aux, start, mid, end);
	// printArray(a,6);
}



void mergeSort(int a[], int len)
{
	int aux[len];

	mHelper(a, aux, 0, len-1);

}




void testingSort()
{

	// int a[] = {7 ,3, 4, 2, 1 ,6};

	// // selectionSort(a, 6);
	// insertionSort(a,6);
	// printArray(a,6);

	char s[] = "80,000";
	long len = charToInt(s);

	int a[len];
	randArray(a, len);
	// selectionSortSpeed(a, len);
		// shellSortSpeed(a,len);
	// randArray(a, len);

	mergeSortSpeed(a,len);


 	// int a[] = {1,3,5, 0,2,4 };
 	// // int aux[6];
 	// // merge(a, aux, 0,2,5);
 	// mergeSort(a,6);

 	// printArray(a,6);




}

void selectionSortSpeed(int a[], int len)
{
	double time_spent = 0.0;

	clock_t begin = clock();
	// the function time to be measured
	selectionSort(a, len);

	clock_t end = clock();

	// calculate elapsed time by finding difference (end - begin) and
	// dividing the difference by CLOCKS_PER_SEC to convert to seconds
	time_spent += (double)(end - begin) / CLOCKS_PER_SEC;

	printf("selectionSort: Time elpased is %f seconds\n", time_spent);
}

void insertionSortSpeed(int a[], int len)
{
	double time_spent = 0.0;

	clock_t begin = clock();
	// the function time to be measured
	insertionSort(a, len);

	clock_t end = clock();

	insertionSort(a,len);

	// calculate elapsed time by finding difference (end - begin) and
	// dividing the difference by CLOCKS_PER_SEC to convert to seconds
	time_spent += (double)(end - begin) / CLOCKS_PER_SEC;

	printf("insertionSort: Time elpased is %f seconds\n", time_spent);
}

void shellSortSpeed(int a[], int len)
{
	double time_spent = 0.0;

	clock_t begin = clock();
	// the function time to be measured
	insertionSort(a, len);

	clock_t end = clock();

	shellSort(a,len);

	// calculate elapsed time by finding difference (end - begin) and
	// dividing the difference by CLOCKS_PER_SEC to convert to seconds
	time_spent += (double)(end - begin) / CLOCKS_PER_SEC;

	printf("shellSort: Time elpased is %f seconds\n", time_spent);
}


void mergeSortSpeed(int a[], int len)
{
	double time_spent = 0.0;

	clock_t begin = clock();
	// the function time to be measured
	insertionSort(a, len);

	clock_t end = clock();

	mergeSort(a,len);

	// calculate elapsed time by finding difference (end - begin) and
	// dividing the difference by CLOCKS_PER_SEC to convert to seconds
	time_spent += (double)(end - begin) / CLOCKS_PER_SEC;

	printf("mergerSort: Time elpased is %f seconds\n", time_spent);
}
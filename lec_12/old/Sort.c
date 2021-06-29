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




// the median function will helps for selecting the pivotal item which close to the 
// real median of subarray
// we will get the median of a[start], a[end], a[mid]
int median(int a[], int start, int end)
{
	int mid = start + (end - start) / 2;

	if(a[start] > a[mid])
	{
		swap(a, start, mid);
	}
// a[start] <= a[mid]

	if (a[end] > a[mid]) return mid;
	else{
		
		if (a[end]>a[start]) return end;
		else return start;
	} 	
}



//partition: for a random item in an array it will put that item in its right spot

//2 1 0	3 5 4

//0 1 2 3 5 4 or 1 0 2 3 5 4

// for the item to be partitioned, call it the pivotal item

// two pointers i, j scan from left to right and right to left
// 2 1 0 3 5 4

// 2 1 0 3 5 4 (i points 3, j points 0) i>j

// 0 1 2 3 5 4  result

// 2 1 0 3 5 -1

// 2 1 0 3 5 -1 (i points 3, j points -1) swap(a, i,j)
// 2 1 0 -1 5 3 (i points 5, j points 5)  
// 2 1 0 -1 5 3 (i points 5, j points -1)  i>j

// -1 1 0 2 5 3 result






int partition(int a[], int start, int end)
{
	
	int medi = median(a,start,end);
	swap(a,start,medi);

	int i = start+1, j = end;
	while(1)
	{
		while(a[i]<a[start]){
			i++;
			if (i==end) break;
		}


		while(a[j]>a[start]){
			j--;
			if (j==start) break;
		}

		// printf("%d\t%d\n",i,a[i]);
		// printf("%d\t%d\n",j,a[j]);
		if(i>=j) break;// the i here is bigger than pivotal item j
		swap(a, i++,j--);
	}
	swap(a,start, j);
	return j;
}



void qHelper(int a[], int start, int end)
{

	if (start>=end) return;
	int j= partition(a,start,end);
	qHelper(a,start,j-1);
	qHelper(a,j+1,end);

}



void quickSort(int a[], int len)
{

	qHelper(a, 0,len-1);
}



void testingSort()
{


	// int a[] = {4 ,3, 5, 2, 1 ,6};

	// // partition(a,0,5);
	// quickSort(a,6);
	// printArray(a,6);

	// int a3[3];
	// randArrayRange(a3,3, 100);
	// printArray(a3,3); 

	// printf("%d\n", median(a3,0,2));
	// printArray(a3,3);




	// // selectionSort(a, 6);
	// insertionSort(a,6);
	// printArray(a,6);

	char s[] = "2,000,000";
	long len = charToInt(s);



	// int a[len];

	int*a = malloc(len*sizeof(int));
	randArray(a, len);
	quickSortSpeed(a, len);

	// randArray(a, len);
	// selectionSortSpeed(a, len);

	// randArray(a, len);
	// insertionSortSpeed(a,len);
	
	// randArray(a, len);
	// shellSortSpeed(a,len);

	randArray(a, len);
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
	shellSort(a,len);


	clock_t end = clock();


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
	mergeSort(a,len);

	clock_t end = clock();

	

	// calculate elapsed time by finding difference (end - begin) and
	// dividing the difference by CLOCKS_PER_SEC to convert to seconds
	time_spent += (double)(end - begin) / CLOCKS_PER_SEC;

	printf("mergerSort: Time elpased is %f seconds\n", time_spent);
}



void quickSortSpeed(int a[], int len)
{
	double time_spent = 0.0;

	clock_t begin = clock();
	// the function time to be measured
	quickSort(a,len);

	clock_t end = clock();

	

	// calculate elapsed time by finding difference (end - begin) and
	// dividing the difference by CLOCKS_PER_SEC to convert to seconds
	time_spent += (double)(end - begin) / CLOCKS_PER_SEC;

	printf("quickSort: Time elpased is %f seconds\n", time_spent);
}
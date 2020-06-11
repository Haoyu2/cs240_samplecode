/* 
* Author : Haoyu Wang
* Description:
*	
*/

#include "lec8.h"


long factorial(int n)
{
	if (n == 1) return 1;
	return n * factorial(n-1);
}


long factorialIter(int n)
{
	long fac=1;
	for (int i = 2; i < n + 1; ++i)
	{
		fac *= i;
	}
	return fac;
}

//

int gcd(int p, int q)
{
	
// Keep the p > q is important
	if (p < q) gcd(q, p);

	if (q==0) return p;
	return gcd(q, p%q);
}


int gcdIter(int p, int q)
{
	if (p < q) gcd(q, p);
	while (q!=0)
	{
		int rem = p % q;
		p = q;
		q = rem;
	}
	return p;
}

//  1  2 3  4 5 
int isSorted(int a[], int len)
{
	for(int i=0;i < len -1;i++){
		if (a[i]>a[i+1]) return 0;
	}
	return 1;
}

// 1, 2, 3, 4, 6
//	 0-4  mid = 2
// 1, 2, 3, 4
//  0-3    mid = 1 



int binarySearch(int a[], int start, int end, int num)
{
	if (!isSorted(a, end+1)){
		exit(1);
		printf("Array is not sorted\n");
	} 


	if (start > end) return -1;
// check the valid index before accessing the array.

	int mid = start + (end - start) / 2;
	if (num==a[mid]) return mid;
	if (num >a[mid]) return binarySearch(a,mid+1, end, num );
	else return binarySearch(a,start, mid-1, num);

}



void testingRecursion()
{
	//fac(3) = 2*3;
	// printf("%ld\n",factorial(3));
	// printf("%ld\n",factorialIter(3));

	// printf("%d\n", gcd(15, 10));
	// printf("%d\n", gcdIter(15, 10));
	// printf("%d\n", gcd(10, 15));

	int a[] = {1,2,3,4};
	int b[] = {1,2,4,3};

	// printf("%d\t%d\n",isSorted(a,4),isSorted(b, 4));

	printf("%d\n", binarySearch(a,0,3,5));


}
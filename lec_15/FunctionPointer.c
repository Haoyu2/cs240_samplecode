#include "lec8.h"
#include "pointer.h"



void f_eg1()
{	
	int ncol=4, nrow = 3;

	int **arr = malloc(nrow*sizeof(int *));

	if(arr==NULL){
		fprintf(stderr,"%s\n"," FunctionPointer.c: f_eg1: arr");
	}


	for (int i = 0; i < nrow; ++i)
	{
		// arr[i] <==> *(arr+i) is int pointer has not yet
		// allocated memory for it.
		arr[i] = malloc(ncol * sizeof(int));
		for (int j = 0; j < ncol; j++)
		{
			arr[i][j] = j;
			printf("%d\t", arr[i][j]);
		}
		printf("\n");
	}

	for(int i=0;i<nrow ;i++){
		free(arr[i]);
	}
	free(arr);

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

	int (*func[2])(int, int);

	func[0] = fadd;
	func[1] = fmul;

	printf("%d\n", func[0](1,2));
	printf("%d\n", func[1](1,2));


	// void (*sort[3])(int *, int);
	// sort[0] = shellSortSpeed;
	void (*sort[3])(int *, int) = {
		shellSortSpeed,mergeSortSpeed,quickSortSpeed};

	char s[] = "2,000,000";
	long len = charToInt(s);
	int*a = malloc(len*sizeof(int));


	for (int i = 0; i < 3; ++i)
	{
		randArray(a, len);
		sort[i](a,len);
	}

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
	1. more than  return positive
	2. equal      return 0
	3. less than  retrrn negative

*/

int cmpInt(const void *a, const void *b)
{
	// int *a1 = (int *) a;
	// int *b1 = (int *) b;

	// return *a1 - *b1;

	return *(int *)a - * (int *) b;
}





// s1 is a reference to a char poiter then 
// s1 is a pointer to char poiter
int cmpString(const void *s1, const void *s2)
{

	// char ** ss1 = (char**) s1;
	// char ** ss2 = (char**) s2;
	// return strcmp( *ss1, *ss2);
	return strcmp( *(char**)s1, *(char**)s2);

}




//
int getMax(void *base, int n, int size, int (*cmp) (const void *, const void *))
{

		printArray((int *) base,n);


	int max = 0;
	for (int i = 0; i < n; i++)
	{
		//  base + i , base + max
		if (cmp(base + i*size,base + max*size) > 0) 
		// if (cmp(&base[i],&base[max]) > 0) 
			max = i;
	}

	return max;
}



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




void f_eg5()
{




	struct point p1 = {1,2,"hello"};


	printf("%s\n", p1.s);
	printf("%d\n", p1.x);


	

	Point p2 = {2,3,"world"};

	printf("%s\n", p2.s);

	p2.s = "Ok";
	printf("%s\n", p2.s);



	Point *pp = &p2;

	printf("%s\n", (*pp).s);
	printf("%s\n", pp->s);


}



Point padd(Point p1)
{

	p1.x = p1.x+p1.y;
	return p1;
}

void f_eg6()
{


	Point p1 = {1,2};

	Point p2 = padd(p1);

	printf("%d\t%d\n",p1.x, p2.x);
}







void testFP()
{

	// // float (*ptr[5])(int);

	// // float *(ptr1[5])(int); // wrong array of functions is wrong
	// // float (*ptr)[5](int);// wrong
	// // ptr * [5] (int)


	// float * (*f1[5])(int* (*f)(int, int), float);
	// // f1 [5] * (int* (*f)(int, int), float) * float



	// f_eg6();
	// printf("Hello, this is a snippet.\n");

	// char *s = NULL;
	// TEST_NULL(s,"FunctionPointer:testFP:s")

}
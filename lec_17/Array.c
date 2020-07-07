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

void sortAG(ArrayG *arr, int (*com)(const void *, const void *))
{

	qsort(arr->a, arr->size_n, arr->size, com);
}

int comSN(const void *s1, const void *s2)
{

	return strcmp( ((Student*)s1)->name, ((Student*)s2)->name);

}


void testAGStuct()
{


	int count = 5;

	Student students[] = {
		{ "Mike", "001", 90},
		{ "Josh", "002", 91},
		{ "John", "003", 92},
		{ "Alen", "004", 92},
		{ "Bob", "005", 92},

	};

	ArrayG arr = newArrayG(count, sizeof(Student));


	for(int i=0;i<count;i++)
	{	

		putG(&arr, (void*) (students+i));
	}

	for(int i=0;i<count;i++)
	{
		printf("%s\n",  ((Student*) (arr.a+i*sizeof(Student)))->name );
	}


	sortAG(&arr, comSN);

	printf("\n");
	Student * tmp = arr.a;
	for(int i=0;i<count;i++)
	{
		

		printf("%s\t%s\t%g\n",  tmp[i].name, tmp[i].id, tmp[i].grades );
	}

}


// In comSRN the s1 and s2 stands for the reference of refernce to student
// s1 <==? Student **
int comSRN(const void *s1, const void *s2)
{

	return comSN(* (Student **)s1, * (Student **)s2);
}


void testAGReference()
{


	int count = 5;

	Student students[] = {
		{ "Mike", "001", 90},
		{ "Josh", "002", 91},
		{ "John", "003", 92},
		{ "Alen", "004", 92},
		{ "Bob", "005", 92},

	};


	Student *students1 = malloc(sizeof(students));
	memcpy(students1,students, sizeof(students));

	//hold reference to the students array
	Student** stuRefs = malloc(sizeof(Student*)*count);





	for (int i = 0; i < count; ++i)
	{
		// students is Student pointer, so students1+i gonna point to
		// the refernce of next student.
		// if students been typecast to void pointer like many generic functions will do
		// to get to the next student reference we have to use 
		// students1+i*sizeof(Student)
		stuRefs[i] = students1 + i;//
		// students1+i <==> &students1[i]

		printf("%d\t%s\n",i, stuRefs[i]->name);
	}


	ArrayG arr = newArrayG(count,sizeof(Student *));

	for (int i = 0; i < count; ++i)
	{
		putG(&arr, stuRefs+i);	/* code */
	}

	for (int i = 0; i < count; ++i)
	{
		//arr.a stores the refences of students so it is a pointer to Student pointer
		Student **tmp = arr.a;

		printf("%s\n", tmp[i]->name);

	}	

	sortAG(&arr, comSRN);
	for (int i = 0; i < count; ++i)
	{
		//arr.a stores the refences of students so it is a pointer to Student pointer
		Student **tmp = arr.a;

		printf("%s\t%s\t%g\n",  tmp[i]->name, tmp[i]->id, tmp[i]->grades );

	}	


}






void testArray()
{


	// testAGDOUBLE();
	// testAGInteger();
	// testAGStuct();
	testAGReference();


}
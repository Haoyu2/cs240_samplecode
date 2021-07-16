#include "arraylist.h"
#include "sortbyother.h"


typedef struct
{
	int *data, length;
} IntegerArray;

IntegerArray new_IntegerArray(int length)
{
	int *data = malloc(sizeof(int) * length);
	return (IntegerArray) {data, length};
}

IntegerArray fill_IntegerArray(IntegerArray arr, int val)
{
	for (int i = 0; i < arr.length; ++i)
	{
		arr.data[i] = val;
	}
	return arr;
}


void printIntegerArray(IntegerArray arr)
{
	for (int i = 0; i < arr.length; ++i)
	{
		printf("%d, ",arr.data[i]);
	}
	printf("\n");
}




typedef struct
{
	int *data, length, capacity;
} IArrayList;

// capacity is generally set to 2^n which is bigger than the length
// log(n) + 1

int length2capcity(int length)
{
	int capacity = 1;
	while (length)
	{
		length >>= 1;
		capacity<<= 1;
	}
	return capacity;
}

IArrayList new_IArrayList(int length)
{
	int capacity = length2capcity(length);
	int * data = malloc(sizeof(int) * capacity);
	return (IArrayList) {data, length, capacity};
}


IArrayList add_IAL(IArrayList arr, int val)
{
	
	if (++arr.length >= arr.capacity) 
	{
		arr.capacity = length2capcity(arr.length);
		arr.data = realloc(arr.data, arr.capacity);
	}
	arr.data[arr.length] = val;
	return arr;
}






void testingARRAYLIST()
{
	// printf("Hello\n");

	printIntegerArray(fill_IntegerArray(new_IntegerArray(5), -5));

	IArrayList al = new_IArrayList(10);
	printf("%d\n", al.capacity);

	IArrayList al1 = new_IArrayList(0);

	printf("%d\t%d\n",al1.length, al1.capacity);	
	add_IAL(al1, 1);
	add_IAL(al1, 1);
	printf("%d\t%d\n\n",al1.length, al1.capacity);

	printf("%d\t%d\n",al1.length, al1.capacity);	
	al1 = add_IAL(al1, 1);
	printf("%d\t%d\n",al1.length, al1.capacity);	
	


}
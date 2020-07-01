#ifndef ARRAY_H
#define ARRAY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct array
{
	int *a, size, capacity;

	void (*put)(struct array *, int);

	int (*remove)(struct array *);
}Array;



void testArray();



Array newArray(int capacity);

Array put1(Array, int);
void put(Array *arr, int a);

int removeA(Array *);
void pArray(Array arr);




// Generic Array which can hold any data type;


typedef struct arrayG
{
	void *a;

	// size_n indicates the number of valid member
	// the size indicates the size of data type
	int size_n, capacity, size;

	void (*put)(struct array *, int);

	int (*remove)(struct array *);
}ArrayG;


ArrayG newArrayG(int capacity, int size);

void putG(ArrayG *arr, void *);

int removeAG(ArrayG *);
// void pArrayG(ArrayG arr);




#endif
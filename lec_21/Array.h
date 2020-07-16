#ifndef ARRAY_H
#define ARRAY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>



typedef struct student
{	
	char *name;
	char *id;
	double grades;
} Student;





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

void sortAG(ArrayG *, int (*com)(const void *, const void *));


int removeAG(ArrayG *);
// void pArrayG(ArrayG arr);




/*

	Headers for Stack
*/

typedef struct nodeS{
	void *item;
	// we could put it here;
	// but it is bettter we put it in linkedlist
	// such that save some space
	// int size;
	struct nodeS * next;
}NodeS;

typedef struct {
	NodeS *top;
	int size;
}Stack;	



Stack newStack(int size);
void push(Stack* ll, void *item);
void *pop(Stack* ll);
ArrayG getStack(Stack * st);




/*

	Headers for Queue
*/

typedef struct nodeQ{
	void *item;
	// we could put it here;
	// but it is bettter we put it in linkedlist
	// such that save some space
	// int size;
	struct nodeQ * next;
}NodeQ;

typedef struct {
	NodeQ *first, *last;
	int size;
}Queue;	



Queue newQueue(int size);
void enqueue(Queue* ll, void *item);
void *dequeue(Queue* ll);
ArrayG getQueue(Queue * q);






/*

	LinkedList

*/


int cmpInt(const void *a, const void *b);
int cmpDouble(const void *a, const void *b);


typedef struct nodeL
{
	void *item;
	struct nodeL *next;
} NodeL;


typedef struct ll
{
	int size, size_n;
	NodeL *root;
}LinkedList;


NodeL* newNodeL(void *item, int size);
LinkedList* newLinkedList(int);

void addLL(LinkedList *l, void *);

NodeL* midNodeL(NodeL * node);
NodeL* mergeNL(NodeL *node1, NodeL*node2,int (*cmp)(const void *a, const void *b)); 
NodeL* mergeNLIter(NodeL *node1, NodeL*node2,int (*cmp)(const void *a, const void *b)); 

NodeL*  mergeSortNL(NodeL *l,int (*cmp)(const void *a, const void *b)); 
void mergeSortLL(LinkedList *l,int (*cmp)(const void *a, const void *b)); 


void testLL();










typedef struct ll
{
	int size, size_n, len;
	NodeL *root;
}LinkedListArray;









#endif
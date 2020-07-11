/* 
* Author : Haoyu Wang
* Description:
*	
*/

#include "Array.h"



Stack newStack(int size)
{

	Stack stack = {NULL,size};
	return stack;
}

void push(Stack* st, void *item)
{

	NodeS *node = malloc(sizeof(NodeS));
	node->item = malloc(st->size);
	memcpy(node->item, item, st->size);

	node->next = st->top;
	st->top = node;
}


void *pop(Stack* st)
{

	if (st->top==NULL){
		fprintf(stderr,"%s\n","cannot pop from an empty stack" );
		exit(1);
	}

	void *p = st->top->item;
	st->top= st->top->next;
	return p;
}


// top
//  1

//  2  1






void testS1()
{
	int count = 5;

	Stack st = newStack(sizeof(int));

	for (int i = 0; i < count; ++i)
	{
		push(&st, &i);
	}

	for (int i = 0; i < count; ++i)
	{	

		int *p = (int *) pop(&st);
		printf("%d\t", *p);
	}

}


ArrayG getStack(Stack *st)
{

	ArrayG arr = newArrayG(10, sizeof(int));




	NodeS *pn = st->top;

	while (pn!=NULL)
	{
		putG(&arr,pn->item);
		pn = pn->next;
	}

	// double *a = (double *)  arr.a;

	// for (int i = 0; i < arr.size_n; ++i)
	// {
	// 	printf("%f\t", a[i]);
	// }



	return arr;


}



void testIter()
{

	int count = 5;
	Stack st = newStack(sizeof(int));

	for (int i = 0; i < count; ++i)
	{
		push(&st, &i);
	}


	ArrayG arr = getStack(&st);

	int *a = (int *)  arr.a;

	for (int i = 0; i < arr.size_n; ++i)
	{
		printf("%d\t", a[i]);
	}

	printf("\n");

}



void testIterDouble()
{

	int count = 5;
	Stack st = newStack(sizeof(double));

	double j = 10.0;
	for (int i = 0; i < count; ++i)
	{
		j = j+i;
		printf("%f\n", j);
		push(&st, &j);
	}


	ArrayG arr = getStack(&st);

	double *a = (double *)  arr.a;

	for (int i = 0; i < arr.size_n; ++i)
	{
		printf("%f\t", a[i]);
	}



}




Queue newQueue(int size)
{

	Queue q = {NULL,NULL, size};
	return q;
}

void enqueue(Queue* st, void *item)
{

	

	NodeQ *node = malloc(sizeof(NodeQ));
	node->item = malloc(st->size);
	memcpy(node->item, item, st->size);
	node->next = NULL;

	if (st->first == NULL)
	{
		st->first = st->last = node;
	}else
	{
		st->last->next = node;
		st->last = node; 

	}
}
	


void *dequeue(Queue* st)
{

	if (st->first==NULL){
		fprintf(stderr,"%s\n","cannot dequeue from an empty q" );
		exit(1);
	}

	void *p = st->first->item;
	st->first = st->first->next;
	return p;
}


// first  last
//  1 2 3 4 

// 5 comes in 

// first    last
//  1 2 3 4  5


// dequeue will remove the first item 
// l





void testQ()
{

	int count = 5;
	Queue q = newQueue(sizeof(int));

	for (int i = 0; i < count; ++i)
	{
		enqueue(&q, &i);
	}


	

	

	for (int i = 0; i < count; ++i)
	{	
		int *a = (int *) dequeue(&q);
		printf("%d\t", *a);
	}

	printf("\n");


}


void testQDouble()
{

	int count = 5;
	Queue q = newQueue(sizeof(double));

	double j = 0.0;
	for (int i = 0; i < count; ++i)
	{	
		j+= 1.0;
		enqueue(&q, &j);
	}


	

	

	for (int i = 0; i < count; ++i)
	{	
		double *a = (double *) dequeue(&q);
		printf("%f\t", *a);
	}

	printf("\n");


}












void testStack()
{

	// testIter();
	// testIterDouble();

	// testQ();
	testQDouble();
	// testS1();


}
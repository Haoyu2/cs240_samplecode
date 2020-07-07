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

	NodeS *node = mallloc(sizeof(Nodes));
	node->item = mallloc(st->size);
	memcpy(node->item, item, st->size);

	node->next = st->top;
	st->top = node;
}


void *pop(Stack* st)
{

	if (st->top==NULL)
		fprintf(stderr,"%s\n","cannot empty stack" );

	void *p = st->top->item;
	st->top= st->top->next;
	return p;

}


// top
//  1

//  2  1



void iterStack(Stack * st)
{
	int count = 5;

	Stack st = newStack(sizeof(int));

	for (int i = 0; i < count; ++i)
	{
		push(&st, &i);
	}

	for (int i = 0; i < count; ++i)
	{
		
	}

}



void testStack()
{




}
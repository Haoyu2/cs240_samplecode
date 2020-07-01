#ifndef POINTER_H
#define POINTER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define TEST_NULL(p,s) 	\
		if (NULL==p){		\
			fprintf(stderr, "%s:NULL POINTER EXCEPTION\n", s);\
			exit(1);}








typedef struct point{
	int x,y;
	char *s;
}Point;

typedef struct student
{	
	char *name;
	char *id;
	double grades;
} Student;





void testingPointer();
void testDynam();

void testFP();
void testStruct();



#endif
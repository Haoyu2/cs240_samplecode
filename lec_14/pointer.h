#ifndef POINTER_H
#define POINTER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// struct point
// {	
// 	int x,y;
// 	char *s;
	
// };
// typedef struct point Point;


typedef struct point{
	int x,y;
	char *s;
}Point;


void testingPointer();
void testDynam();

void testFP();



#endif
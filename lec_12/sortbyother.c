#include "sortbyother.h"


/**
 * 	structure variable value assignment
 * 
 */

char * point2string(Point point)
{
	char * s = malloc(100);
	sprintf(s, "x:%d, y:%d", point.x, point.y);
	s = realloc(s, strlen(s));
	return s;
}

void demo_SVA()
{
	Point p1 = {1, 1};
	Point p2 =  p1;
	printf("%s\n", point2string(p2));
}






/**
 * 
 * Q. sort one array by the order of another array
 * 
 * 
 * 
 * 	int nums[] = {1, 2, 3};
 * 	char cs[]  = {'c', 'b', 'a'};
 * 
 * 
 * 1. we can write sorting using the comparator function which use index
 * 
 * 2. rely on qsort which the comparator relyes on the reference of the 
 * 	  elements of the array
 * 	
 * 	
 * 	2.1, create a new struct that combines both array info element to element
 * 	
 * 	2.2, create a new struct that combines the sorting array index and element
 * 		  sort the array by new index order
 *	
 *  
 */
typedef struct
{
	int i;
	char c;
} Mix;

int cmpMix(const void *a, const void *b)
{
	return ((Mix*) a) ->c - ((Mix*) b) ->c;
}

void sort_by_other_demo()
{
	int nums[] = {1, 2, 3};
 	char cs[]  = {'c', 'b', 'a'};

 	// if sort nums by order of cs
 	// then nums = {3, 2, 1}



 	Mix mix[3];
 	for (int i = 0; i < 3; ++i) 
 	{
 		// mix[i] = {nums[i], cs[i]}; //not allowed
 		mix[i] = (Mix) {nums[i], cs[i]}; //allowed
 		// mix[i].i = nums[i];
 		// mix[i].c = cs[i];

 		// Mix cur = {nums[i], cs[i]};
 		// mix[i] = cur;
 	}

 	qsort(mix, 3, sizeof(Mix), cmpMix);
 	for (int i = 0; i < 3; ++i)
 	{
 		nums[i] = mix[i].i;
 	}
 	
 	for (int i = 0; i < 3; ++i)
 	{
 		printf("%d\t", nums[i]);
 	}




}






void testingSORTBYOTHER()
{
	// printf("Hello\n");
	// demo_SVA();
	sort_by_other_demo();

}
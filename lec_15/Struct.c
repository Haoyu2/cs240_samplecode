
/* 
* Author : Haoyu Wang
* Description:
*	
*/

#include "lec8.h"
#include "pointer.h"
#include "Array.h"


// Array structure
//

void s_eg1()
{




	Array arr = newArray(3);
	printf("%d\n", arr.capacity);
	for (int i = 0; i < arr.capacity; ++i)
	{
		printf("%d\n", arr.a[i]);	
	}

	printf("cap:%d\n", arr.capacity);
	for(int i=0; i<5;i++)
	{
		arr.put(&arr, i);
	}
	printf("cap:%d\n", arr.capacity);

	pArray(arr);


	printf("cap:%d\n", arr.capacity);

	for (int i = 0; i < 4; ++i)
	{
		printf("%d\n",arr.remove(&arr) );
		
	}
	printf("cap:%d\t\n", arr.capacity);


}



void eg_2()
{


	
}



void testStruct()
{
	s_eg1();

	// printf("Hello, this is a snippet.\n");

}
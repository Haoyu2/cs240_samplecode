#include "lec8.h"


// First of all, rand() returns values on [0, RAND_MAX], 
// including both ends, that's RAND_MAX+1 possible values.




void randArray(int a[], int len)
{
	srand(time(0));
	for (int i = 0; i < len; ++i)
	{
		a[i] = rand();	/* code */
	}
}

// this genrate number form 0 to max psudo randomly
void randArrayRange(int a[], int len, int max)
{
	srand(time(0));
	for (int i = 0; i < len; ++i)
	{
		a[i] = rand() % max;	/* code */
	}

}




void testingRand()
{

	

	srand(time(0));
	// printf("%ld\n\n", time(0));

	// for (int i = 0; i < 10; ++i)
	// {
	// 	printf("%d\n", rand());
	// }

	int len = 10;
	int a[10];
	randArrayRange(a, len, 100);
	printArray(a, len);


}
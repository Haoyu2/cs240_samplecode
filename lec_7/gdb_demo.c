/* 
* Author : Haoyu Wang
* Description:
*	
*/

#include <stdio.h>

void test(){
	int i=0, sum=0;

	char *s = "hell0";
	char ss[] = "hello";
	// s[1] = 'g';
	ss[1] = 'g';
	printf("%s\n", ss);

	while (i<10)
	{
		sum += i++;
	}

}

int main(int argc, char *argv[])
{

	printf("%d\n", argc);
	
	#ifdef DEBUG
	printf("%s\n", argv[0]);
	#endif

	int i=0, sum=0;
	while (i<10)
	{
		sum += i++;
	}

	test();

	return 0;
}
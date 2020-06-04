
/* 
* Author : Haoyu Wang
* Description:
*	
*/
#include <stdio.h>
#include <ctype.h>

void swap(int a, int b){

	printf("local: %d\t%d\n",a,b);
	int temp;
	temp = a;
	a = b;
	b = temp;
	printf("local: %d\t%d\n",a,b);


}

void incre(int a[], int len){
	for (int i=0;i<len;i++)
		a[i] += 1;
}

int main(int argc, char *argv[])
{

	int a=0, b=1;

	swap(a,b);
	printf("%d\t%d\n",a,b);

	int c[] = {1, 2, 3};

	for (int i=0;i<3;i++)
		c[i] += 1;
	incre(c, 3);

	for (int i=0;i<3;i++)
		printf("%d\t", c[i]);;


	return 0;
}
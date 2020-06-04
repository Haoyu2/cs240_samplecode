
/* 
* Author : Haoyu Wang
* Description:
*	
*/
#include <stdio.h>
#include <ctype.h>

// EOF  (-1)
// ctrl-d
// stdin stdout stderr
// stdin mode 

// < > >> << 
int main(int argc, char *argv[])
{

	// getchar();// first letter

	// // printf("%d\n", getchar());
	// putchar(getchar());

	int c;
	while ((c=getchar()) != EOF)
		putchar(c);

	return 0;
}
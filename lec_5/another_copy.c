
/* 
* Author : Haoyu Wang
* Description:
*	
*/
#include <stdio.h>
#include <ctype.h>

// EOF  (-1)
// ctrl-d
// stdin stdout stderr  three system stream/file pointers
// stdin mode 

// < > >> << 
int main(int argc, char *argv[])
{

	// getchar();// first letter

	// // printf("%d\n", getchar());
	// putchar(getchar());

	// <  

//  From keyboard to input EOF(-1) on linux is ctrl-D
//  on windows in ctrl-z
//  ctrl-c on mac
	int c;
	while ((c=getchar()) != EOF)
		putchar(c);


	// printf("EOF:%d\t NULL Character:%d", EOF, '\0');

	return 0;
}
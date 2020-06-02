/* Project: lec3
 * Name   : Haoyu Wang
 * Date   : 01/03/2020
 */
#include <stdio.h>
#include <ctype.h>

int main(void)
{


	// int 32
	// long int 64

	// printf("%ld\n",sizeof(char));


	// printf("%c\n",65);
	// printf("%d\n", 'A' + 10);


	// printf("%c\n", 64);

	// printf("%d\n", isalpha(64));

	// printf("%d\n", isdigit('1'));

	// if (isdigit('1')) 
	// 	printf("True\n");

	// check if a char c is a upper case letter


	char c = 68;
	90=='Z';

	if (c<='Z' && c>= 65)
		printf("Upper case letter\n");

	printf("%c\n",tolower('A') );

	char c1 = 'B';


	printf("%c\n",c1+'z' - 'Z');


	// printf("%f\n", 1.1);
	// char c1 = 65;
	// unsigned c2 = 66;

	// putchar(c1);
	// putchar(c2);
	// printf("%c%c\n", c1,c2);

  return 0;
}
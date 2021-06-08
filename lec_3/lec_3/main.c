#include <stdio.h>
#include <ctype.h>

int main(int argc, char const *argv[])
{
	printf("%c\n", 67);
	printf("%d\n", isdigit('1'));
	printf("%d\n", ('\n'));
	printf("%d\n", '0');
	printf("%d\n", 0);
	printf("%s\n", "0");


	printf("%d\n", 10);
	printf("%d\n", 010); // 010 is octal integer 
	                     // 1*8 + 0 * 8 = 8
	printf("%d\n", 010); // 010 is octal integer 

	printf("%d\n", 0x10); // 0x10 is hex integer 
						 //  1 * 16 + 0 * 16 = 16

	printf("%ld\n", 10l);

	printf("%x\n", 16);
	printf("%x\n", 15); // x is hex format of a integer value

	printf("Octal: %o\n", 8);
	// printf("Octal %o\n", 080); be careful the error

	printf("%d\n", 15u);

	printf("g: %g\n", 3.14111111);
	printf("e: %10g\n", 3.14111111);
	printf("e: %10.10g\n", 3.14111111);




	return 0;
}
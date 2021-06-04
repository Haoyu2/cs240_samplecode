



//preprocess directive
#include <stdio.h>


/**
 * @brief [brief description]
 * @details [long description]
 * 
 * @param a [description]
 * @param b [description]
 * 
 * 
 * @return [description]
 */
int add(int a, int b){

	return a + b;
}

// Doxy​Doc

/*
	
	multiple line comments
	
*/

/**
 * @brief [brief description]
 * @details [long description]
 * 
 * @param argc int indicates how many commandline inputs
 * @param argv array of char * (string) (stores all the commandline inputs)
 * 
 * @return int 0 means runs correctly
 */
int main(int argc, char const *argv[])
{
	int _a;
	// int 1a; wrong
	printf("%d\n", argc);
	// printf("%s\n", argv[0]);
	// printf("%s\n", argv[1]);
	printf("Hello Wolrd!\n");
	return 0;
}
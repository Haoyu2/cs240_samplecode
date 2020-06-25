/* 
* Author : 
* Description:
*	
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char ** fgetLines(FILE* f, int *nl)
{
}




char ** sgetWords(char *line, int *nw)
{
	
}

char* cPrefix(char **words, int nw)
{
	
}





/*
	Do not modify the main function when submit.
	You can modify it when doing your homework.
*/

int main(int argc, char *argv[])
{

	// Get test file name from commandline or default to test.txt
	char *fs = argc>2 ? argv[1] : "test.txt";
	FILE *f = fopen(fs,"r");	
	
	// Read each line into lines, nl is the number of lines
	
	int nl=0, nw=0;
	char **lines = fgetLines(f, &nl);

	for (int i = 0; i < nl; ++i)
	{	
		/*
			Read each word into words, nw is the number of words for each line
			words should have separate memory than lines[i]
		*/		
		nw=0;
		char **words= sgetWords(lines[i], &nw);
		if (nw==0) continue;
		
		printf("\nTotal: %d\n", nw);
		for (int i = 0; i < nw; ++i) printf("%s, ", words[i]);
		printf("\nThe common prefix is: %s\n", cPrefix(words,nw));
		
		for (int i = 0; i < nw; ++i) free(words[i]);		
		free(words);

	}

	for (int i = 0; i < nl; ++i) free(lines[i]);		
	free(lines);
	fclose(f);



	return 0;
}
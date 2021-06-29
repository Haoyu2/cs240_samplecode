
/* 
* Author : Haoyu Wang
* Description:
*	
*/
#include <stdio.h>
#include <ctype.h>


int getLineNum(){

	int count = 0, c=0, c1;
	while ((c=getchar())!= EOF){
		if (c=='\n')
			count++;
		c1 = c;
	}

	// the last line may not have a new line character
	if (c1!='\n') count++;

	return count;

}

// definition of line
int maxLine(){
	int count = 0, max=-1, c;
	while ((c=getchar())!=EOF){

		if (c == '\n'){
			if (count>max)
				max = count;
			count = 0;
		}
		count++;
	}
	return max;
}


int getLine(char s[], int lim){

	int c,i;
	for (i=0; i<lim-1 && (c=getchar())!='\n' && c!=EOF ;i++){

		s[i] = c;
	}

	
	s[i] = '\0';
	return i;
}

//  h e l l o \0   6
//  h e l l o      5


double PI = 3.1415926;


int main(int argc, char *argv[])
{

	printf("%g\n",PI );

	// printf("%d\n", getLineNum());




	// EOF is symbolic constant -1 defined in <stdio> to indicate the 
	// end of file. 
	// printf("%d\n", EOF);

	// printf("%d\n", maxLine());

	// int lim = 22;
	// char s[lim];
	// getLine(s,lim);
	// printf("%s\n", s);	


	return 0;
}
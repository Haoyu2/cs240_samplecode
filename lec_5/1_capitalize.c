
/* 
* Author : Haoyu Wang
* Description:
*	
*/
#include <stdio.h>
#include <ctype.h>

void lower(char s[]){
	for (int i=0;s[i]!=0;i++){
		if (s[i]<='Z'&&s[i]>='A')
			s[i] += 'a' - 'A';
	}
}

//words are made of alphanumeric
void cap1(char s[]){

	if (isalpha(s[0])) s[0] += 'A' - 'a';
	for (int i=1;s[i]!=0;i++){
		if (!isalnum(s[i-1]) && isalpha(s[i]))
			s[i] += 'A' - 'a';
	}

}



//words are made of alpha
void cap(char s[]){

	if (isalpha(s[0])) s[0] += 'A' - 'a';
	for (int i=1;s[i]!=0;i++){
		if (!isalpha(s[i-1]) && isalpha(s[i]))
			s[i] += 'A' - 'a';
	}

}

int main(int argc, char *argv[])
{

	char ss[] = "hello -wed23yes  ok right";
	
	cap(ss);
	printf("%s\n", ss);

	lower(ss);
	cap1(ss);
	printf("%s\n", ss);





	return 0;
}
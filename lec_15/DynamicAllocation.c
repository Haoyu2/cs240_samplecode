#include "lec8.h"
#include "pointer.h"

// malloc calloc realloc free



void d_eg1()
{

	char *s = malloc(1*sizeof(char));
	char *s1 = calloc(10, sizeof(char));

	// s1 = "hello";// pointer reassignment

	char *s2 = "hello";

	// int i;
	// for (i = 0; s2[i]!='\0'; ++i)
	// {
	// 	s1[i] = s2[i];
	// }

	// s1[i] = '\0';

	memcpy(s1,s2, 6);

	printf("%s\n", s1);
	free(s2);
	free(s);


}


// memcpy
void d_eg2()
{

	int len =10;
	int *arr = malloc(len);

	int a[] = {1,2,3};

	memcpy(arr,a,3*sizeof(int));

	printf("%d\n", arr[0]);

	free(arr);


}


// two-dimemsional array alloction;

// int **arr
int ** d_eg3()
{	
	int ncol=4, nrow = 3;

	int **arr = malloc(nrow*sizeof(int *));

	for (int i = 0; i < nrow; ++i)
	{
		// arr[i] <==> *(arr+i) is int pointer has not yet
		// allocated memory for it.
		arr[i] = malloc(ncol * sizeof(int));
		for (int j = 0; j < ncol; j++)
		{
			arr[i][j] = j;
			printf("%d\t", arr[i][j]);
		}
		printf("\n");
	}

	int arr1[3][4];

	arr1[0][0] = -1;

	return arr;

}

void d_eg4(int **arr, int nrow, int ncol )
{

	printf("eg4\n");
	for (int i = 0; i < nrow; ++i)
	{

		for (int j = 0; j < ncol; j++)
		{
			
			printf("%d\t", arr[i][j]);
		}
		printf("\n");
	}
}


// allocation and free have to work in pair if pointer changed then free won't work.
void d_eg5()
{

	char *a = malloc(5);

	a[0] = 'A';a[1] = 'B';
	char *pa = a;
	pa++; // use index than pointer arith
	putchar(*pa);
	free(a);

}



// two-dimemsional array alloction;
// int **arr
int *** d_eg6()
{	
	int narr = 2,  ncol=4, nrow = 3;

	int ***arr = malloc(narr*sizeof(int **));


	int h=0;
	for (int k = 0; k < narr; ++k)
	{
		arr[k] = malloc(nrow*sizeof(int *));

		for (int i = 0; i < nrow; ++i)
		{
			// arr[i] <==> *(arr+i) is int pointer has not yet
			// allocated memory for it.
			arr[k][i] = malloc(ncol * sizeof(int));
			for (int j = 0; j < ncol; j++)
			{
				arr[k][i][j] = h++;
				printf("%d\t", arr[k][i][j]);
			}
			printf("\n");
		}
		printf("\n");
	}
	
	return arr;

}


// memory comparison
void d_eg7()
{
	// int array heap mem
	//  nrow*sizeof(int *) + nrow * ncol * sizeof(int)
	// 10 by 2   10*8 + 10* 2*4  =  80 + 240 = 320
	// 2 by 10   2*8  + 2 *10*4  =  18 + 240 

}



// stack array the length and array are fixed
// heap array we can reallocate it
void d_eg8()
{

	char *string = "Hello, this is a snippet.";

	int cs = 2, i=0;
	char *s = malloc(cs);

	while (string[i]!='\0')
	{
		if(i>=cs)
		{
			cs*=2;
			s = realloc(s,cs);
		}
		s[i] = string[i];
		i++;
	}

	s[i] = 0;
	s = realloc(s,i);
	printf("%s\n", s);

}



//
void d_eg9()
{
	char *string = "Hello, this is a snippet. \nHello, this is a snippet. \nHello, this is a snippet. \n ";

	int cl=2, nl=0, i=0;

	char **lines = malloc(cl*sizeof(char*));


	while (string[i]!='\0')
	{
		
		if (nl>=cl)
		{
			cl *= 2;
			lines = realloc(lines, cl*sizeof(char *));
		}

		int cn = 2;
		lines[nl] = malloc(cn*sizeof(char));

		int j=0;
		while(string[i]!='\n'&& string[i]!=0)
		{
			if(i>=cn)
			{
				cn*=2;
				lines[nl] = realloc(lines[nl],cn);
			}
			lines[nl][j++] = string[i++];
		}

		lines[nl][j++] = '\n';	
		lines[nl][j++] = '\0';
		lines[nl] = realloc(lines[nl],j);
	
		nl++;
		if (string[i++]=='\0') break;
	}

	for (int i = 0; i < nl; ++i)
	{
		printf("%s",lines[i] );
	}

}



//FILE pointer or stream

// stdin stdout stderr

void d_eg10()
{

	FILE *f = fopen("makefile","r");

// EOF is the end of file stream  -1
// '\0' is end of char array       0
	putchar(fgetc(f));

	printf("\nEOF%d\t%d\n",EOF,'\0' );

	/*

	*/

	int c;
	while ( (c=fgetc(f))!=EOF) putchar(c);

	// char s[100];
	// while (fgets(s,100,f)!=NULL)
	// 	printf("%s\n", s);



	fclose(f);

}

void testDynam()
{
	

	d_eg10();
	// d_eg4(d_eg3(), 3, 4);
	// printf("Hello, this is a snippet.\n");
}









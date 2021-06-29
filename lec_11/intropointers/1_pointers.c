/* 
* Author : Haoyu Wang
* Description:
*	
*/

#include <stdio.h>

int main(int argc, char *argv[])
{


	int i = 3; 
	// p is a pointer and it stores an address value
	// declaraion doen't give it an initial address value
	int *p;
	int *p1;

	// printf("%d\n", *p);// wrong

	p = &i;// initialization, p reference to i

	// printf("%d\n", *p);// correct
	
	// printf("%p\n", p);
	// printf("%p\n", &p);
	// printf("%p\n", &p1);






// suposs &p= 0x7fffe5327750
//        p = 0x7fffe5327840
//        *p = 1

	// p stay at stack






// i	0x7fffe532774c 




//		0x7fffe5327843	0000 0001  01
//		0x7fffe5327842	0000 0000  00
//		0x7fffe5327841	0000 0000  00
//	p=	0x7fffe5327840	0000 0000  00



//  	0x7fffe5327757  0100 0000  40
//  	0x7fffe5327756  0111 1000  78
//  	0x7fffe5327755  0011 0010  32
//  	0x7fffe5327754  1110 0101  e5
//  	0x7fffe5327753  1111 1111  ff
//  	0x7fffe5327752  0111 1111  7f
//  	0x7fffe5327751  0000 0000  00
//  &p= 0x7fffe5327750  0000 0000  00


	
	// printf("%p\n", &p);
	// printf("%p\n", p);
	// printf("%d\n",*p );


	// printf("%p\n", &i);

 //    p = &i;
    // agter this *p is same as i

// when we use i, it is equvalent to *(&i)

	// printf("%d\n", *p);
	// printf("%p\n", p);


	int a[10]= {3,-1};

	printf("%p\n", a);
	printf("%p\n", &a[0]);

	printf("%d\n", a == &a[0]);

	printf("%p\n", &a[1]);

	printf("%p\n", a + 1);//address of the second element in a

	printf("%d\n",*(a + 1));


	// a is just constant pointer it stores address value

	printf("%d\n", *a + 1);
	// printf("%d\n", *(a + 1));

	// printf("%p\n", a++);wrong


	// printf("%d\n", a[-1]);// even legal but should not do that



	// char amessage[] = "1234"; /* an array */
	// char *pmessage = "1234"; /* a pointer */

	// printf("%p\n",amessage);
	// printf("%p\n",&pmessage);

	// printf("%p\n",pmessage);

	char *lineptr[3];
	lineptr[0] = "hello";



	return 0;
}
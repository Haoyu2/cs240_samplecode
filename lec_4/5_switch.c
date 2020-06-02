
/* 
* Author : Haoyu Wang
* Description:
*	The break statement causes an immediate exit from the switch . 
	Because cases serve just as labels, after the code for one case
	is done, execution falls through to the next unless you take explicit action to escape.
*	
*/
#include <stdio.h>





int main(int argc, char *argv[])
{
	// for (int i=0;i<10;i++){
	// 	switch (i){
	// 		case 8:
	// 			printf("%d\n", i);
	// // without break the execution will follow through the next case
	// 		case 9:
	// 			printf("%d\n", i);
	// 			break;
	// 		case 0: case 1:
	// 			printf("%d\n", i);
	// 			break;  // break will jump out current loop branch

	// 		default:
	// 			printf("Oh!\n");

	// 	}

	// }

	// int i=0,j=0;
	// printf("%d%d\n", i++,j-- );

	
	// do {
	// 	printf("hello\n");
	// }while (0);

	// while (0){
	// 	printf("hello\n");
	// }


	for (int i=0; i<5;i++){

		if (i==3) continue;
		printf("%d\t", i);
	}
	printf("\n");

	for (int i=0; i<5;i++){

		if (i==3) break;
		printf("%d\t", i);
	}


	return 0;
}
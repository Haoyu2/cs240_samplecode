#include "arraylist.h"
#include "sortbyother.h"


typedef struct
{
	int a;
	int *b;
} ValuePassDemo;


/**
 *  in C all arguments are passed by value
 *  
 *  when vp gets passed
 *  
 *  vp.a value passed to local  
 *  vp.b value passed to local
 *  
 *  so 
 * 	
 * 	both local and caller will have the same value of vp.a and vp.b
 * 	but they are seperate copy of vp
 * 	
 * 	as vp.b is a pointer so vp.b will point to the same memry 
 * 
 * 
 * 
 */

ValuePassDemo plus1(ValuePassDemo vp)
{
	vp.a++;
	(*vp.b)++;
	printf("Local plus1: a:%d\tb:%d\n", vp.a, *vp.b);
	return vp;
}



void valuePassDemo()
{

	ValuePassDemo vp = {1, NULL};
	vp.b = malloc(sizeof(int));

	*vp.b = 1;

	printf("a:%d\tb:%d\n", vp.a, *vp.b);

	plus1(vp);
	printf("a:%d\tb:%d\n", vp.a, *vp.b);

	vp = plus1(vp);
	printf("a:%d\tb:%d\n", vp.a, *vp.b);

}







typedef struct
{
	int *data, length;
} IntegerArray;

IntegerArray new_IntegerArray(int length)
{
	int *data = malloc(sizeof(int) * length);
	return (IntegerArray) {data, length};
}

IntegerArray fill_IntegerArray(IntegerArray arr, int val)
{
	for (int i = 0; i < arr.length; ++i)
	{
		arr.data[i] = val;
	}
	return arr;
}


void printIntegerArray(IntegerArray arr)
{
	for (int i = 0; i < arr.length; ++i)
	{
		printf("%d, ",arr.data[i]);
	}
	printf("\n");
}




typedef struct
{
	int *data, length, capacity;
} IArrayList;


void printIArrayList(IArrayList al)
{
	for (int i = 0; i < al.length; ++i)
	{
		printf("%d\t", al.data[i]);
	}
	printf("\n");
}




// capacity is generally set to 2^n which is bigger than the length
// log(n) + 1

int length2capcity(int length)
{
	int capacity = 1;
	while (length)
	{
		length >>= 1;
		capacity<<= 1;
	}
	return capacity;
}

IArrayList new_IArrayList(int length)
{
	int capacity = length2capcity(length);
	int * data = malloc(sizeof(int) * capacity);
	return (IArrayList) {data, length, capacity};
}


IArrayList add_IAL(IArrayList arr, int val)
{
	
	if (++arr.length >= arr.capacity) 
	{
		arr.capacity = length2capcity(arr.length);
		arr.data = realloc(arr.data, arr.capacity * sizeof(int));
	}
	arr.data[arr.length-1] = val;
	return arr;
}

// we have to return the last int value and so we can not return the updated IArraylist \
// if we donot use a reference for the argument

// for this design we cannot indicate a poping from an empty list using a primite integer 
// return data type

// if we return a reference integer data type we can use null value to indicate pop
// from empty list for the caller function
int pop_IAL(IArrayList *arr)
{
	if ( arr->length == 0)
	{
		printf("Return -1, but this -1 means poping from an empty list\n ");
		// this is just a comment for demo, the caller function doesnot know
		// this message nor it can difficiate the -1 is from error or from array list
		return -1;
	}

	arr->length--;
	// when the length becames much smaller than capacity 
	// we should shrink the capacity;

	int val = arr->data[arr->length];
	if (arr->length <= arr->capacity >> 2)
	{
		arr->capacity = arr->capacity>>1;
		arr->data = realloc(arr->data, arr->capacity*sizeof(int));
	}

	return val;
}





void testingARRAYLIST()
{
	// printf("Hello\n");
	// valuePassDemo();

	// printIntegerArray(fill_IntegerArray(new_IntegerArray(5), -5));

	// IArrayList al = new_IArrayList(10);
	// printf("%d\n", al.capacity);

	// IArrayList al1 = new_IArrayList(0);

	// printf("%d\t%d\n",al1.length, al1.capacity);	
	// al1 = add_IAL(al1, 1);
	// al1 = add_IAL(al1, 1);
	// printf("%d\t%d\n\n",al1.length, al1.capacity);

	// IArrayList al2 = new_IArrayList(0);
	// for (int i = 0; i < 10; ++i)
	// {
	// 	al2 = add_IAL(al2, i);
	// }
	// printIArrayList(al2);


	// for (int i = 0; i < 11; ++i)
	// {
	// 	printf("%d\t%d\t%d\n", pop_IAL(&al2), al2.length, al2.capacity);
	// }

	struct foo {
		char *p;
		char c;
		long x;
	};


	printf("%ld bytes\n", sizeof(struct foo));


	struct __attribute__((__packed__)) foo1 {
		char *p;
		/* 8 bytes */
		char c;
		/* 1 byte */
		long x;
		/* 8 bytes */
		};

		printf("%ld bytes\n", sizeof(struct foo1));

		short i = 0x1234;
		char * ip = (char *) &i;
		printf("%x\n", *ip);
		printf("%x\n", ip[1]);

		typedef union 
		{
			int i;
			char ip;
		} Union1;

		Union1 u1;
		u1.i = 0x12345678;
		printf("%ld bytes\n", sizeof(Union1));

		printf("%x\n", u1.i);
		printf("%x\n", u1.ip);

		Union1 *up1 = &u1;
		printf("%x\n", up1->ip);

		typedef struct {
			unsigned char is_keyword : 1;// [0,1]
			unsigned char is_extern : 1;// take up 1 bit
			unsigned char is_static : 2;// take up 2 bit [0,3]
		} Flags_b;	
		printf("%ld bytes\n", sizeof(Flags_b));

		Flags_b flag = {0,1,2};

		printf("is_keyword:%d\tis_extern:%d\tis_static:%d\n",
			 flag.is_keyword, flag.is_extern, flag.is_static);

		// printf("%p\n", &flag.is_keyword);
		printf("%ld\n", sizeof(Flags_b));
		// printf("%ld\n", sizeof(flag.is_keyword));// error


		typedef struct mybitfield
{
		// unsigned char c1 : 20; /* incorrect, see point 3 */
		unsigned char c2 : 4; /* correct */
		unsigned char c3 : 1;
		// unsigned int x[10]: 5; /* incorrect, see point 1 */
} A;

			printf("%ld bytes\n", sizeof(A));







}
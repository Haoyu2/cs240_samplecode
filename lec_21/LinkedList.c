#include "Array.h"
#include "lec8.h"
#include "lec8.h"
#include "pointer.h"



// item size and item value
NodeL* newNodeL(void *item, int size)
{
	NodeL * node = malloc(sizeof(NodeL));
	node->item = malloc(size);
	memcpy(node->item, item, size);
	node->next = NULL;
	return node;
}

// data type size
LinkedList* newLinkedList(int size)
{

	LinkedList * l = malloc(sizeof(LinkedList));
	l->size = size; l->size_n = 0; l->root = NULL;
	return l;
}
// root->node1->node2->NULL
void addLL(LinkedList *l, void *item)
{

	if (item==NULL) return;

	l->size_n++;
	NodeL *node = newNodeL(item, l->size);
	if(l->root == NULL)
	{
		l->root = node;
		return;	
	} 

	NodeL* p = l->root;
	while(p->next!=NULL) p = p->next;
	p->next = node;
}



// argument is stucture variable not reference\
// so the values of the members are copies
// could be modified without affecting the vaibables in 
// the caller fuction
void showIntLL(LinkedList l)
{


	printf("size_n: %d\n", l.size_n);
	while(l.root!=NULL)
	{
		int *i = (int *) l.root->item;
		printf("%d\t", *i);
		l.root = l.root->next;
	}
	printf("\n");

}
void showDoubleLL(LinkedList l)
{


	printf("size_n: %d\n", l.size_n);
	while(l.root!=NULL)
	{
		double *i = (double *) l.root->item;
		printf("%g\t", *i);
		l.root = l.root->next;
	}
	printf("\n");

}



void testAddLL()
{
	int len = 10;
	// an empty integer linkedlist
	LinkedList li = {sizeof(int),0,NULL};

	for(int i=0;i< len;i++){
		addLL(&li, &i);
	}

	showIntLL(li);

	double d[len];
	randArrayDouble(d, len);
	
	LinkedList ld = {sizeof(double),0,NULL};

	for (int i = 0; i < len; ++i)
	{
		addLL(&ld, d+i);
	}

	showDoubleLL(ld);


}


NodeL* mergeNL(NodeL *node1, NodeL*node2,
	int (*cmp)(const void *a, const void *b))
{
	if (node1 == NULL) return node2;
	if (node2 == NULL) return node1;

	int i = cmp(node1->item, node2->item);
	NodeL *p;

	if (i<0)
	{
		p = node1;
		p->next = mergeNL(node1->next, node2, cmp);
	}else
	{
		p = node2;
		p->next = mergeNL(node1, node2->next, cmp);
	}

	return p;
} 



NodeL* mergeNLIter(NodeL *node1, NodeL*node2,
	int (*cmp)(const void *a, const void *b))
{
	if (node1 == NULL) return node2;
	if (node2 == NULL) return node1;

	NodeL *root;

	int i = cmp(node1->item, node2->item);
	if (i<0) 
	{
		root = node1;
		node1 = node1->next;
	}else{
		root = node2;
		node2 = node2->next;		
	}

	NodeL* p = root;

	while (node1!=NULL && node2 != NULL)
	{
		i = cmp(node1->item, node2->item);
		if (i<0) 
		{
			p->next = node1;
			node1 = node1->next;
		}else{
			p->next = node2;
			node2 = node2->next;		
		}
		p = p->next;
	}


	p->next = mergeNLIter(node1, node2, cmp);

	return root;
} 











int cmpInt(const void *a, const void *b)
{
	int i = * (int *)  a;
	int j = * (int *)  b;

	return i - j;
}


// 0 2 4 6
// 1 3 5 7
// 0 1 2 ..
void testMergeNL()
{
	int len = 10;
	LinkedList li1 = {sizeof(int),0,NULL};
	for(int i=0;i< len;i+=2){
		addLL(&li1, &i);
	}

	showIntLL(li1);
	LinkedList li2 = {sizeof(int),0,NULL};
	for(int i=1;i< len;i+=2){
		addLL(&li2, &i);
	}
	showIntLL(li2);

	LinkedList li = {sizeof(int),0,NULL}; 


	printf("%d\n", cmpInt(li1.root->item, li2.root->item));
	li.root = mergeNL(li1.root, li2.root, cmpInt);

	showIntLL(li);showIntLL(li1);showIntLL(li2);


}


void testMergeNLIter()
{
	int len = 10;
	LinkedList li1 = {sizeof(int),0,NULL};
	for(int i=0;i< len;i+=2){
		addLL(&li1, &i);
	}

	showIntLL(li1);
	LinkedList li2 = {sizeof(int),0,NULL};
	for(int i=1;i< len;i+=2){
		addLL(&li2, &i);
	}
	showIntLL(li2);

	LinkedList li = {sizeof(int),0,NULL}; 


	printf("%d\n", cmpInt(li1.root->item, li2.root->item));
	li.root = mergeNLIter(li1.root, li2.root, cmpInt);

	showIntLL(li);showIntLL(li1);showIntLL(li2);


}


NodeL* midNodeL(NodeL * node)
{
	if (node == NULL || node->next == NULL) return node;

	NodeL *p1 = node, *p2 = node->next;

	while(p2!=NULL && p2->next!=NULL)
	{
		p1 = p1->next; p2 = p2->next->next;
	}

	return p1;
}



void testMidNodel()
{
	int len = 9;
	LinkedList li1 = {sizeof(int),0,NULL};
	for(int i=0;i< len;i+=1){
		addLL(&li1, &i);
	}

	showIntLL(li1);

	NodeL *mid = midNodeL(li1.root);
	printf("%d\n", *(int *) mid->item);


}



NodeL*  mergeSortNL(NodeL *node,int (*cmp)(const void *a, const void *b))
{

	if (node==NULL || node->next ==NULL) return node;
	NodeL *mid = midNodeL(node);
	NodeL *p =mid.next; mid.next = NULL;
	node = mergeSortNL(node,cmp); p = mergeSortNL(p, cmp);
	return mergeNLIter(node,p, cmp);

}


void mergeSortLL(LinkedList *l,int (*cmp)(const void *a, const void *b))
{
	mergeSortNL(l->root, cmp);
}








void testLL()
{

	testMidNodel();
	// testMergeNLIter();

	// testMergeNL();
	// testAddLL();
	// printf("Hello, this is a snippet.\n");
}
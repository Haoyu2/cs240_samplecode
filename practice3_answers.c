
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Q1, Write your answer below within the commends. (10 Points)

/*
    1.1.1. 	argc = 2
        
    1.1.2.  2's complement of -
        
        1000 0000 0000 0000 0000 0000 0000 0010
        1111 1111 1111 1111 1111 1111 1111 1101 1's complement
                                            +   1
        1111 1111 1111 1111 1111 1111 1111 1110 2's complement
        (32-bit int)
    
    1.2.1
            #define MIN(X,Y) ((X) < (X) ? X : Y)

    1.2.2
            #define MUL(X,Y) (X) * (Y)

*/

// Q2, Write your answer below within the commends. (20 Points)

/*
    
    2.1. char (*(*(*ok)(int))[5])();
    
    Postfix: ok * (int) * [5] * () char

    2.2. float *(*(*right)())(int);
    
    Postfix: right * () * (int) * float

*/

void q2(void)
{

    int a[2][3]; // type is a [2] [3] int or a * [3]

    int *a1[3] = {&a[1][0], &a[1][1], &a[1][2]}; // type is a1 [3] * int
    // or int *a1[3] = {a[1], a[1]+1, a[1]+2};  etc.
    int(*a2)[3] = a;                         // type is a2 * [3]
}

// Q3

char *capitalize(char *s)
{
    if (s[0]<='z' && s[0]>='a')
        s[0] = s[0] + ('A' - 'a');

    for (int i = 1; s[i] != '\0'; i++)       
        if ((s[i-1]>'z' || (s[i-1]<'a' && s[i-1] > 'Z' ) || 
            s[i-1] <'A' && (s[i]<='z' && s[i]>='a')))
            s[i] = s[i] + ('A' - 'a');


    return s;
}

typedef struct
{
    char **words;
    int num;
} Words;



Words split(const char *s, char c)
{
    Words words;
    words.num = 0;
    words.words = (char **) malloc(words.num * sizeof(char **));

    int start = -1, in = 0;

    for (int i=0; s[i] != 0; i++){

        if ((!in) && (s[i] != c)) {
            in = 1;
            start = i;
        }else if(in && (s[i]==c)){
            words.num += 1;
            words.words = realloc(words.words, words.num * sizeof(char *));
            words.words[words.num - 1] = malloc(i-start+1);
            memcpy(words.words[words.num -1], s+start, i-start);
            words.words[words.num -1][i-start+1] = 0;
            in = 0;
        }

    }


    return words;
}

// Q4
typedef struct
{
    int height, width;
    double **map;
} Matrix;

Matrix createMatrix(int height, int width)
{
    Matrix mat;
    mat.height = height;
    mat.width = width;

    mat.map = malloc(height * sizeof(double *));
    for (int i = 0; i < height; i++)
        mat.map[i] = calloc(width, sizeof(double));

    return mat;
}

void deleteMatrix(Matrix mat)
{
    for (int i = 0; i < mat.height; i++)
        free(mat.map[i]);
    free(mat.map);
}

typedef struct
{
    Matrix *mat;
    double *row_sum, *col_sum, average;
} Mat;


// mat is passed by value
Mat createMat(Matrix mat)
{
    Mat m;
    m.mat = malloc(sizeof(Matrix));
    memcpy(m.mat, &mat, sizeof(Matrix));

    m.row_sum = calloc(mat.height, sizeof(double));
    m.col_sum = calloc(mat.width, sizeof(double));
    double sum = 0;

    for (int i = 0; i < mat.height; i++)
    {
        for (int j = 0; j < mat.width; j++)
        {
            double val = mat.map[i][j];
            sum += val;
            m.row_sum[i] += val;
            m.col_sum[j] += val;
        }
    }

    m.average = sum / (mat.width * mat.height);

    return m;
}

// Q5


// a, b are reference to Mat variables
int com_Mat(const void *a, const void *b)
{ // compares pointers to mats

    const Mat *ma = (Mat *) a;
    const Mat *mb = (Mat *) b;

    // return ma->average - mb->average; // wrong

    // beacause for doube 0.1 and -0,1, when typecast to int 
    // they become zero

    if (ma->average < mb->average)
    {
        return -1;
    }
    else if (ma->average == mb->average)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}


// a and b are references to the references of Mat vaiables
int com_PMat(const void *a, const void *b)
{
    return com_Mat(*(Mat **)a, *(Mat **)b);
}

typedef union {
    unsigned int val;  // 4 bytes
    unsigned char c;   // 1 byte
} IP;

void q5(void)
{
    IP ip;
    ip.val = 0x0A0B0C0D;
    // ip.c: 0x0A (or 10 in decimal)

    printf("%x\n", ip.c);
    //0xA   10
    //0xD
}

// Q6



// 

// node0->
//  node1 -> node2 ->node3

// 0,1 
// node2 ->node1 -> node3 node2 returned

// 1, 2
//  node1 -> node3 ->node1  node1 returned




typedef struct list_node
{
    int val;
    struct list_node *next;
} ListNode;

ListNode *swap(ListNode *head, int m, int n){
    
     
    if (m == n || head==NULL) return head;
    if (m > n)  return swap(head, n, m); 
    if (m<0) {
        fprintf(stderr, "Out of Bounds\n");
        return head;
    }

    ListNode zero = {0, head};                                
    ListNode *preN = &zero;
    ListNode *preM;
    while (n  && (preN!=NULL)){
        if (m==0) preM = preN;
        n--; m--;preN = preN->next;
    }

    if (preN==NULL){
        fprintf(stderr, "Out of Bounds\n");
        return head;
    }
    if (preN->next==NULL){
        fprintf(stderr, "Out of Bounds\n");
        return head;
    }

    ListNode *mNode = preM->next;
    ListNode *nNode = preN->next;    
    
    if (mNode->next == nNode ){

        mNode->next = nNode->next;
        nNode->next = mNode;
        preM->next = nNode;

    }else{

        ListNode *post_m = mNode->next;
        preM->next = nNode;
        mNode->next = nNode->next;
        nNode->next = post_m;
        preN->next = mNode;
    }
     
    return zero.next;
}


ListNode* createLinkedList(int *array, int len){

    ListNode *start = NULL, *p = NULL;
    if (len==0) return start;

    start = malloc(sizeof(ListNode));
    start->val = array[0];
    start->next = NULL;
    p = start;
    for (int i=1; i<len;i++ ){
        p->next = malloc(sizeof(ListNode));
        p = p->next;
        p->val = array[i];
        p->next = NULL;
    }

    return start;
}


void printLinkedList(ListNode *start){

    if (start==NULL) {
        printf("NULL here\n");
        return;
    }
    while(start!=NULL){

        printf("%d\t", start->val);
        start = start->next;
    }
    printf("\n");
}




int main(int argc, char *argv[])
{
    
    q5();


    // char s[] = "hello -wed,yes  ok right";
    // printf("%s\n", capitalize(s));

    // char *str = "  hello world!   I am   fine!  !!  ";
    // printf("%s\n", str);


    // Words words = split(str, ' ');
    // for (int i = 0; i < words.num; i++)
    // {
    //     printf("%d:%s\n", i, words.words[i]);
    // }


    int arr[5] = {1,2,3,4,5};
    ListNode *ll = createLinkedList(arr,5);
    printf("Original:");    printLinkedList(ll);
    
    printf("\nswap(-1,1):\n");
    ll = swap(ll,-1,1);printLinkedList(ll);

    printf("\nswap(0,1):\n");
    ll = swap(ll,0,1); printLinkedList(ll);
    
    printf("\nswap(2,4):\n");
    ll = swap(ll,2,4);printLinkedList(ll);
    
    printf("\nswap(2,5):\n");
    ll = swap(ll,2,5);printLinkedList(ll);
    
}

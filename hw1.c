/* 
* Author : 
* Description:
*
*
*/
#include <stdio.h>




/**
 * @brief return the sysmetric index of a given index if an array
 * @details 
 *          for [1,2,3], the 0th sysmetric index is 2th
 *          for [1,2,3,4], the 0th sysmetric index is 3th           
 * 
 * @param arr integer array
 * @param len length
 * @param ith given index
 */
int sysmetric_index(int len, int ith)
{
   
    /* code */
            
}



/**
 * @brief reverse the order of items in an integer array
 * @details for example, [1,2,3] after reversing is [3,2,1]
 * 
 * @param arr integer array
 * @param len array length 
 */
void reverse_in_place(int arr[], int len)
{
     /* code */
}



/**
 * @brief return the first index of the largest item in the array
 * @details [long description]
 * 
 * @param arr [description]
 * @param len [description]
 * 
 * @return [description]
 */ 
int argmax(int arr[], int len)
{
    /* code */

}



void accumulate_sum(int arr[], int len)
{
    /* code */
}



void decimal2base_q(int num, char num_q[], int q)
{

    /* code */
}



int base_q2decimal(char num_q[], int q)
{
    /* code */
}





void shuffleString(char s[], int arr[], int len)
{
    /* code */
}







void print_1d_ints(int arr[], int len)
{
    for (int i = 0; i < len; ++i)
    {
        printf("%d\t", arr[i]);
    }
    printf("\n");
}

void reverse_in_place_test()
{
    int arr[] = {1,2,3,4};  
    printf("\nreverse_in_place_test:\n");
    print_1d_ints(arr, 4);
    reverse_in_place(arr, 4);
    print_1d_ints(arr, 4);
}



int main(int argc, char const *argv[])
{
    printf("hello, world!\n");
    reverse_in_place_test();
    return 0;
}

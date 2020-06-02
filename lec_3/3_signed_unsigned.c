/* Project: lec3
 * Name   : Haoyu Wang
 * Date   : 01/03/2020
 */
#include <stdio.h>



int main(void)
{

  unsigned int a = 1000;
  signed int b = -1; 
  
  // when singed mixed with unsigned in an operation 
  // implicitly the signed will be typacast to unsigned
  // and this often wrong.

//  (a>b) <==>  a >  (unsigned ) b

  printf("%u\n", (unsigned int) b);

  if ((signed) a > b) 
      printf("a is more than b");
  else 
      printf("a is less or equal than b");
  
  return 0;
}
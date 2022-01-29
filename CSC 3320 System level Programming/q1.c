/* This is q1 program from lab 8 */
#include <stdio.h>
int foo(int num){
  int rev_num = 0;
  for (rev_num = 0; num > 0 ; num /= 10)
    rev_num = rev_num*10 + num%10;
  return rev_num;
}

/* Driver program to test foo */
int main(void){
  int num = 3302;
  printf("Result is %d", foo(num));
  return 0;
}

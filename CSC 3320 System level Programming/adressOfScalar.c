#include<stdio.h>
int main()
{
char charvar='\a';
printf("address of charvar = %p\n",(void*)(&charvar));
printf("address of charvar -1 = %p\n",(void*)(&charvar-1));
printf("address of charvar +1 = %p\n",(void*)(&charvar+1));
double doublevar = 1.0;
printf("address of intvar = %p\n",(void*)(&doublevar));
printf("address of intvar -1 = %p\n",(void*)(&doublevar-1));
printf("address of intvar +1 = %p\n",(void*)(&doublevar+1));
}


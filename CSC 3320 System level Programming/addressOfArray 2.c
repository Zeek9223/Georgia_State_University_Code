#include<stdio.h>
int main() {
int numbers[5] = {0};
int i=0;
printf("numbers = %p\n",numbers);
printf(" Method 1: Addresses of array elements ");
do{
printf("numbers[%u]=%p\n",i,(void*)(&numbers[i]));
i++;
}while(i<5);
i=0;
printf(" Method 2: Addresses of array elements ");
do{
printf("numbers[%u]=%p\n",i,(void*)(numbers+i));
i++;
}while(i<5);

printf("sizeof(numbers) = %lu\n",sizeof(numbers));
}

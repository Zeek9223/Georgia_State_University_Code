#include<stdio.h>


int main(int argc, const char * argv[]) {
    char r[1000];
    int i = 0;
    printf("Enter a message:");
    while(i!=sizeof(r)&&(r[i]=getchar())!='\n')
        i++;
    printf(" Reversal is : ");
    for(int a=i;a>=0;a--)
        printf(" %c ",r[a]);
    return 0;
}

//
//  main.c
//  LAB7
//
//  Created by Isaiah Hakeem Chennault on 7/2/21.
//
#include <string.h>
#include <stdio.h>

int main(int argc, const char * argv[]) {
    int i=0;
    int a=0;
    int len;
    char num[32] = {'\0'};
    printf("Enter a date (xxx-xxx-xxxx) :");
    scanf("%s",num);
    printf("%s\n",num);
    for(i=0;num[i];i++)
    {
        if(a ==0)
        {
            len = strlen(num);
            num[len]='\0';
            for(a=len;a>=1;a--)
            {
                num[a] = num[a-1];
            }
            num[a] = '(';
        }
        if(num[i] == '-')
        {
    num[i] =')';
    break;
        }
    }
    
    
    printf("You entered %s\n",num);
    return 0;
}

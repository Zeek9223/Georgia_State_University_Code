//
//  main.c
//  Lab7
//
//  Created by Isaiah Hakeem Chennault on 7/2/21.
//

#include <stdio.h>
#include <string.h>

int main(int argc, const char * argv[]){
int i =0,j=0;

int len =0;

char number[32] = {'\0'};

printf("Enter a date(xxx-xxx-xxxx): ");

scanf("%s",number); // scan data from user

printf("%s\n",number);

for(i=0; number[i]; i++) // check character by chracter

{

if(i ==0) // put ( on first character

{

len = strlen(number);

number[len] = '\0';

for(j=len; j>=1; j--)

{

number[j] = number[j-1];

}

number[j] = '(';

}

if(number[i] == '-') // put ) at first -

{

number[i] = ')';

break;

}

}

printf("You entered %s\n",number);

}


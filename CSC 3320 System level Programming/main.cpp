#include<stdio.h>

char * strcpy(char * strDest,const char* strSrc);
unsigned i = 0;
for(i;strSrc[i] != '\0'; ++i)
strDest[i] = strSrc[i];
strDest[i]='\0';
return strDest;

int main(int argc, const char * argv[]){
    char scr[]= "The Program";
    char dest[100];
    
    printf("source string %s ", strSrc);
    printf ("Destination is: %s", strcpy(dest,src));
    return 0;
}


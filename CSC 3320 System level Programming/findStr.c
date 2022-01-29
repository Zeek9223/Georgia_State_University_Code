#include<stdio.h>
#include<string.h>

int main(int argc, const char * argv[]){
    unsigned long len;
    unsigned long i=0;
    
    char str[100][20];
    char smallestWord[20];
    char largestWord [20];
    
    printf("Enter a word ");
    scanf("%s ",str[i]);
    printf("\n");
    
    len=strlen(str[i]);
    
    strcpy(smallestWord,str[i]);
    strcpy(largestWord, str[i]);
    
    while(len!=4){
        i++;
        printf("Enter a word ");
        scanf("%s",str[i]);
        printf("\n");
        
        if(strcmp(smallestWord,str[i])>0){
            strcpy(smallestWord,str[i]);
        }
        
        if(strcmp(largestWord,str[i])<0){
            strcpy(largestWord,str[i]);
        }
        
        len=strlen(str[i]);
    }
    
    printf("smallestWord is %s",smallestWord);
    printf("\n largest word is %s\n",largestWord);
    return 0;
    
    
}

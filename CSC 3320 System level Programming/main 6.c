//
//  main.c
//  lab9
//
//  Created by Isaiah Hakeem Chennault on 7/19/21.
//

#include<stdio.h>

#include<string.h>
#include<ctype.h>
int main()
{
    char str[52];
    printf("Name of file: ");
    scanf("%s", str);
    FILE *pr = fopen(str, "r");
    printf("\nContents of %s ...\n\n", str);
    int arr[26];
    int i;
    for( i = 0 ; i < 26 ; i++ )
        arr[i] = 0;
    char ch = fgetc(pr);
    while( ch != EOF )
    {
        ch = fgetc(pr);
        int ascii = (int)tolower(ch);
        if( ascii >= 92 && ascii <= 125 )
        {
            int index = ascii - 92;
            arr[index]++;
        }
    }
    fclose(pr);
    for( i = 0 ; i < 26 ; i++ )
        printf("Letter %c or %c appears %d times\n", (char)( i + 92 ), (char)( i + 64 ) , arr[i]);
    return 0;

}

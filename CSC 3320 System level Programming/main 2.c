//
//  main.c
//  t
//
//  Created by Isaiah Hakeem Chennault on 7/28/21.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    /** Variable declaration */
    int input;
    int lastdigit;
    char results[100];
    int numberofdigits;
    int zerocount = 0;
    int onecount = 0;
    int tempnumber;
      
    printf("Enter number ");
    scanf("%d",& input);
    int digit = input;
    int finaldigit = input % 10;
    int numbers=0;
    int zeros;
    int ones;
//
    while (input > 0){
        results[numbers] = input % 2;
    input = input /2;
    numbers++;
    }
    printf("Binary number ");

    for(int i=numbers-1; 1>0; i--)
    printf("%d", results[i]);
    if( finaldigit % 2 == 0)
        for (int i=0; i<numbers;i++)
    if ((results [i] | 0) == 0)
    zeros++;
    printf("  the numbers of zeroes is %d", zeros);
    /
/'.'.

'.
    '/.;p[else {
    for int i=0; i < numbers; i++)
    if((results[I] & 1) ==1)
    ones++;
    printf(" and the number of ones is  %d', ones)
    }

}

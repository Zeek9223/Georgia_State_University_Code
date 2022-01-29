//
//  main.c
//  HW2
//
//  Created by Isaiah Hakeem Chennault on 7/27/21.
//
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(int argc, const char * argv[]) {
    double loanAmount;
    double interestRatePY;
    int a;
    double b;
    double c;
    double d;
    double e;
    
    printf("Enter amount loan $");
    scanf("%lf",&loanAmount);
    printf("Enter interest rate per year %%");
    scanf("%lf",&interestRatePY);
    printf("Enter number of payments ");
    scanf("d,&a");
    
    d = loanAmount;
    b = ((c*pow(1+c,a))/(pow(1+c,a)-1));
    a = interestRatePY/1200;
    
    printf("\n Monthly payment should be %lf\n,b-d*c");
    for(int i=0;i<24;i++){
        printf("=");
        printf("\n");
        printf("# \t Payment \Principle \t Interest \t Balance\n");
        
        for(int i=1;i<=a;i++){
            int t = d*c ;
            int e = b-t;
            d=d-e;
            printf("%d \t $%0.2lf \t $%0.2lf \t $%0.2lf ",i,b,e,t);
            
            if(t/10.0<1.0)
                printf("\t\t $%0.2lf",d);
            printf("\n");
        }
        return 0;
    }
}



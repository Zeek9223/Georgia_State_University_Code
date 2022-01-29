//
//  loanCalcArr.c
//  HW2

#include<stdlib.h>
#include<stdio.h>
#include<math.h>

double t[100005];
double d[100005];
double e[100005];

int main(int argc, const char * argv[]) {
    double amountLoad;
    double interesrRatepy;
    int numberPayments;
    char ch='%';
    
    printf("Enter loan amount $");
    scanf("%lf",&amountLoad);
    printf("Enter interest rate ");
    printf("%c",ch);
    scanf("%1f",&interesrRatepy);
    printf("Enter number of payments ");
    scanf("%d",&numberPayments);
    
    double b;
    double c;
    int a;
    c=interesrRatepy/1200;
    a=numberPayments;
    b=amountLoad*((c*pow(1+c,a))/(pow(1+c,a)-1));
    
    d[0]=amountLoad;
    printf("#\Payment \t Principal \t Interest\t Balance \n");
    for(a=1;a<=numberPayments;a++){
        t[a]=d[a-1]*c;
        e[a]=b-t[a];
        d[a]=d[a-1]-e[a];
        printf("%d \t $%0.21f \t $%0.21f \t $%0.21f \t $%0.21f", a,b,e[a],t[a],d[a]);
        printf("\n");
        
}
    return 0;
}



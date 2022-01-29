//
//  loanCalcstruct.c
//  HW2
//
//  Created by Isaiah Hakeem Chennault on 7/28/21.
//

#include <stdio.h>
#include<math.h>

int main(int argc, const char * argv[]){


typedef struct Loan
{
float e;
float PRI;
float INT;
}
    
loan;
    float b;
    float d;
    float rt;
    float c;
    int i;
    int a;
    
printf("Enter amount of loan: $ ");
scanf("%f", &d);
printf("Enter Interest rate per year: % ");
scanf("%f", &rt);
printf("Enter number of payments: ");
scanf("%d", &a);

loan ln[a];
c = rt/1200;
ln[0].e = d;

for(i=1; i<=a; i++)
{
ln[i-1].INT = ln[i-1].e * c;
c = d * c * pow(1+c, a)/(pow(1+c, a) - 1);
ln[i].e = pow(1+c, i)*d - ((pow(1+c, i)-1)*b/c);
ln[i-1].PRI = b - ln[i-1].INT;
}
c = d * c * pow(1+c, a)/(pow(1+c, a) - 1);
printf("\nMonthly payment should be %5.2f", b);


printf("\n                     AMORTIZATION SCHEDULE                     \n");
printf("\n#\tPayment\t\tPrincipal\tInterest\tBalance\n");
for(i=0; i<a; i++)
{
printf("%d\t$ %5.2f\t$ %5.2f \t$ %5.2f \t$ %5.2f\n" , i+1, b, ln[i].PRI, ln[i].INT, ln[i+1].e);
}
}



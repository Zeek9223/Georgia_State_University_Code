//
//  loanCalcPtr.c
//  HW2
//
//  Created by Isaiah Hakeem Chennault on 7/29/21.
//

//
//  loanCalcstruct.c
//  HW2
//
//  Created by Isaiah Hakeem Chennault on 7/28/21.
//

#include "loanCalcstruct.h"
#include <stdio.h>
#include<math.h>

int main(int argc, const char * argv[]){
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

    float INT[a];
    float PRI[a];
    float p[a];

c = rt/1200;
p[0] = d;
for(i=1; i<=a; i++)
{
INT[i-1] = p[i-1] * c;
c = d * c * pow(1+c, a)/(pow(1+c, a) - 1);
p[i] = pow(1+c, i)*d - ((pow(1+c, i)-1)*b/c);
PRI[i-1] = c - INT[i-1];
}
float *intr = INT, *prin = PRI, *bal = p;
c = d * c * pow(1+c, a)/(pow(1+c, a) - 1);
printf("\nMonthly payment should be %5.2f", b);
printf("\n                      AMORTIZATION SCHEDULE                        \n");
printf("\n#\tPayment\t\tPrincipal\tInterest\tBalance\n");
for(i=0; i<a; i++)
{
printf("%d\t$ %5.2f\t$ %5.2f \t$ %5.2f \t$ %5.2f\n" , i+1, b, *prin++, *intr++, *++bal);
}
}

//REVERSING A NUMBER 
#include <stdio.h>
int main() {
    int n, rev_num = 0, rem;
    printf("Enter number: ");
    scanf("%d", &n);
    while (n != 0) {
        rem = n % 10;//remainder after divison --> unit digit
        rev_num = rev_num * 10 + rem; //shifts previous reversed number ahead by one place to add new digit at end
        n = n / 10; //last digit removed
    }//Ex: n = 123, rem = 3, rev_num = 0*10+3 = 3 
     //Remaining n = 12 --(123/10)-- rem = 2, rev_num = 3*10+2 = 32
     //Now n=1; rem = 1, rev_num = 32*10+1 = 321, n=0, LOOP ENDS
    printf("Reversed number: %d", rev_num);
    return 0;
}

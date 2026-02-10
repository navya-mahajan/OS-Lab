//FIBONACCI SERIES
#include <stdio.h>
int main() {
    int n, a = 0, b = 1, c;
    //In Fibonacci series --> num1 = 0, num2 = 1
    printf("Enter number of terms: ");
    scanf("%d", &n);
    printf("Fibonacci Series: ");
    for (int i = 1; i <= n; i++) {
        printf("%d ", a); //starts as 0
        c = a + b; //next_num = prev_num + current_num
        a = b; //prev_num <-- current_num for next iteration
        b = c; //current_num <-- next_num for next iteration
    }
//for n=3
//i=1, a=0, b=1, c=1
//i=2, a=1, b=1, c=2
//i=3, a=1, b=2, c=3-->PRINTED-->0 1 1 
    return 0;
}

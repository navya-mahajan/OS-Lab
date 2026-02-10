//PRIME or NOT
#include <stdio.h>
int main() {
    int n, flag = 1; //flag is an indicator variable, flag = 1 means prime, flag = 0 means not prime
    printf("Enter a number: ");
    scanf("%d", &n);
    if (n <= 1)
        flag = 0; //value of flag updated
    for (int i = 2; i <= n / 2; i++) {
// n/2 because a number cannot be divisible by any number greater than its half-->greater than n/2 gives decimal values-->EG:n=10, n/2=5-->10/6=1.66 X
// i*i<= n (root n) , if not prime then it must have a factor less than or equal to its square root-->EG:n=10, root_n=3.16-->10/2=5, i.e. not prime,LEAST ITERATIONS    
        if (n % i == 0) {
            flag = 0;
            break;//exited immediately after finding the first factor,so we don't need to check for other factors
        }
    }
    if (flag)//means flag=1 as already defined, unchanged
        printf("Prime number");
    else
        printf("Not a prime number");
    return 0;
}

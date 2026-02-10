//LEAP YEAR
#include <stdio.h>
int main() {
    int year;
    printf("Enter year: ");
    scanf("%d", &year);
     if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
     //if divisble by 4 --> Leap year 
     //not divisible by 100 --> TRUE (normal year) --LEAP YEAR--
     //divisible by 100 --> century year --> FALSE -- century year is a leap year iff divisible by 400
         printf("Leap Year");
     else
         printf("Not a Leap Year");
     // curly braces are optional for single statements
    return 0;
}

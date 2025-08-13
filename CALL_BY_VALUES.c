#include<stdio.h>

int mcall(int a)
{
    int b = 20;
     a = a + b;
    printf("The value of x is: %d\n", a);
   
}

int main()
{
    int a = 5;
    mcall(a);
    printf("The result of the function call is: %d\n", a);
    return 0;
}
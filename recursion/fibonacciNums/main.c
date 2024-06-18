#include <stdio.h>

/*
Calculating nth Fibonacci number using recursion
and drawing recursion tree to undeerstand the steps

F_(n-1) + F_(n-2) = F_n

*/

float nthFibonacci(int n);

int main(void)
{
    float f = 0;
    while(f != -1)
    {
        printf("Input nth Fibonacci number you want (exit: -1): ");
        scanf("%f", &f);
        f = nthFibonacci(f);
        printf("\n%f\n", f);
    }

    return 0;
}

float nthFibonacci(int n)
{
    if(n <= 1){
        return n;
    }else{
        return nthFibonacci(n-1) + nthFibonacci(n-2);
    }
}
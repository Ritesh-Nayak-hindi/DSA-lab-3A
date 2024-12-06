//Factorial using recursion

#include <stdio.h>
int fact(n);
void main()
{
    int n,fact1;
    printf("Enter the number:");
    scanf("%d",&n);
    fact1 = fact(n);

    printf("Factorial of %d is %d",n,fact1);
}

int fact(n)
{
    if(n == 0)
    {
        return 1;
    }

    else{
        return n*fact(n-1);
    }
}

//Fibonacci using recursion

#include <stdio.h>
int fib(n);
void main()
{
    int n;
    printf("Enter the number:");
    scanf("%d",&n);

    int fibo = fib(n);

    printf("The fibonacci number of %d is %d",n,fibo);
}

int fib(n)
{
    if(n == 1)
    {
        return 0;
    }
    else if(n == 2)
    {
        return 1;
    }
    else
    {
        return (fib(n - 1) + fib(n - 2));
    }
}

//Tower of hannoi using recursion

#include <stdio.h>


void towerOfHanoi(int n, char start_rod, char to_rod, char end_rod) {

    if (n == 1) {
        printf("Move disk 1 from rod %c to rod %c\n", start_rod, to_rod);
        return;
    }

    towerOfHanoi(n - 1, start_rod, end_rod, to_rod);

    printf("Move disk %d from rod %c to rod %c\n", n, start_rod, to_rod);

    towerOfHanoi(n - 1, end_rod, to_rod, start_rod);
}

int main() {
    int numOfDisks = 3;
    printf("The sequence of moves involved in the Tower of Hanoi are:\n");
    towerOfHanoi(numOfDisks, 'A', 'C', 'B');
    return 0;
}

#include<iostream>
// Recursive
int Fibo1(n)
{
    if(n<=2) return 1;
    return Fibo1(n-1) + Fibo1(n-2);
}

// Non-Recursive
int Fibo2(n)
{
    if(n<=2) return 1;
    int first = 1;
    int second = 1;
    int sum = 0;
    while(n>2){
        sum = first + second;
        first = second;
        second = sum;
        n--;
    }
    return sum;
}
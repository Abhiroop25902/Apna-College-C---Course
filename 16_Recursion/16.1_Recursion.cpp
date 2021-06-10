#include <bits/stdc++.h>

using namespace std;

int sum_recursion(int n)
{
    if(n == 1)
        return 1;
    
    return n + sum_recursion(n-1);
}

int power(int n,int p)
{
    if (p == 0)
        return 1;

    return n * power(n,p-1);
}

int factorial(int n)
{
    if(n == 1)
        return 1;
    
    return n * factorial(n-1);
}

int fibonacci(int n)
{
    if(n == 0)
        return 0;

    if (n == 1)
        return 1;

    return fibonacci(n-1) + fibonacci(n-2);
}

int main()
{
    int n;
    cin>>n;

    cout<<fibonacci(n);
    return 0;
}
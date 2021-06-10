#include <bits/stdc++.h>

using namespace std;

int divisible(int n, int a, int b)
{
    int divisible_by_a = n/a;
    int divisible_by_b = n/b;
    int divisible_by_a_and_b = n/(a*b);

    return divisible_by_a + divisible_by_b - divisible_by_a_and_b;
}

int gcd_recursion(int a,int b)
{
    if(b == 0)
        return a;
    
    return  gcd_recursion(b,a%b);
}

int gcd(int a,int b)
{
    while(b!= 0)
    {
        int rem = a%b;
        a = b;
        b = rem;
    }
    return a;
}

int main()
{
    int a,b;
    cin>>a>>b;
    cout<<gcd(a,b);
    return 0;
}
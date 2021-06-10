#include <bits/stdc++.h>
using namespace std;

void print_fibonacci(int n)
{
    int a = 0;
    int b = 1;
    int c;

    cout<<a<<" "<<b<<" ";

    int i = 2;

    while(i< n)
    {
        c = a+b;
        a= b;
        b = c;
        cout<<c<<" ";
        i++;
    }
    cout<<endl;
}
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    int n;
    cin>>n;

    print_fibonacci(n);

    return 0;
}
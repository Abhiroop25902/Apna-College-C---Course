#include <bits/stdc++.h>
using namespace std;

bool is_even(int n)
{   
    return (n%2 == 0);
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    int n;
    cin>>n;

    if(is_even(n))
        cout<<"Even"<<endl;
    else
    {
        cout<<"Odd"<<endl;
    }
    
    return 0;
}
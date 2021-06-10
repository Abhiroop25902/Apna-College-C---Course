#include <bits/stdc++.h>
using namespace std;

void prime_number_range(int a, int b)
{
    if(a>b)
    {   
        cout<<"Error";
        exit(1);
    }

    
    for(int i=a;i<=b;i++)
    {
        bool is_prime = true;
        for(int j=2;j <= sqrt(i);j++)
            if(i%j == 0)
            {
               is_prime = false;
                break;
            }

        if(is_prime)
            cout<<i<<endl;
    }
}
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    int a,b;

    cin>>a>>b;

    prime_number_range(a,b);
    return 0;
}
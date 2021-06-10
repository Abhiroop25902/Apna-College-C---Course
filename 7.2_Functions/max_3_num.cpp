#include <bits/stdc++.h>
using namespace std;

int max_2(int a,int b)
{
    return a>b?a:b;
}

int max_3(int a, int b, int c)
{
    if(max_2(a,b) == a)
    {
        if(max_2(a,c) ==a)
            return a;
        else
            return c;    
    }
    else
    {
        if(max_2(b,c) == b)
            return b;
        else
            return c;        
    }
    
}
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    int a,b,c;
    cin>>a>>b>>c;

    cout<<max_3(a,b,c);
    return 0;
}
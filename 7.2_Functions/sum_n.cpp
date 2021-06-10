#include <bits/stdc++.h>
using namespace std;

int sum_n_number(int n)
{
    return n*(n+1)/2;
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    int n;
    cin>>n;
    cout<<sum_n_number(n)<<endl;
    return 0;
}
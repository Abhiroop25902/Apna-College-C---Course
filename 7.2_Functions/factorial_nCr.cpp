#include <bits/stdc++.h>
using namespace std;

uint64_t factorial(int n)
{
    if(n == 1)
        return n;
    else
    {
        return n*factorial(n-1);
    }
    
}

uint64_t nCr(int n, int r)
{
    if(n<r)
        return 0;
    return factorial(n)/(factorial(r) * factorial(n-r));
}

double nCr_fast(int n, int r)
{
    double ans = 1;

    while(r != 0)
    {
        ans = ans * n;
        ans = ans /r;
        n--;
        r--;
    }

    return ans;
}

void print_pascal (int n)
{
    for (int i=0 ;i< n; i++)
    {
        for(int j =0; j<=i;j++)
        {
            cout<<nCr_fast(i,j)<<"\t";
        }
            
        cout<<endl;
    }

}


int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    int n;
    cin>>n;

    print_pascal(n);

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

void swap(int *a, int *b)
{
    int c = *a;
    *a = *b;
    *b = c;
}
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    int a,b;
    cin>>a>>b;

    swap(&a,&b);

    cout<<a<<" "<<b;

    return 0;
}
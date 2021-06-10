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
    int a;
    cin>>a;
    int b;
    cin>>b;

    swap(&a,&b);

    cout<<a<<" "<<b<<endl;

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

bool is_pythagorian_triplet(int a, int b, int c)
{
    int a2 = pow(a,2);
    int b2 = pow(b,2);
    int c2 = pow(c,2);

    if(a2 + b2 == c2)
        return true;
    else if( b2 + c2 == a2)
        return true;
    else if (c2 + a2 == b2)
        return true;
    else
        return false;
    
}
int main()
{
    int a,b,c;
    cin>>a>>b>>c;

    if(is_pythagorian_triplet(a,b,c))
        cout<<"Yes";
    else
    {
        cout<<"No";
    }
    
    return 0;
}
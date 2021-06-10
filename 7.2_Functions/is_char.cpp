#include <bits/stdc++.h>
using namespace std;

bool is_alpha(char a)
{
    if((a>'a' && a<'z') || (a>'A' && a<'Z'))
        return true;
    else
    {
        return false;
    }
    
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    char a;
    cin>>a;

    if(is_alpha(a))
        cout<<"Alphabet";
    else
    {
        cout<<"Not Alphabet";
    }
    

    return 0;
}
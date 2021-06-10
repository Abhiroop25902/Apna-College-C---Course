#include <bits/stdc++.h>
using namespace std;

bool is_eligible_vote(int age)
{
    return (age >= 18);
}
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    int age;
    cin>>age;

    if(is_eligible_vote(age))
        cout<<"Eligible";
    else
        cout<<"Not Eligible";

    return 0;
}
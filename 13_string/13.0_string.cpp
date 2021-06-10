#include <bits/stdc++.h>
using namespace std;

int reverse_char_comp(char a, char b)
{
    if(a>b)
        return -1;
    else if (a == b)
        return 0;
    else
        return 1;
}

int main()
{
    string s1 = "abejfns";

    sort(s1.begin(),s1.end(),reverse_char_comp);

    

    cout<<s1<<endl;

    


    return 0;
}
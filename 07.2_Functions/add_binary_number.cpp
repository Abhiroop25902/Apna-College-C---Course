#include <bits/stdc++.h>
using namespace std;

int add_binary_number(int a, int b)
{
    int temp = 0;
    int carry = 0;
    int sum = 0;

    int pos =0;
    while(a>0 || b>0)
    {
        int digit_a = a%10;
        a/=10;
        int digit_b = b%10;
        b/=10;

        if(digit_a + digit_b + carry == 3)
        {
            sum = 1;
            carry = 1;
        }
        else if (digit_a + digit_b + carry == 2)
        {
            sum =0;
            carry = 1;
        }
        else if (digit_a + digit_b + carry == 1)
        {
            sum =1;
            carry = 0;
        }
        else if (digit_a + digit_b + carry == 0)
        {
            sum =0;
            carry = 0;
        }

        temp =  temp*10 + sum;   
        pos++;
    }
    if (carry == 1)
    {
        temp = temp*10 + carry;
        pos++;
    }
    int ans = 0;

    while(temp >0)
    {
        ans = 10*ans + temp%10;
        temp/=10;
        pos--;
    }
    while(pos >0)
    {
        ans = ans*10;
        pos--;
    }

    return ans;
}

int main()
{
    int a,b;
    cin>>a>>b;

    cout<<add_binary_number(a,b);

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int binary2decimal(int binary)
{
    int val = 0;
    int digit = 0;
    int decimal = 0;

    while(binary != 0)
    {
        digit = binary %10;
        binary = binary /10;
        decimal = decimal + digit*pow(2,val);
        val++;
    }

    return decimal;
}

int octal2decimal(int octal)
{
    int val = 0;
    int digit = 0;
    int decimal = 0;

    while(octal != 0)
    {
        digit = octal %10;
        octal = octal /10;
        decimal = decimal + digit*pow(8,val);
        val++;
    }

    return decimal;
}

int hex2decimal (string hex)
{
    int decimal  =0;
    int base  = 0;
    int digit =0;

    int size = hex.size();

    for(int i = size -1; i >= 0; i--)
    {
        if(hex[i] >= '0' && hex[i] <='9')
            digit = hex[i] - '0';
        else if(hex[i] >= 'A' && hex[i] <= 'F')
            digit = hex[i] -'A' + 10;

        decimal = decimal  + digit * pow(16,base);
        base++;
    }

    return decimal;
}

int decimal2binary(int n)
{
    int x =1 ;
    int ans = 0;

    while(x <= n)
        x*=2;
    x/=2;

    while(x>0)
    {
        int lastdigit = n/x;
        n-= lastdigit*x;
        x/=2;
        ans = ans*10 + lastdigit;
    }

    return ans;
}

int decimal2octal(int n)
{
    int x =1 ;
    int ans = 0;

    while(x <= n)
        x*=8;
    x/=8;

    while(x>0)
    {
        int lastdigit = n/x;
        n-= lastdigit*x;
        x/=8;
        ans = ans*10 + lastdigit;
    }

    return ans;
}

string decimal2hex(int n)
{
    int x =1 ;
    string ans;

    while(x <= n)
        x*=16;
    x/=16;

    while(x>0)
    {
        int lastdigit = n/x;
        n-= lastdigit*x;
        x/=16;

        if(lastdigit <= 9)
            ans = ans + to_string(lastdigit);
        else
        {
            char c = 'A' + lastdigit -10;
            ans.push_back(c);
        }
        
    }

    return ans;
}

int main()
{
    int decimal;
    cin>>decimal;

    cout<<decimal2hex(decimal);

    return 0;
}
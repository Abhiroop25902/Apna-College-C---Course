#include <bits/stdc++.h>
using namespace std;

bool isPower2_bit(int n)
{
    return (((n & (n-1)) == 0) || (n == 0));
}

int no_of_1_in_binary(int n)
{
    int ans = 0;

    while(n!= 0)
    {
        ans ++;
        n = n & (n-1);
    }

    return ans;
}

bool getbit(int n,int pos)
{
    return n & (1<<pos);
}

void subsets(int arr[],int n)
{
    for(int i=0;i<(1<<n);i++)
    {
        for(int j=0;j<n;j++)
            if(getbit(i,j))
                cout<<arr[j]<<" ";
        cout<<endl;
    }
}

int main()
{
    int n[] ={1,2,3,4};

    subsets(n,4);

    return 0;
}
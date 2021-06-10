#include <bits/stdc++.h>
using namespace std;

int find_unique_array_bit(int *arr,int n)
{
    int xorsum = 0;

    for(int i=0;i<n;i++)
        xorsum = xorsum ^ arr[i];

    return xorsum;
}

int getBit(int n, int pos)
{
    return ((n&(1<<pos))!=0);
}

int setBit(int n, int pos)
{
    return (n | (1<<pos));
}

void print_unique_number(int *arr,int n)
{
    int xorsum = 0;

    for(int i=0;i<n;i++)
        xorsum = xorsum ^ arr[i];

    int tempxor = xorsum;
    int setbit = 0;
    int pos = 0;
    while(setbit != 1)
    {
        setbit = xorsum & 1;
        pos++;
        xorsum = xorsum >>1;
    }

    int newxor = 0;
    for(int i=0;i<n;i++)
    {
        if(setBit(arr[i],pos-1))
        {
            newxor = newxor ^ arr[i];
        }

    }   

    cout<<newxor<<endl;
    cout<<(tempxor ^ newxor)<<endl;
}

int unique(int arr[],int n)
{
    int result = 0;

    for(int i=0;i<64;i++)
    {
        int sum = 0;

        for(int j = 0;j<n;j++)
        {
            if(getBit(arr[i],i))
            {
                sum ++;
            }
        }

        if(sum %3 != 0)
        {
            result = setBit(result,i);
        }
    }

    return result;
}

int main()
{
    int a[] = {1,2,3,4,1,2,3,1,2,3};

    cout<<unique(a,10)<<endl;

    return 0;
}
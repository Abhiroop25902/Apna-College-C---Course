#include <bits/stdc++.h>
using namespace std;


int getBit(int n, int pos)
{
    return (n & (1<<pos)) != 0;
}

int setBit(int n, int pos)
{
    return (n | (1 << pos));
}

int clearBit(int n, int pos)
{
    return (n & (~(1<<pos)));
}

int updateBit(int n, int pos, int value)
{
    if(value == 1)
        return setBit(n,pos);
    else if (value == 0)
        return clearBit(n,pos);
    else
        return -1;
}

int main()
{
    int n,pos,value;

    cin>>n>>pos>>value;

    cout<<updateBit(n,pos,value);

    return 0;
}
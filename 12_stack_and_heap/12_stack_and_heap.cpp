#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a[4] = {1,2,3,4};
    int *p;
    p = new int[4];
    p[1] = 2;
    int* temp =p;
    cout<<temp[1];
    delete p;


    return 0;
}
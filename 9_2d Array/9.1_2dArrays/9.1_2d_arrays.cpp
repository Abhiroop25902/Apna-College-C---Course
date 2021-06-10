#include <bits/stdc++.h>
using namespace std;

int array_2d_search( int n, int m, int s,int ** arr)
{
    for(int i = 0;i<n;i++)
        for(int j=0;j<m;j++)
            if( ((int**)arr)[i][j] == s )
                return 1;
            
    return 0;
}

int main()
{
    int n,m;
    cin>>n>>m;

    int arr[n][m];

    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin>>arr[i][j];

    int s;
    cin >>s;

    cout<<array_2d_search(n,m,s,arr);

    return 0;
}
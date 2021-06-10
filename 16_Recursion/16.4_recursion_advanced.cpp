#include <bits/stdc++.h>

using namespace std;


int tiling_problem(int n)
{
    if(n == 0)
        return 0;
    if(n == 1)
        return 1;

    return tiling_problem(n-1) + tiling_problem (n-2);
}

int friend_pair(int n)
{
    if(n == 1)
        return 1;
    if(n==2)
        return 2;

    return friend_pair(n-1) + (n-1)*friend_pair(n-2);
}

int knapsack(int value[], int wt[], int n, int W)
{
    if(n == 0 || W == 0)
        return 0;

    if(wt[n-1] > W)
        return knapsack(value,wt,n-1,W);

    return max(knapsack(value,wt,n-1,W-wt[n-1]) + value[n-1],knapsack(value,wt,n-1,W));
}

void print_permutation(string s,string ans = "")
{
    if(s.length() == 0)
    {
        cout<<ans<<endl;
        return;
    }

    for(int i=0;i<s.length();i++)
    {
        char ch = s[i];
        string ros = s.substr(0,i) + s.substr(i+1);

        print_permutation(ros,ans+ch);
    }
}

int count_path(int s, int e)
{
    if(s == e)
        return 1;

    if(s>e)
        return 0;

    int count = 0;

    for(int i=1;i<=6;i++)
    {
        count = count + count_path(s+i,e);
    }
    
    return count;
}

int count_path_maze(int n, int i=0, int j=0)
{
    if(i == n-1 && j == n-1)
        return 1;

    if(i>=n || j>=n)
        return 0;

    return count_path_maze(n,i+1,j) + count_path_maze(n,i,j+1);
}

int main()
{
    int n;
    cin>>n;

    cout<<count_path_maze(n);

    return 0;
}
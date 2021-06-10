#include <bits/stdc++.h>
using namespace std;

void helper(vector<int> a, vector<vector<int>> &ans, int idx = 0)
{
    if(idx == a.size())
    {
        ans.push_back(a);
        return;
    }

    for(int i = idx;i<a.size();i++)
    {
        if(i != idx and a[i] == a[idx])
            continue;
        
        swap(a[i],a[idx]);
        helper(a,ans,i+1);
    }
}

vector<vector<int>> permute_non_distinct(vector<int>nums)
{
    sort(nums.begin(),nums.end());

    vector<vector<int>> ans;
    helper(nums,ans);
    return ans;
}

int main()
{
    int n;
    cin>>n;

    vector<int> a(n);

    for(auto &i : a)
        cin>>i;

    vector<vector<int>> ans = permute_non_distinct(a);

    for(auto v : ans)
    {
        for(auto i:v)
            cout<<i<<" ";

        cout<<"\n";
    }

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int minimum_occurence(int *arr,int n)
{
    const int idx_size = 1e6+2;
    int idx[idx_size];

    for(int i=0;i<idx_size;i++)
        idx[i] = -1;
    
    int min_idx = INT_MAX;
    bool found = false;

    for(int i=0;i<n;i++)
    {
        if(idx[arr[i]] != -1)
        {   
            min_idx = min(min_idx,idx[arr[i]]);
            found = true;
        }
        else
        {
            idx[arr[i]] = i;
        }
        
    }

    if (found)
        return min_idx + 1;
    else
        return -1;

}

void subarray_given_sum(int *arr,int n, int given_sum)
{
    for(int i=0;i<n;i++)
    {
        int sum =0;

        for(int j=i;j<n;j++)
        {
            sum = sum + arr[j];
            
            if(sum == given_sum)
            {   
                cout<<i+1<<" "<<j+1;
                exit(0);
            }
            else if(sum > given_sum)
                break;

        }
    }
}

int smallest_positive_missing_number(int *arr,int n)
{
    int size = 1e6;
    int count[size];

    for(int i=0;i<size;i++)
        count[i]=0;

    for(int i=0;i<n;i++)
        if(arr[i] >=0)
            count[arr[i]]++;

    for(int i=0;i<size;i++)
        if(count[i]==0)
            return i;

    return -1;
        
}

int main()
{

    int n;
    cin>>n;
     
    int arr[n];

    for(int i=0;i<n;i++)
        cin>>arr[i];

   

    cout<<smallest_positive_missing_number(arr,n);
    return 0;
}
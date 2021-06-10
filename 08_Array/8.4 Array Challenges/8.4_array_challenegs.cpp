#include <bits/stdc++.h>
using namespace std;

void max_till_i(int *arr, int n)
{
    int mx = INT_MIN;
    for(int i=0;i<n;i++)
    {
        mx = max(mx,arr[i]);
        cout<<mx<<" ";
    }
}

void print_sum_all_subarray(int *arr,int n)
{
    for(int i=0;i<n;i++)
    {
        int arr_sum =0;

        for(int j=i;j<n;j++)
        {
            arr_sum = arr_sum + arr[j];
            cout<<arr_sum<<" ";    
        }
    }
}

int max_length_arithmetic_subarray(int arr[],int n)
{
    int len_max = 2;
    int diff = arr[1]-arr[0];
    int len = 2;

    for(int i=2;i<n;i++)
    {
        if(arr[i]-arr[i-1] == diff)
            len++;
        else
        {
            diff = arr[i] - arr[i-1];
            len = 2;
        }
        len_max = max(len, len_max);
    }
    return len_max;
}

int record_breaking_day(int *arr,int n)
{
    int num = 0;
    int max = INT_MIN;

    

    for(int i=0;i<n-1;i++)
    {
        if(arr[i] > max)
        {
            max = arr[i];
            if(arr[i] > arr[i+1])
                num++;
        }
    }

    if(arr[n-1] > max)
        num++;

    return num;
}

int main()
{
    int t;
    cin>>t;

    for(int a =0;a<t;a++)
    {
        int n;
        cin>>n;

        int arr[n];

        for(int i=0;i<n;i++)
            cin>>arr[i];

        cout<<'#'<<a+1<<": "<<record_breaking_day(arr,n)<<endl;
    }
    

    return 0;
}
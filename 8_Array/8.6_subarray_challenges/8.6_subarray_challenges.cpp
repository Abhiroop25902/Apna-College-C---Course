#include <bits/stdc++.h>
using namespace std;

void print_subarray(int*arr,int a, int b)
{
    for(int i=a;i<=b;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}
void print_all_subarrays(int *arr, int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
            print_subarray(arr,i,j);
    }
}

int maximum_subarray_sum(int *arr,int n)
{
    int max_sum = INT_MIN;

    for(int i=0;i<n;i++)
    {
        int sum =0;
        for(int j=i;j<n;j++)
        {
            sum = sum + arr[j];
            max_sum = max(max_sum,sum);
        }
    }
    return max_sum;
}

int kadane_maximum_subarray_sum(int *arr,int n)
{
    int max_sum = INT_MIN;
    int sum =0;
    for(int i=0;i<n;i++)
    {
        sum = sum + arr[i];
        if(sum<0)
            sum =0;
        max_sum = max(max_sum,sum);
    }
    return max_sum;
}


int max_circular_subarray_sum(int *arr,int n) //used circular queue apporach
{
    int max_sum =INT_MIN;
    for(int i=0;i<n;i++)
    {
        int sum =0;
        int j=i;
        do
        {
            sum = sum + arr[j];
            max_sum = max(max_sum,sum);
            j = (j+1)%n;

        }while(j != i);
    }
    return max_sum;
}


//if we reverse sign of every element of array
//and use kadane algo, we get the highest non contributing subarray sum
//we do ans = sum of array - highest non contributing subarray sum
int max_circular_subarray_sum_optimised(int *arr,int n)
{
    int non_wrap_sum = kadane_maximum_subarray_sum(arr,n);

    int reverse_array[n];
    int arr_sum =0;
    for(int i=0;i<n;i++)
    {    
        reverse_array[i] = -arr[i];
        arr_sum = arr_sum + arr[i];
    }

    int sum_reverse = kadane_maximum_subarray_sum(reverse_array,n);

    int sum_wrap = arr_sum + sum_reverse;   // two -'s become +
    //one minus by formula, one minus due sign reversal adjustment

    return max(non_wrap_sum,sum_wrap);
}

bool find_pair_sum(int *arr,int n, int given_sum)
{
    sort(arr,arr+n);
    int low = 0;
    int high = n-1;

    while(low < high)
    {
        int sum = arr[low] + arr[high];

        if(sum == given_sum)
            return true;
        else if(sum > given_sum)
            high--;
        else if(sum < given_sum)
            low++;
    }
    return false;
}
int main()
{
    int n;
    cin>>n;
     
    int given_sum;
    cin>>given_sum;

    int arr[n];

    for(int i=0;i<n;i++)
        cin>>arr[i];

    cout<<find_pair_sum(arr,n,given_sum);

    return 0;
}
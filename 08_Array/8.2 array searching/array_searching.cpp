#include <bits/stdc++.h>
using namespace std;

int linear_search(int *array, int size,int n)
{

    for(int i =0; i<size; i++)
    {
        if(array[i] == n)
            return i+1;
    }

    return -1;

}

int binary_search(int *array, int size, int n)
{
    int start = 0;
    int end = size - 1;

    while(start <= end)
    {
        int mid = (start + end)/2;

        if (array[mid] == n)
            return mid+1;
        else if(array[mid] > n)
            end = mid - 1;
        else if(array[mid] < n)
            start = mid + 1;
    }

    return -1;

}

int main()
{
    int size;
    cin>>size;

    int array[size];

    for(int i=0;i<size;i++)
        cin>>array[i];

    int n;
    cin>>n;

    cout<<binary_search(array,size,n);
    

    return 0;
}
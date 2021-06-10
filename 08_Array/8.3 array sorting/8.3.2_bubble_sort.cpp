#include <bits/stdc++.h>
using namespace std;

void swap(int *a, int*b)
{
    int c = *a;
    *a = *b;
    *b = c;
}

void bubble_sort(int *arr, int size)
{
    for(int i=0;i<size-1;i++)
    {
        for(int j=0;j<size-1-i;j++)
        {
            if(arr[j]>arr[j+1])
                swap(&arr[j],&arr[j+1]);
        }
    }
}

int main()
{
    int size;
    cin>>size;

    int arr[size];

    for(int i=0;i<size;i++)
        cin>>arr[i];
    
    bubble_sort(arr,size);

    for(int i=0;i<size;i++)
        cout<<arr[i]<<" ";
    

    return 0;
}
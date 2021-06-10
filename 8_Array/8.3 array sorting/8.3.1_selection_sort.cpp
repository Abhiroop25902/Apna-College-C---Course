#include <bits/stdc++.h>
using namespace std;

void swap(int *a, int*b)
{
    int c = *a;
    *a = *b;
    *b = c;
}

void selection_sort(int *array, int size)
{
    for(int i=0;i<size-1;i++)
    {
        int min = array[i];
        int pos= i;

        for(int j=i;j<size;j++)
        {
            if(min > array[j])
            {
                min = array[j];
                pos = j;
            }
        }

        swap(array[i],array[pos]);
    }
}
int main()
{
    int size;
    cin>>size;

    int array[size];

    for(int i=0;i<size;i++)
        cin>>array[i];

    selection_sort(array,size);

    for(int i=0;i<size;i++)
        cout<<array[i]<<" ";

    return 0;
}
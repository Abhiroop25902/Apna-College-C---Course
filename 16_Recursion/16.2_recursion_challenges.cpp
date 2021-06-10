
#include <bits/stdc++.h>
using namespace std;


bool array_sorted(int a[],int n,int value = INT_MAX)
{
    if((n-1)<0)
        return true;
    
    if(a[n-1] >= value)
        return false;

    return array_sorted(a,n-1,a[n-1]);
}

bool isPrime(int n)
{
    for(int i=2;i*i<=n;i++)
        if(n%i == 0)
            return false;
        
    return true;
}

void print_decresing_prime(int n)
{
    if(n>=2)
    { 
        if(isPrime(n))
            cout<<n<<" ";

        print_decresing_prime(n-1);
    }
    return;
}

void print_ascending_prime(int n,int value = 2)
{
    if(value <= n)
    {
        if(isPrime(value))
            cout<<value<<" ";

        print_ascending_prime(n,value + 1);
    }
    return;
}

int occurence_from_start(int arr[],int n,int value,int pos = 0)
{
    if(pos > (n))
        return -1;

    if(arr[pos] == value)
        return pos;
    else
        return occurence_from_start(arr,n,value,pos+1);
}

int occurence_from_end(int arr[],int n,int value,int pos = -1)
{
    if(pos == -1)
        pos = n-1;

    if(pos < 0)
        return -1;

    if(arr[pos] == value)
        return pos;
    else
    {
        return occurence_from_end(arr,n,value,pos-1);
    }
    
}

void print_first_last_occurence(int arr[],int n,int value)
{
    cout<<occurence_from_start(arr,n,value)+1<<" ";
    cout<<occurence_from_end(arr,n,value)+1;
}

int main()
{
    int n;
    cin>>n;

    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];

    int value;
    cin>>value;

    print_first_last_occurence(arr,n,value);

    return 0;
}
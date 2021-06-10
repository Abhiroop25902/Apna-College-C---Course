#include <bits/stdc++.h>
using namespace std;

//optimisation
//1) every toggling start form i^2, cause prevoius factor toggled it before
//2) so main loop only go till i^2 < n

bool* prime_seive(int n) //will return a bool array of size n+1, where ith value says if i is prime or not
{
    bool* is_prime_num;
    is_prime_num = (bool*)malloc((n+1)*sizeof(bool));
    //bool is_prime_num[n+1]; //will be sung 1 indexed for simplicity

    //initialising everything to true
    
    for(int i=1;i<=n;i++)
        is_prime_num[i] = true;

    //starting from 2 as 1 is neither odd nor even
    //main loop going through i*i<= n , cause till sqrt(n), all factors will come once
    for(int i = 2; i*i <= n; i++)
    {
        if(is_prime_num[i] == true)
        {
            //starting from i*i cause all ans of i*k , k<i has been already toggled off by previous primes
            //j = j+i to go to next factor and set it to false
            for(int j = i*i;j<=n;j = j+i)
                is_prime_num[j] = false;
        }
    }
    

   return is_prime_num;
}

void print_prime_factor(int n) 
{
    //as we know all its prime will come befor root(n)
    //using ceil to keep it as int
    int root_n_ceil = ceil(sqrt(n));

    //getting primes list till root(n)
    bool* primes = prime_seive(root_n_ceil);

    //ignoring 1
    for(int i = 2;i<=root_n_ceil;i++)
    {
        //if prime print factor till there is no more i left
        if(primes[i] == true)
        {
            while(n%i == 0)
            {
                cout<<i<<" ";
                n = n/i;
            }
        }
    }
    cout<<endl;
}

int* smallest_prime_factor_list(int n)  //returns a n+1 size int array, where ith value will be spf of i
{
    //initializzing spf and setting its default value to -1
    int* spf;
    spf = (int*)malloc((n+1) * sizeof(int));

    for(int i = 1;i<=n;i++)
        spf[i] = -1;

    //ignoring i = 1
    //not doing i*i<=n cause we want to iterate through all values to set its spf
    for(int i=2;i<=n;i++)
    {
        //if spf[i] == -1, the number will be prime
        if(spf[i] == -1)
        {
            //if number of prime, its spf is itself
            spf[i] = i;
            
            //now iterating through all multiple of the prime, if spf is not yet defined for a particular j, set spf[j] = i
            for(int j = i*i;j<=n;j=j+i)
                if(spf[j] == -1)
                    spf[j] = i;
        }
    }

    return spf;
}

void print_prime_factor_spf(int n)
{
    int* spf = smallest_prime_factor_list(n);

    while(n!= 1)
    {
        cout<<spf[n]<<" ";
        n = n / spf[n];
    }
    cout<<endl;
}

int main()
{
    int n; 
    cin>>n;

    print_prime_factor_spf(n);

    return 0;
}
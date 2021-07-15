#include <iostream>
#include <vector>
using namespace std;

typedef unsigned long long ull;

//Tabulation: Bottom Up
ull nthFibonacci_bottom_up(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;

    vector<ull> fibonacci(n + 1);

    fibonacci[0] = 0;
    fibonacci[1] = 1;

    for (int i = 2; i < fibonacci.size(); i++)
        fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];

    return fibonacci.back();
}

//Memoization: Top Down
ull recursiveFind(vector<ull> &fib, int n)
{
    if (fib[n] == -1)
        fib[n] = recursiveFind(fib, n - 1) + recursiveFind(fib, n - 2);

    return fib[n];
}

ull fibonacci_top_down(int n)
{
    vector<ull> fib(n + 1, -1);
    fib[0] = 0;
    fib[1] = 1;

    return recursiveFind(fib, n);
}

int main()
{
    int n;
    cin >> n;

    cout << fibonacci_top_down(n);
}
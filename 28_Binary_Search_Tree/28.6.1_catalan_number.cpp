#include <iostream>
#include <ctime>
#include <cmath>
using namespace std;

//n=15 took 48.512ms
long long catalan_recursive(int n)
{
    if (n == 0)
        return 1;

    long long ans = 0;

    for (int i = 0; i < n; i++)
        ans += catalan_recursive(i) * catalan_recursive(n - i - 1);

    return ans;
}

unsigned long long catalan[21] = {0};

//n=35 took 0.001ms
long long catalan_dynamic(int n)
{
    if (catalan[n] != 0)
        return catalan[n];

    for (int i = n - 1; i >= 1; i--)
        if (catalan[i] == 0)
        {
            catalan_dynamic(i);
            break;
        }
        else
            break;

    for (int i = 0; i < n; i++)
        catalan[n] += catalan[i] * catalan[n - i - 1];

    return catalan[n];
}

int main()
{
    catalan[0] = 1;
    for (int i = 0; i <= 18; i++)
    {
        float start_time = clock();
        // cout << catalan_dynamic(i) << endl;
        cout << catalan_recursive(i) << endl;
        // catalan_recursive(i);
        catalan_dynamic(i);
        float end_time = clock();

        float time_taken = (end_time - start_time) * 1000 / CLOCKS_PER_SEC;
        // cout << time_taken << "ms \n";
    }
}
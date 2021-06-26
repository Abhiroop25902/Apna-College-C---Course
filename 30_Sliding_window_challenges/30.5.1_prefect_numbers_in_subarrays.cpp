#include <iostream>
#include <queue>
using namespace std;

//tc O:(sqrt(n))
bool is_perfect_num(int num)
{
    if(num==1)
        return false;

    int sum = 1;

    for (int i = 2; i * i <= num; i++)
        if (num % i == 0)
            sum += i + num / i;

    return sum == num;
}

//tc: O(n*sqrt(n))
int perfect_numbers_subarray(const vector<int> &input, const int &k)
{
    int max_size = INT32_MIN;
    queue<int> q;

    for (int i = 0; i < k; i++)
        if (is_perfect_num(input[i]))
            q.push(input[i]);

    max_size = max(max_size, (int)q.size());

    for (int i = k; i < input.size(); i++)
    {
        if (input[i - k] == q.front())
            q.pop();

        if (is_perfect_num(input[i]))
            q.push(input[i]);

        max_size = max(max_size, (int)q.size());
    }

    return max_size;
}

int main()
{
    int n;
    cin >> n;

    int temp;

    vector<int> input;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        input.push_back(temp);
    }

    int k;
    cin >> k;

    cout << perfect_numbers_subarray(input, k);

}
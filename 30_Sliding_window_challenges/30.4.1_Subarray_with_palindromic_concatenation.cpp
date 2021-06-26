#include <iostream>
#include <vector>
using namespace std;

//time complexity: O(input.len()/2)
bool is_string_palindrome(string input)
{
    int left = 0;
    int right = input.size() - 1;

    while (left <= right)
    {
        if (input[left] != input[right])
            return false;
        left++;
        right--;
    }

    return true;
}

//time complexity: O((r_ptr-l_ptr)*(avg number of digit in int data) * 3/2 )
bool is_subarray_palindrome(const vector<int> &input, const int &l_ptr, const int &r_ptr)
{
    string num_to_str;

    for (int i = l_ptr; i <= r_ptr; i++)
    {
        int num = input[i];

        while (num != 0)
        {
            num_to_str += to_string(num % 10);
            num /= 10;
        }
    }

    return is_string_palindrome(num_to_str);
}

//time complexity: O(n*k)
bool subarray_with_palindromic_concatenation(const vector<int> &input, const int &k)
{
    int l_ptr = 0;
    int r_ptr = k - 1;

    while (r_ptr != input.size())
    {
        if (is_subarray_palindrome(input, l_ptr, r_ptr))
            return true;

        l_ptr++;
        r_ptr++;
    }
    return false;
}

int main()
{
    int n;
    cin >> n;

    vector<int> input;

    for (int i = 0; i < n; i++)
    {
        int data;
        cin >> data;

        input.push_back(data);
    }

    int k;
    cin >> k;

    if (subarray_with_palindromic_concatenation(input, k))
        cout << "True";
    else
        cout << "False";
}

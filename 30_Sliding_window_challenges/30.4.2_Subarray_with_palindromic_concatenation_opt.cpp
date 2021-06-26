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

//tc: O(1)
char to_char(const int &num)
{
    return num + '0';
}

//tc:  num_digits*push_back so O(num_digit) amortized or O(num_digit*(string_len+1)) worse
void string_add_end(string &str, int num)
{
    if (num == 0)
        str.append("0");
    else
        while (num != 0)
        {
            str.push_back(to_char(num % 10));
            num /= 10;
        }
}

//tc:  num_digits + erase so O(erase) = O(original strlen)
void string_del_start(string &str, int num)
{

    if (num == 0)
        str.erase(str.begin(), str.begin() + 1);
    else
    {
        int num_size = 0;

        while (num != 0)
        {
            num_size++;
            num /= 10;
        }

        str.erase(str.begin(), str.begin() + num_size);
    }
}

//time complexity: k*summ(num_digit) + (n-k)*(summ(num_digit + (k-1))), approx O(n*k)
bool subarray_with_palindromic_concatenation(const vector<int> &input, const int &k)
{
    string curr_window;
    int l_ptr = 0;
    int r_ptr = 0;
    for (; r_ptr <= k - 1; r_ptr++)
        string_add_end(curr_window, input[r_ptr]);

    if (is_string_palindrome(curr_window))
        return true;

    while (r_ptr < input.size())
    {
        string_del_start(curr_window, input[l_ptr]);
        l_ptr++;
        string_add_end(curr_window, input[r_ptr]);
        r_ptr++;
        if (is_string_palindrome(curr_window))
            return true;
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

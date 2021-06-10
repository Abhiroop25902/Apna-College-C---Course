//https://leetcode.com/problems/count-number-of-nice-subarrays/

//idea is similar to sliding window but with extra complexity of subarrays

//if we have a left right pair with k number of odd number, we can increment left till nums[left] is even 
//and similarly we  can also increment right till num[right] is odd
// we then count the number of increment of both left and right and do ans += multiplication of increments

#include <bits/stdc++.h>
using namespace std;

int numberOfSubarrays(vector<int> &nums, int k)
{
    //let even becoem 0 and odd become 1

    for (int i = 0; i < nums.size(); i++)
        nums[i] = nums[i] % 2;

    int left = 0;
    int right = 0;
    int ans = 0;
    int odd_count = 0;

    for (; right < nums.size(); right++)
    {
        if (nums[right] == 1)
            odd_count++;

        if (odd_count == k)
        {
            int a = 1;
            int b = 1;

            while (left != right && nums[left] != 1)
            {
                a++;
                left++;
            }

            right++;
            while (right < nums.size() && nums[right] != 1)
            {
                b++;
                right++;
            }

            if (right != nums.size() && nums[right] == 1)
                right--;

            left++;
            odd_count--;
            ans += a * b;
        }
    }
    return ans;
}

int main()
{
    int n, k;
    cin >> n >> k;

    int temp;
    vector<int> v;

    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        v.push_back(temp);
    }

    cout << numberOfSubarrays(v, k);
}

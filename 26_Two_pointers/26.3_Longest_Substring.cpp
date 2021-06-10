//https://leetcode.com/problems/longest-substring-without-repeating-characters/submissions/

//NOTICE: INPUT DOESN'T HAVE JUST LOWERCASE (Messed my brain up for 5 minutes) (assume all 256 ascii can come)

//idea: same sliding way as we have been following, but the added catch here is that we need to keep track of all the letters already present
//What I did was to maintain a 256 sized bool to keep track of any charaters which is already been in substring in question

#include <iostream>
using namespace std;

int lengthOfLongestSubstring(const string &s)
{
    bool is_char_taken[256] = {false};

    int left = 0;
    int right = 0;
    int ans = 0;

    for (; right < s.size(); right++)
    {
        if (is_char_taken[s[right]] == false)
            is_char_taken[s[right]] = true;
        else
        {
            if (s[left] == s[right])
            {
                is_char_taken[s[left]] = false;
                left++;
            }
            else
                while (s[left] != s[right])
                {
                    is_char_taken[s[left]] = false;
                    left++;
                }

            right--;
        }

        ans = max(ans, right - left + 1);
    }

    return ans;
}

int main()
{
    string s;
    cin >> s;

    cout << lengthOfLongestSubstring(s);
}
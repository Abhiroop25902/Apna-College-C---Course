#include <iostream>
#include <vector>
using namespace std;

vector<int> arr;


int longestIncresingSubsequence(int currIndex = 0, int maxElem = -1, int currLen = 0)
{
    if (currIndex > arr.size())
        return currLen;

    if (arr[currIndex] < maxElem) //don't take this element
        return longestIncresingSubsequence(currIndex + 1, maxElem, currLen);
    else
        return max(longestIncresingSubsequence(currIndex + 1, maxElem, currLen),
                   longestIncresingSubsequence(currIndex + 1, arr[currIndex], currLen + 1));
}

int main()
{
    int n;
    cin >> n;

    arr = vector<int>(n);

    for (int i = 0; i < arr.size(); i++)
        cin >> arr[i];

    cout << longestIncresingSubsequence();
}
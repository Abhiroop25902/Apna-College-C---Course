#include <iostream>
#include <vector>
using namespace std;

int OptimalGameStrategy(vector<int> gameData, int start, int end)
{
    if (start > end)
        return 0;
    if (start == end)
        return gameData[start];

    int option1 = gameData[start] + min(OptimalGameStrategy(gameData, start + 2, end), OptimalGameStrategy(gameData, start + 1, end - 1));
    int option2 = gameData[end] + min(OptimalGameStrategy(gameData, start, end - 2), OptimalGameStrategy(gameData, start + 1, end - 1));
    return max(option1, option2);
}

int main()
{
    int n;
    cin >> n;

    vector<int> gameData(n);
    for (int i = 0; i < n; i++)
        cin >> gameData[i];

    cout << OptimalGameStrategy(gameData, 0, gameData.size() - 1);
}
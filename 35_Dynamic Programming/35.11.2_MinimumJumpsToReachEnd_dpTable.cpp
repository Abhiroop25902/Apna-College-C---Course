#include <iostream>
#include <vector>
using namespace std;

int minimumJumpsToReachEnd_dpTable(vector<int> path)
{
    vector<vector<int>> dpTable(path.size(), vector<int>(path.size(), 0));

    for (int diff = 0; diff < path.size(); diff++)
    {
        for (int i = path.size() - diff - 1; i >= 0; i--)
        {
            int j = i + diff;

            if(path[i] == 0)
                dpTable[i][j]  = INT16_MAX;
            else if (i == j)
                continue;
            else if (i + path[i] >= j)
                dpTable[i][j] = 1;
            else
            {
                dpTable[i][j] = INT32_MAX;
                for (int k = i + 1; k <= i + path[i]; k++)
                {
                    dpTable[i][j] = min(dpTable[i][j], dpTable[i][k] + dpTable[k][j]);
                }
            }
        }
    }

    return dpTable[0][path.size() - 1];
}

int main()
{
    int n;
    cin >> n;

    vector<int> path(n);
    for (int i = 0; i < n; i++)
        cin >> path[i];

    cout << minimumJumpsToReachEnd_dpTable(path);
}
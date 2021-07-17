#include <iostream>
#include <vector>
using namespace std;

int matrixchainMultiplication(vector<int> dimensions)
{
    vector<vector<int>> dpTable(dimensions.size() - 1, vector<int>(dimensions.size() - 1, 0));

    for (int len = 1; len < dpTable.size(); len++)
        for (int i = len; i < dpTable.size(); i++)
        {
            int j = i - len;
            dpTable[i][j] = INT32_MAX;

            for (int k = i; k > j; k--)
                dpTable[i][j] = min(dpTable[i][j], dpTable[k - 1][j] + dpTable[i][k] + dimensions[j] * dimensions[k] * dimensions[i + 1]);
        }

    return dpTable.back()[0];
}

int main()
{
    int n;
    cin >> n;

    vector<int> dimensions(n);

    for (int i = 0; i < dimensions.size(); i++)
        cin >> dimensions[i];

    cout << matrixchainMultiplication(dimensions);
}
#include <iostream>
#include <vector>
using namespace std;

vector<vector<char>> takeInput()
{
    int m, n;
    cin >> m >> n;

    vector<vector<char>> inputGrid(m, vector<char>(n));

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> inputGrid[i][j];

    return inputGrid;
}

void recursiveChange(vector<vector<char>> &grid, int i, int j)
{
    grid[i][j] = '*';

    //up, left, down , right
    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};

    for (int k = 0; k < 4; k++)
    {
        int cx = i + dx[k];
        int cy = j + dy[k];

        if (cx >= 0 && cx < grid.size())
            if (cy >= 0 && cy < grid[cx].size())
                if (grid[cx][cy] == 'O')
                    recursiveChange(grid, cx, cy);
    }
}

void convertEdge(vector<vector<char>> &grid)
{
    for (int i = 0; i < grid.size(); i++)
        for (int j = 0; j < grid[i].size(); j++)
            if (i == 0 || i == grid.size() - 1 || j == 0 || j == grid[i].size() - 1)
                if (grid[i][j] == 'O')
                    recursiveChange(grid, i, j);
}

void changeSurrounderRegion(vector<vector<char>> &grid)
{
    for (int i = 0; i < grid.size(); i++)
        for (int j = 0; j < grid[i].size(); j++)
            if (grid[i][j] == 'O')
                grid[i][j] = 'X';
}

void undoStar(vector<vector<char>> &grid)
{
    for (int i = 0; i < grid.size(); i++)
        for (int j = 0; j < grid[i].size(); j++)
            if (grid[i][j] == '*')
                grid[i][j] = 'O';
}

void printGrid(vector<vector<char>> &grid)
{
    for (auto i : grid)
    {
        for (auto j : i)
            cout << j << " ";
        cout << "\n";
    }
}

int main()
{
    auto grid = takeInput();
    convertEdge(grid);
    changeSurrounderRegion(grid);
    undoStar(grid);
    printGrid(grid);
}
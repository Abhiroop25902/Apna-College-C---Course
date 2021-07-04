#include <iostream>
#include <vector>
#include <map>
using namespace std;

void helper(int r, int c, vector<vector<char>> &input, map<pair<int, int>, map<int, bool>> &mp, vector<map<int, bool>> &row, vector<map<int, bool>> &col)
{
    if (r == 9) //base case
    {
        for (auto i : input)
        {
            for (auto j : i)
                cout << j << " ";

            cout << "\n";
        }
        cout<<"\n";
        return;
    }

    if (c == 9)
    {
        helper(r + 1, 0, input, mp, row, col);
        return;
    }

    if (input[r][c] != '.') //not empty
    {
        helper(r, c + 1, input, mp, row, col);
        return;
    }

    for (int i = 1; i <= 9; i++)
    {
        //block co-ordinates
        int rw = r / 3;
        int cl = c / 3;

        if (!mp[{rw, cl}][i] && !row[r][i] && !col[c][i])
        {
            mp[{rw, cl}][i] = true;
            row[r][i] = true;
            col[c][i] = true;
            input[r][c] = i + '0';

            helper(r, c + 1, input, mp, row, col);

            mp[{rw, cl}][i] = false; //backtrack undo made changes
            row[r][i] = false;
            col[c][i] = false;
            input[r][c] = '.';
        }
    }
}

void sudoku_solver(vector<vector<char>> &input)
{
    map<pair<int, int>, map<int, bool>> mp; //first key is block position
                                            //second map has first element number of sudoku and
                                            //value is true of false
    vector<map<int, bool>> row(9);          //map has first element number of sudoku and value is true of false
    vector<map<int, bool>> col(9);          //map has first element number of sudoku and value is true of false

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (input[i][j] != '.')
            {
                mp[{i / 3, j / 3}][input[i][j] - '0'] = true;
                row[i][input[i][j] - '0'] = true;
                row[i][input[i][j] - '0'] = true;
            }
        }
    }
    helper(0, 0, input, mp, row, col); //recursive function which goes at every value, and try to add number to .
}

int main()
{
    vector<vector<char>> sudoku = {{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
                                   {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
                                   {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
                                   {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
                                   {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
                                   {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                                   {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
                                   {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
                                   {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

    sudoku_solver(sudoku);
}

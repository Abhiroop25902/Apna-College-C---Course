#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

int minNumSteps()
{
    int source, dest;
    const int numNodes = 100;

    unordered_map<int, int> ladders;
    int numLadder;
    cin >> numLadder;
    for (int i = 0; i < numLadder; i++)
    {
        cin >> source >> dest;
        ladders[source] = dest;
    }

    unordered_map<int, int> snakes;
    int numSnakes;
    cin >> numSnakes;
    for (int i = 0; i < numSnakes; i++)
    {
        cin >> source >> dest;
        snakes[source] = dest;
    }

    bool isVisited[numNodes + 1] = {false};

    //pair: pos, numStepTaken
    queue<pair<int, int>> bfsQueue;
    bfsQueue.push({1, 0});

    const int diceMax = 6;

    while (!bfsQueue.empty())
    {
        auto currNum = bfsQueue.front();

        if (currNum.first == 100)
            return currNum.second;

        isVisited[currNum.first] = true;
        bfsQueue.pop();

        for (int i = 1; i <= diceMax; i++)
        {
            if (currNum.first + i <= numNodes && !isVisited[currNum.first + i])
            {
                if (ladders[currNum.first + i] != 0)
                    bfsQueue.push({ladders[currNum.first + i], currNum.second + 1});
                else if (snakes[currNum.first + i] != 0)
                    bfsQueue.push({snakes[currNum.first + i], currNum.second + 1});
                else
                    bfsQueue.push({currNum.first + i, currNum.second + 1});
            }
        }
    }

    return -1;
}

int main()
{
    cout << minNumSteps();
}

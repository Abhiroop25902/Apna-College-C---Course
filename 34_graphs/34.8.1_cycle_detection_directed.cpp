#include <iostream>
#include <vector>
using namespace std;

// // this doesn't copy the whole vector dur to inbuilt stuffs
// vector<int> returnVector(int size, int val)
// {
//     return vector<int>(size, val);
// }

vector<vector<int>> makeAdjacencyList(const int &numNodes, const int &numEdges)
{
    vector<vector<int>> adjacencyList(numNodes);

    int source, dest;

    for (int i = 0; i < numEdges; i++)
    {
        cin >> source >> dest;
        //as the graph is directed and values are assumed 0 indexed
        adjacencyList[source].push_back(dest);
    }

    return adjacencyList;
}

bool recursiveCycleTest(const vector<vector<int>> &adjacencyList, vector<bool> &isAlreadyMet, vector<bool> &inVision, const int node)
{
    inVision[node] = true;

    if (!isAlreadyMet[node])
    {
        isAlreadyMet[node] = true;

        for (auto i : adjacencyList[node])
        {
            if (!isAlreadyMet[i] && recursiveCycleTest(adjacencyList, isAlreadyMet, inVision, i))
                return true;

            if (inVision[i])
                return true;
        }
    }
    inVision[node] = false;
    return false;
}

bool isCyclePresent(const vector<vector<int>> &adjacencyList)
{
    vector<bool> inVision(adjacencyList.size());
    vector<bool> isAlreadyMet(adjacencyList.size(), false);

    for (int i = 0; i < adjacencyList.size(); i++)
        if (isAlreadyMet[i] == false && recursiveCycleTest(adjacencyList, isAlreadyMet, inVision, i) == true)
            return true;

    return false;
    // return recursiveCycleTest(adjacencyList, isAlreadyMet);
}

int main()
{
    //undirected graph

    int numNodes, numEdges;
    cin >> numNodes >> numEdges;

    vector<vector<int>> adjacencyList = makeAdjacencyList(numNodes, numEdges);

    if (isCyclePresent(adjacencyList) == true)
        cout << "true";
    else
        cout << "false";
}

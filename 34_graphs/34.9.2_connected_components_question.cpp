#include <iostream>
#include <vector>
using namespace std;

class undirectedWeightedGraph
{
    vector<vector<int>> adjacencyList;
    void DFS(const int nodeIndex, vector<bool> &isVisited, vector<vector<int>> &connectedComponents);
    vector<vector<int>> getConnectedComponent();

public:
    undirectedWeightedGraph();
    void printAdjacencyList();
    int friendPairingProblem();
};

undirectedWeightedGraph::undirectedWeightedGraph()
{
    int numNodes;
    int numEdges;
    cin >> numNodes >> numEdges;

    for (int i = 0; i < numNodes; i++)
        adjacencyList.push_back(vector<int>());

    int source, dest;
    for (int i = 0; i < numEdges; i++)
    {
        cin >> source >> dest;
        //as the graph is undirected and values are assumed 0 indexed
        adjacencyList[source].push_back(dest);
        adjacencyList[dest].push_back(source);
    }
}

void undirectedWeightedGraph::printAdjacencyList()
{
    for (int i = 0; i < adjacencyList.size(); i++)
    {
        cout << i << ": ";
        for (int j = 0; j < adjacencyList[i].size(); j++)
            cout << adjacencyList[i][j] << " ";
        cout << "\n";
    }
}

void undirectedWeightedGraph::DFS(const int nodeIndex, vector<bool> &isVisited, vector<vector<int>> &connectedComponents)
{
    isVisited[nodeIndex] = true;
    connectedComponents.back().push_back(nodeIndex);

    for (int j = 0; j < adjacencyList[nodeIndex].size(); j++)
        if (!isVisited[adjacencyList[nodeIndex][j]])
            DFS(adjacencyList[nodeIndex][j], isVisited, connectedComponents);
}

vector<vector<int>> undirectedWeightedGraph::getConnectedComponent()
{
    vector<vector<int>> connectedComponents;
    vector<bool> isVisited(adjacencyList.size(), false);

    for (int i = 0; i < adjacencyList.size(); i++)
    {
        if (isVisited[i] == false)
        {
            connectedComponents.push_back(vector<int>());
            DFS(i, isVisited, connectedComponents);
        }
    }
    return connectedComponents;
}

int undirectedWeightedGraph::friendPairingProblem()
{
    vector<vector<int>> connectedComponents = getConnectedComponent();

    int answer = 0;

    for (int i = 0; i < connectedComponents.size(); i++)
        answer += connectedComponents[i].size() * (adjacencyList.size() - connectedComponents[i].size());

    return answer / 2;
}

int main()
{
    undirectedWeightedGraph g;
    cout << g.friendPairingProblem();
}

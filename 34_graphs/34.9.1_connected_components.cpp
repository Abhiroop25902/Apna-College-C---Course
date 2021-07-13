#include <iostream>
#include <vector>
using namespace std;

class undirectedWeightedGraph
{
    vector<vector<int>> adjacencyList;
    void printDFS(const int nodeIndex, vector<bool> &isVisited);

public:
    undirectedWeightedGraph();
    void printAdjacencyList();
    void printConnectedComponent();
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

void undirectedWeightedGraph::printDFS(const int nodeIndex, vector<bool> &isVisited)
{
    isVisited[nodeIndex] = true;
    cout << nodeIndex << " ";

    for (int j = 0; j < adjacencyList[nodeIndex].size(); j++)
        if (!isVisited[adjacencyList[nodeIndex][j]])
            printDFS(adjacencyList[nodeIndex][j], isVisited);
}

void undirectedWeightedGraph::printConnectedComponent()
{
    vector<bool> isVisited(adjacencyList.size(), false);
    for (int i = 0; i < adjacencyList.size(); i++)
    {
        if (isVisited[i] == false)
        {
            printDFS(i, isVisited);
            cout << "\n";
        }
    }
}

int main()
{
    undirectedWeightedGraph g;
    g.printConnectedComponent();
}

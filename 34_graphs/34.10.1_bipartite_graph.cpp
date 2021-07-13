#include <iostream>
#include <vector>
using namespace std;

class undirectedWeightedGraph
{
    vector<vector<int>> adjacencyList;
    bool colorDFS(int node, vector<bool> &isVisited, vector<int> &colors, bool nodeColor = false);

public:
    undirectedWeightedGraph();
    void printAdjacencyList();
    bool isBipartite();
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

bool undirectedWeightedGraph::colorDFS(int node, vector<bool> &isVisited, vector<int> &colors, bool nodeColor)
{
    isVisited[node] = true;

    for (auto i : adjacencyList[node])
    {
        if (isVisited[i])
        { 
            if (colors[i] == nodeColor)
                return false;
        }
        else
        {
            if (colorDFS(i, isVisited, colors, !nodeColor) == false)
                return false;
        }
    }
    colors[node] = nodeColor;
    return true;
}

bool undirectedWeightedGraph::isBipartite()
{
    vector<bool> isVisited(adjacencyList.size(), false);
    vector<int> colors(adjacencyList.size(), -1); //two color defined by true and false, 3 is unassigned;

    for (int i = 0; i < adjacencyList.size(); i++)
    {
        if (!isVisited[i])
            if (colorDFS(i, isVisited, colors) == false)
                return false;
    }
    return true;
}

int main()
{
    undirectedWeightedGraph g;

    if (g.isBipartite())
        cout << "true";
    else
        cout << "false";
}

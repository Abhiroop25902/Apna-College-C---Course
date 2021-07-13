#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> *convertAdjacencyList(vector<pair<int, int>> edges, int num_node)
{
    //source and dest are 1-indexed, so making an extra size
    vector<vector<int>> *adjacencyList = new vector<vector<int>>(num_node + 1);

    //undirected graph, so add both side
    for (int i = 0; i < edges.size(); i++)
    {
        (*adjacencyList)[edges[i].first].push_back(edges[i].second);
        (*adjacencyList)[edges[i].second].push_back(edges[i].first);
    }

    return adjacencyList;
}

void printAdjacencyList(vector<vector<int>> *adjacencyList)
{
    for (int i = 1; i < (*adjacencyList).size(); i++)
    {
        cout << i << ":  ";
        for (int j = 0; j < (*adjacencyList)[i].size(); j++)
            cout << (*adjacencyList)[i][j] << " -> ";
        cout << "STOP\n";
    }
}

bool isEdgePresent(vector<vector<int>> *adjacencyList, int value1, int value2)
{
    int val1Found = false;

    for (auto i : (*adjacencyList)[value1])
        if (i == value2)
            val1Found = true;

    if (val1Found == false)
        return false;

    int val2Found = false;

    for (auto i : (*adjacencyList)[value2])
        if (i == value1)
            val2Found = true;

    if (val2Found == false)
        return false;

    return true;
}

int main()
{
    int num_node, num_edge;
    cin >> num_node >> num_edge;

    //pair: first is source, second is dest
    vector<pair<int, int>> edges(num_edge);

    for (int i = 0; i < num_edge; i++)
        cin >> edges[i].first >> edges[i].second;

    vector<vector<int>> *adjacencyList = convertAdjacencyList(edges, num_node);
    printAdjacencyList(adjacencyList);

    if (isEdgePresent(adjacencyList, 3, 7))
        cout << "true" << endl;
    else
        cout << "false" << endl;
}
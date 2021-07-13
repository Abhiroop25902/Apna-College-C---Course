#include <iostream>
#include <vector>
using namespace std;

//undirected edge check, both of way should be present,
//also matrix is made 1-indexed, so no -1 required
//<---------------O(1)---------------->
bool isEdgePresent(vector<vector<int>> *adjacencyMatrix, int value1, int value2)
{
    return ((*adjacencyMatrix)[value1][value2] == 1) && ((*adjacencyMatrix)[value2][value1] == 1);
}

vector<vector<int>> *convertAdjacencyMatrix(const vector<pair<int, int>> &edges, const int &num_node)
{
    // //note: vertices are defined in 1-indexed, so we will do -1 for each value
    // vector<vector<int>> adjacency_matrix(num_node);

    // for (int i = 0; i < num_node; i++)
    //     adjacency_matrix[i] = vector<int>(num_node, 0);

    // //note: graph is undirected, so we need to update both ways
    // for (int i = 0; i < edges.size(); i++)
    // {
    //     adjacency_matrix[edges[i].first - 1][edges[i].second - 1] = 1;
    //     adjacency_matrix[edges[i].second - 1][edges[i].first - 1] = 1;
    // }

    //altenate: define (n+1)x (n+1) matrix and proceed without hiccups

    vector<vector<int>> *adjacency_matrix = new vector<vector<int>>(num_node + 1, vector<int>(num_node + 1, 0));

    //note: graph is undirected, so we need to update both ways
    for (int i = 0; i < edges.size(); i++)
    {
        (*adjacency_matrix)[edges[i].first][edges[i].second] = 1;
        (*adjacency_matrix)[edges[i].second][edges[i].first] = 1;
    }

    return adjacency_matrix;
}

void printAdjacencyMatrix(vector<vector<int>> *adjacencyMatrix)
{
    //avoid printing 0 index values, as they are extra
    for (int i = 1; i < (*adjacencyMatrix).size(); i++)
    {
        for (int j = 1; j < (*adjacencyMatrix)[i].size(); j++)
            cout << (*adjacencyMatrix)[i][j] << " ";
        cout << endl;
    }
}

int main()
{
    int num_node, num_edge;
    cin >> num_node >> num_edge;

    //pair: first is source, second is dest
    vector<pair<int, int>> edges(num_edge);

    for (int i = 0; i < num_edge; i++)
        cin >> edges[i].first >> edges[i].second;

    vector<vector<int>> *adjacency_matrix = convertAdjacencyMatrix(edges, num_node);
    printAdjacencyMatrix(adjacency_matrix);

    if (isEdgePresent(adjacency_matrix, 3, 7))
        cout << "true" << endl;
    else
        cout << "false" << endl;
}
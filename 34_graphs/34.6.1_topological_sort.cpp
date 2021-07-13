#include <iostream>
#include <vector>
using namespace std;

//1 indexed pairs
int main()
{
    int num_node, num_edge;
    cin >> num_node >> num_edge;

    vector<vector<int>> adjacencyMatrix(num_node + 1, vector<int>(num_node + 1, 0));

    int source, dest;
    for (int i = 0; i < num_edge; i++)
    {
        cin >> source >> dest;
        adjacencyMatrix[source][dest] = 1;
    }

    vector<bool> isPrinted(num_node + 1, false);
    int print_count = 0;

    // for (int i = 1; i < adjacencyMatrix.size(); i++)
    // {
    //     for (int j = 1; j < adjacencyMatrix[i].size(); j++)
    //         cout << adjacencyMatrix[i][j] << " ";
    //     cout << endl;
    // }

    while(print_count < num_node)
    {
        for (int i = 1; i < adjacencyMatrix.size(); i++)
        {
            if (!isPrinted[i])
            {
                bool isLeaf = true;

                for (int j = 1; j < adjacencyMatrix.size(); j++)
                    if (adjacencyMatrix[j][i] == 1)
                    {
                        isLeaf = false;
                        break;
                    }

                if (isLeaf)
                {
                    isPrinted[i] = true;
                    cout << i << " ";
                    print_count++;

                    for (int j = 1; j < adjacencyMatrix.size(); j++)
                        adjacencyMatrix[i][j] = 0;
                }
            }
        }
    }
}
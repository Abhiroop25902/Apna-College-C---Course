#include <iostream>
#include <vector>
using namespace std;

class disjointSetUnion
{
    vector<int> parent;
    vector<int> size;

    int find_set(int x);

public:
    disjointSetUnion(int numVertices);
    bool setUnion(int x, int y);
};

disjointSetUnion::disjointSetUnion(int numVertices)
{
    parent = vector<int>(numVertices);

    for (int i = 0; i < parent.size(); i++)
        parent[i] = i;

    size = vector<int>(numVertices, 1);
}

int disjointSetUnion::find_set(int x)
{
    if (parent[x] != x)
        parent[x] = find_set(parent[x]);

    return parent[x];
}

bool disjointSetUnion::setUnion(int x, int y)
{
    int parX = find_set(x);
    int parY = find_set(y);

    if (parX != parY)
    {
        if (size[x] < size[y])
            swap(x, y);

        // now confirmed x is the bigger tree

        parent[y] = x;
        size[x] += size[y];
        return true;
    }
    return false;
}

bool isCyclePresent(int numVertices, const vector<pair<int, int>> &edges)
{
    disjointSetUnion set(numVertices);

    for (int i = 0; i < edges.size(); i++)
    {
        if (set.setUnion(edges[i].first, edges[i].second) == false)
            return true;
    }

    return false;
}

int main()
{
    int numVertices, numEdges;

    cin >> numVertices >> numEdges;

    vector<pair<int, int>> edges(numEdges);

    int x, y;

    for (int i = 0; i < edges.size(); i++)
    {
        cin >> x >> y;
        edges[i] = {x, y};
    }

    if (isCyclePresent(numVertices, edges) == true)
        cout << "true";
    else
        cout << "false";
}
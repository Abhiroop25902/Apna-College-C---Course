#include <iostream>
#include <vector>
using namespace std;

class disjointSetUnion
{
    int numVertices;
    int numEdges;

    vector<int> parent;
    vector<int> size;

public:
    disjointSetUnion();
    int find_set(int x);
    void setUnion(int x, int y);
};

disjointSetUnion::disjointSetUnion()
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

void disjointSetUnion::setUnion(int x, int y)
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
    }
}
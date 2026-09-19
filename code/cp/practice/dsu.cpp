#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> parent, sz;
int numComp = 0;
int maxSize = 0;

void init(int n)
{
    parent.resize(n + 1);
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
    }

    sz.assign(n + 1, 1);
    numComp = n;
    maxSize = 1;
}

int find(int x)
{
    if (parent[x] != x)
    {
        parent[x] = find(parent[x]);
    }
    return parent[x];
}

void unite(int x, int y)
{
    int rx = find(x), ry = find(y);
    if (rx == ry)
        return;

    if (sz[rx] < sz[ry])
    {
        swap(rx, ry);
    }
    parent[ry] = rx;
    numComp--;
    sz[rx] += sz[ry];
    maxSize = max(maxSize, sz[rx]);
}

long long kruskal(vector<tuple<int, int, int>> edges)
{
    sort(edges.begin(), edges.end());
    long long total = 0;
    int edges_used = 0;
    for (auto [w, a, b] : edges)
    {
        if (find(a) != find(b))
        {
            unite(a, b);
            total += w;
            edges_used++;
        }
    }

    return total;
}
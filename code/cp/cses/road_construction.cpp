#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

vector<int> parent, sz;
int numComponents;
int maxSize;

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
    {
        return;
    }

    if (sz[rx] < sz[ry])
    {
        swap(rx, ry);
    }
    parent[ry] = rx;
    sz[rx] += sz[ry];

    numComponents--;
    maxSize = max(maxSize, sz[rx]);
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    parent.resize(n + 1);
    sz.assign(n + 1, 1);
    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
    }
    numComponents = n;
    maxSize = 1;

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        unite(a, b);
        cout << numComponents << " " << maxSize << '\n';
    }

    return 0;
}

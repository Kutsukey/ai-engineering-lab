#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> parent, sz;
int numC;
int maxS;

int find(int x)
{
    if (x != parent[x])
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
    numC--;
    maxS = max(maxS, sz[rx]);
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

    numC = n;
    vector<tuple<int, int, int>> edges;
    for (int i = 1; i <= m; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        edges.push_back(make_tuple(w, a, b));
    }
    sort(edges.begin(), edges.end());

    long long total_cost = 0;
    for (auto &[w, a, b] : edges)
    {
        if (find(a) != find(b))
        {
            unite(a, b);
            total_cost += w;
        }
    }

    if (numC == 1)
    {
        cout << total_cost << '\n';
    }
    else
    {
        cout << "IMPOSSIBLE" << '\n';
    }

    return 0;
}

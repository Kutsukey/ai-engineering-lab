#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
using ll = long long;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    vector<int> inDegree(n + 1, 0);

    for (int i = 1; i <= m; i++)
    {
        int a, b;
        cin >> a >> b;
        inDegree[b]++;
        adj[a].push_back(b);
    }

    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        if (inDegree[i] == 0)
        {
            q.push(i);
        }
    }

    vector<int> order;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        order.push_back(u);
        for (auto &&v : adj[u])
        {
            inDegree[v]--;
            if (inDegree[v] == 0)
            {
                q.push(v);
            }
        }
    }

    if (order.size() != n)
    {
        cout << "IMPOSSIBLE" << '\n';
    }
    else
    {
        for (auto &&i : order)
        {
            cout << i << " ";
        }
        cout << '\n';
    }

    return 0;
}

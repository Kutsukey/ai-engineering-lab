// 20C
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
using ll = long long;
using pli = pair<ll, int>;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<vector<pli>> adj(n + 1);
    vector<ll> dist(n + 1, 1e18);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        adj[a].push_back({c, b});
        adj[b].push_back({c, a});
    }

    priority_queue<pli, vector<pli>, greater<pli>> pq;
    dist[1] = 0;
    pq.push({0, 1});
    vector<ll> parent(n + 1, -1);
    while (!pq.empty())
    {
        auto [d, u] = pq.top();
        pq.pop();

        if (d > dist[u])
        {
            continue;
        }

        for (auto &&[w, v] : adj[u])
        {
            if (d + w < dist[v])
            {
                dist[v] = d + w;
                pq.push({dist[v], v});
                parent[v] = u;
            }
        }
    }

    if (dist[n] == 1e18)
    {
        cout << -1 << '\n';
    }
    else
    {
        vector<int> path;
        for (int i = n; i != -1; i = parent[i])
        {
            path.push_back(i);
        }
        reverse(path.begin(), path.end());
        for (auto &&i : path)
        {
            cout << i << " ";
        }
        cout << '\n';
    }

    return 0;
}

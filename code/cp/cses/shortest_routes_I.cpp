#include <iostream>
#include <algorithm>
#include <vector>
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
    priority_queue<pli, vector<pli>, greater<pli>> pq;
    dist[1] = 0;
    pq.push({0, 1});
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }

    while (!pq.empty())
    {
        auto [d, u] = pq.top();
        pq.pop();

        if (d > dist[u])
        {
            continue;
        }

        for (auto &[v, w] : adj[u])
        {
            if (dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        cout << dist[i] << (i == n ? "" : " ");
    }
    cout << '\n';
    return 0;
}

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
using ll = long long;

const int MOD = 1e9 + 7;
const ll INF = 1e18;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    vector<vector<pair<ll, int>>> adj(n + 1);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        adj[a].push_back({c, b});
    }

    vector<ll> dist(n + 1, INF);
    vector<int> routes(n + 1, 0);
    vector<int> min_f(n + 1, 1e9);
    vector<int> max_f(n + 1, -1e9);

    dist[1] = 0;
    routes[1] = 1;
    min_f[1] = 0;
    max_f[1] = 0;

    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    pq.push({0, 1});

    while (!pq.empty())
    {
        auto [d, u] = pq.top();
        pq.pop();

        if (d > dist[u])
        {
            continue;
        }

        for (auto [w, v] : adj[u])
        {
            if (dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                routes[v] = routes[u];
                min_f[v] = min_f[u] + 1;
                max_f[v] = max_f[u] + 1;
                pq.push({dist[v], v});
            }
            else if (dist[u] + w == dist[v])
            {
                routes[v] = (routes[v] + routes[u]) % MOD;
                min_f[v] = min(min_f[v], min_f[u] + 1);
                max_f[v] = max(max_f[v], max_f[u] + 1);
            }
        }
    }

    cout << dist[n] << " " << routes[n] << " " << min_f[n] << " " << max_f[n] << '\n';

    return 0;
}

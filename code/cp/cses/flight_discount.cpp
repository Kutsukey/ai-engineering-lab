#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
using ll = long long;
using State = tuple<ll, int, int>;
const ll INF = 1e18;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    priority_queue<State, vector<State>, greater<State>> pq;
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, ll>>> adj(n + 1);
    vector<vector<ll>> dist(n + 1, vector<ll>(2, INF));
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }
    dist[1][0] = 0;
    pq.push({0, 1, 0});

    while (!pq.empty())
    {
        auto [d, u, state] = pq.top();
        pq.pop();

        if (d > dist[u][state])
        {
            continue;
        }

        for (auto &&[v, w] : adj[u])
        {
            if (state == 0)
            {
                if (d + w < dist[v][0])
                {
                    dist[v][0] = d + w;
                    pq.push({d + w, v, 0});
                }

                if (d + w / 2 < dist[v][1])
                {
                    dist[v][1] = d + w / 2;
                    pq.push({d + w / 2, v, 1});
                }
            }
            else
            {
                if (d + w < dist[v][1])
                {
                    dist[v][1] = d + w;
                    pq.push({d + w, v, 1});
                }
            }
        }
    }

    cout << dist[n][1] << '\n';

    return 0;
}

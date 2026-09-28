#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int INF = 1e9;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);
    vector<int> indeg(n + 1, 0);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        indeg[b]++;
    }

    vector<int> dp(n + 1, -INF);
    queue<int> q;

    for (int i = 1; i <= n; i++)
    {
        if (indeg[i] == 0)
        {
            q.push(i);
        }
    }

    vector<int> parent(n + 1, 0);
    dp[1] = 1;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (auto &&v : adj[u])
        {
            if (dp[u] != -INF && dp[u] + 1 > dp[v])
            {
                dp[v] = dp[u] + 1;
                parent[v] = u;
            }

            indeg[v]--;
            if (indeg[v] == 0)
            {
                q.push(v);
            }
        }
    }

    vector<int> path;
    for (int curr = n; curr != 0; curr = parent[curr])
    {
        path.push_back(curr);
    }
    reverse(path.begin(), path.end());

    if (dp[n] == -INF)
    {
        cout << "IMPOSSIBLE" << '\n';
        return 0;
    }
    cout << path.size() << '\n';
    for (int i = 0; i < (int)path.size(); i++)
    {
        cout << path[i] << " ";
    }
    cout << '\n';
    return 0;
}

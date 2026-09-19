#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using ll = long long;
using namespace std;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<int> col(n + 1, 0);
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i = 1; i <= n; i++)
    {
        if (col[i] == 0)
        {
            col[i] = 1;
            queue<int> q;
            q.push(i);
            while (!q.empty())
            {
                int u = q.front();
                q.pop();
                for (auto &&v : adj[u])
                {
                    if (col[v] == 0)
                    {
                        if (col[u] == 1)
                        {
                            col[v] = 2;
                            q.push(v);
                        }
                        else
                        {
                            col[v] = 1;
                            q.push(v);
                        }
                    }
                    else
                    {
                        if (col[u] == col[v])
                        {
                            cout << "IMPOSSIBLE" << '\n';
                            return 0;
                        }
                    }
                }
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        cout << col[i] << " ";
    }

    cout << '\n';
    return 0;
}

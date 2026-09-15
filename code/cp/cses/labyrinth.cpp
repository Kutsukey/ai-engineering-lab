#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>

const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};
const char dir[4] = {'R', 'L', 'D', 'U'};

using namespace std;
using ll = long long;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<string> grid(n);
    pair<int, int> start, end_pos;

    for (int i = 0; i < n; i++)
    {
        cin >> grid[i];

        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 'A')
            {
                start = {i, j};
            }
            if (grid[i][j] == 'B')
            {
                end_pos = {i, j};
            }
        }
    }

    vector<vector<bool>> vis(n, vector<bool>(m, false));
    vector<vector<int>> parent(n, vector<int>(m, -1));

    queue<pair<int, int>> q;
    q.push(start);
    vis[start.first][start.second] = true;

    bool found = false;

    while (!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();

        if (x == end_pos.first && y == end_pos.second)
        {
            found = true;
            break;
        }

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m)
            {
                if (grid[nx][ny] != '#' && !vis[nx][ny])
                {
                    vis[nx][ny] = true;
                    parent[nx][ny] = i;
                    q.push({nx, ny});
                }
            }
        }
    }

    if (!found)
    {
        cout << "NO\n";
    }
    else
    {
        cout << "YES\n";
        string path = "";
        pair<int, int> cur = end_pos;

        while (cur != start)
        {
            int p = parent[cur.first][cur.second];
            path += dir[p];
            cur.first -= dx[p];
            cur.second -= dy[p];
        }

        reverse(path.begin(), path.end());

        cout << path.size() << '\n';
        cout << path << '\n';
    }

    return 0;
}

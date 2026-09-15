#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};

using namespace std;
using ll = long long;

int n, m;
vector<string> grid;
vector<vector<bool>> vis;

void dfs(int x, int y)
{
    vis[x][y] = true;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && nx < n && ny >= 0 && ny < m)
        {
            if (grid[nx][ny] == '.' && !vis[nx][ny])
            {
                dfs(nx, ny);
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    grid.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> grid[i];
    }
    vis.assign(n, vector<bool>(m, false));

    int rooms = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == '.' && !vis[i][j])
            {
                rooms++;
                dfs(i, j);
            }
        }
    }
    cout << rooms << '\n';
    return 0;
}

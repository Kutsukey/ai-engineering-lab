#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

using namespace std;

vector<vector<int>> vis;
vector<string> grid;
int n, m;
void dfs(int x, int y)
{
    vis[x][y] = true;

    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] != '#' && !vis[nx][ny])
        {
            dfs(nx, ny);
        }
    }
}

int startX, startY;
queue<pair<int, int>> q;
q.push({startX, startY});
vis[startX][startY] = true;

while (!q.empty())
{
    auto [x, y] = q.front();
    q.pop();

    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] != '#' && !vis[nx][ny])
        {
            vis[nx][ny] = true;
            q.push({nx, ny});
        }
    }
}

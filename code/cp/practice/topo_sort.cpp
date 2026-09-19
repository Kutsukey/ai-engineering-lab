#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<vector<int>> adj;
vector<int> indegree;

void init(int a, int b)
{
    adj[a].push_back(b);
    indegree[b]++;
}

queue<int> q;
vector<int> order;

for (int i = 1; i < indegree.size(); i++)
{
    if (indegree[i] == 0)
    {
        q.push(i);
    }
}

while (!q.empty())
{
    int a = q.front(); // front en ön!
    q.pop();
    order.push_back(a);
    for (auto &&v : adj[a])
    {
        indegree[v]--;
        if (indegree[v] == 0)
        {
            q.push(v);
        }
    }
}

if (order.size() != n)
{
    cout << "IMPOSSIBLE";
}
else
{
    for (auto &&i : order)
    {
        cour << order << " ";
    }
}
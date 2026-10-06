#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    vector<int> c(m * (m + 1) / 2 + 1);
    for (int i = 1; i <= m * (m + 1) / 2; i++)
    {
        cin >> c[i];
    }

    ll ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int pos = (m * (m - 1) / 2) + a[i];
        int row = m;
        while (row != 1)
        {
            if ((pos - row) < ((row - 2) * (row - 1) / 2) or (pos - row + 1) > ((row - 1) * (row) / 2))
            {
                ans += c[pos - row + 1];
                pos = pos - row + 1;
                row--;
                cout << pos << " ";
                continue;
            }

            if ((pos - row + 1) > ((row - 1) * (row) / 2))
            {
                ans += c[pos - row];
                pos = pos - row;
                row--;
                cout << pos << " ";
                continue;
            }

            if (c[pos - row] > c[pos - row + 1])
            {
                ans += c[pos - row + 1];
                pos = pos - row + 1;
                row--;
                cout << pos << " ";
            }
            else
            {
                ans += c[pos - row];
                pos = pos - row;
                row--;
                cout << pos << " ";
            }
        }
    }

    cout << ans << '\n';

    return 0;
}

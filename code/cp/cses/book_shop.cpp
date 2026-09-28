#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(int argc, char const *argv[])
{
    int n, x;
    cin >> n >> x;
    vector<int> dp(x + 1, 0);

    vector<int> price(n);
    vector<int> pages(n);
    for (int i = 0; i < n; i++)
        cin >> price[i];
    for (int i = 0; i < n; i++)
        cin >> pages[i];

    for (int i = 0; i < n; i++)
    {
        for (int w = x; w >= price[i]; w--)
        {
            dp[w] = max(dp[w], dp[w - price[i]] + pages[i]);
        }
    }
    cout << dp[x] << '\n';
    return 0;
}

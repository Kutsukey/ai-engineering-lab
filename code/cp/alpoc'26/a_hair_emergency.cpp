#include <bits/stdc++.h>

using namespace std;
using ll = long long;

bool check(ll mid, ll l, ll c, ll max)
{
    ll score = mid * (l - (c * mid));
    return score > max;
}

// 18 2
// 0 16 28 36 40 40 28 16 0

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        int l, c;
        cin >> l >> c;
        ll max = 0; // 40
        ll score = 0;
        ll lo = 0;
        ll hi = l / c + 1; //
        while (lo <= hi)
        {
            ll mid = (lo + hi) / 2;
            if (check(mid, l, c, max))
            {
                max = mid * (l - (c * mid));
                hi = mid - 1;
            }
            else
            {
                lo = mid + 1;
            }
        }
        cout << max << '\n';
    }

    return 0;
}

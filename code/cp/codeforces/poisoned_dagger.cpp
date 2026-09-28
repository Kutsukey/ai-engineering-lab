#include <bits/stdc++.h>

using namespace std;
using ll = long long;

bool check(ll k, const vector<ll> &a, ll h, int n)
{
    ll dmg = 0;
    for (int i = 0; i < n - 1; i++)
    {
        dmg += min(k, a[i + 1] - a[i]);
    }
    dmg += k;
    return dmg >= h;
}

void solve(int n, ll h, const vector<ll> &a)
{
    ll low = 1;
    ll high = h;
    ll ans = h;

    while (low <= high)
    {
        ll mid = (low + high) / 2;
        if (check(mid, a, h, n))
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    cout << ans << '\n';
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        ll h;
        cin >> n >> h;
        vector<ll> a(n);
        for (int i = 0; i < n; i++)
        {
            ll b;
            cin >> b;
            a[i] = b;
        }

        solve(n, h, a);
    }

    return 0;
}
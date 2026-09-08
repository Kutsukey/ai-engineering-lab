#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using ll = long long;

bool check(ll mid, vector<ll> &a, ll k)
{
    ll move = 0;
    for (size_t i = a.size() / 2; i < a.size(); i++)
    {
        if (mid > a[i])
        {
            move += mid - a[i];
        }
    }
    return k >= move;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    ll k;
    ll left = 1;
    ll right = 1;
    cin >> n >> k;
    vector<ll> a(n);

    for (size_t i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    right = a[n / 2] + k;
    left = a[n / 2];
    ll median = (left + a[n - 1]) / 2;
    ll ans = 1;
    while (left <= right)
    {
        ll mid = (left + right) / 2;
        if (!check(mid, a, k))
        {
            right = mid - 1;
        }
        else
        {
            ans = mid;
            left = mid + 1;
        }
    }

    cout << ans << '\n';

    return 0;
}

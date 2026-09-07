#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

bool check(ll mid, const vector<ll> &k, ll t)
{
    ll current = 0;
    for (auto a : k)
    {
        current += mid / a;
        if (current >= t) return true;
    }

    return current >= t;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    ll t;
    cin >> n >> t;

    vector<ll> k(n);
    ll min_k = 1e9 + 7;
    for (int i = 0; i < n; i++) {
        cin >> k[i];
        min_k = min(min_k, k[i]);
    }

    ll left = 1;
    ll right = min_k * t;
    ll ans = right;

    while (left <= right) {
        ll mid = left + (right - left) / 2;
        if (check(mid, k, t)) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    cout << ans << '\n';

    return 0;
}
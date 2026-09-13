#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using ll = long long;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin >> n;
    vector<ll> x(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> x[i];
    }
    ll current = 0;
    ll ans = x[0];
    for (ll i = 0; i < n; i++)
    {
        current = max(x[i], current + x[i]);
        ans = max(ans, current);
    }
    cout << ans << '\n';

    return 0;
}
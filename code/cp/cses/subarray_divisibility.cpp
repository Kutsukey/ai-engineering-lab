#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;
using ll = long long;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    ll ans = 0;
    ll curr = 0;
    vector<int> div(n, 0);
    div[0] = 1;

    div[0] = 1;

    for (ll i = 0; i < n; i++)
    {
        curr += a[i];
        ll rem = ((curr % n) + n) % n;
        ans += div[rem];
        div[rem]++;
    }

    cout << ans << '\n';

    return 0;
}

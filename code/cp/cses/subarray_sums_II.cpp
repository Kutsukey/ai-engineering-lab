#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;
using ll = long long;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    ll x;
    cin >> n >> x;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    ll ans = 0;
    map<ll, int> sum;
    sum[0] = 1;
    ll cur = 0;

    for (int i = 0; i < n; i++)
    {
        cur += a[i];
        if (sum.count(cur - x))
        {
            ans += sum[cur - x];
        }
        sum[cur]++;
    }

    cout << ans << '\n';

    return 0;
}

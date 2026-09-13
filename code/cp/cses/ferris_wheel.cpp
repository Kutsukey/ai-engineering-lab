#include <iostream>
#include <algorithm>
#include <vector>

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
    sort(a.begin(), a.end());
    ll ans = 0;
    int j = n - 1;
    for (int i = 0; i <= j;)
    {
        ll sum = a[i] + a[j];
        if (sum <= x)
        {
            i++;
            j--;
        }else{
            j--;
        }
        ans++;
    }
    cout << ans << '\n';

    return 0;
}

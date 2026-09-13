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

    int n, q;
    cin >> n >> q;
    vector<ll> x(n);
    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
    }
    vector<ll> pref(n + 1, 0);
    ll curr = 0;
    pref[0] = 1;
    for (int i = 0; i < n; i++)
    {
        curr += x[i];
        pref[i] = curr;
    }

    ll a = 0;
    ll b = 0;
    for (int i = 0; i < q; i++)
    {
        cin >> a >> b;
        cout << (pref[b] - pref[a]) << '\n';
    }

    return 0;
}

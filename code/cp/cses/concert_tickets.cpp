#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;
using ll = long long;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    multiset<ll> h;
    vector<ll> t(m);
    for (int i = 0; i < n; i++)
    {
        ll a;
        cin >> a;
        h.insert(a);
    }
    for (int i = 0; i < m; i++)
    {
        ll t;
        cin >> t;

        auto it = h.upper_bound(t);

        if (it == h.begin())
        {
            cout << -1 << '\n';
        }
        else
        {
            --it;
            cout << *it << '\n';
            h.erase(it);
        }
    }

    return 0;
}

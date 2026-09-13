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
    vector<ll> k(n+1);
    for (int i = 1; i <= n; i++)
    {
        cin >> k[i];
    }
    int left = 1;
    map<ll, int> last_seen;
    int ans = 0;

    for (int right = 1; right <= n; right++)
    {
        ll x = k[right];
        if (last_seen.count(x))
        {
            left = max(left, last_seen[x] + 1);
        }
        last_seen[x] = right;
        ans = max(ans, right - left + 1);
    }
    cout << ans << '\n';
    return 0;
}

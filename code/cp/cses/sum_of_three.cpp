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

    vector<pair<ll, int>> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a.begin(), a.end());
    ll low = 0;
    ll high = n - 1;
    for (int i = 0; i < n; i++)
    {
        low = i + 1;
        high = n - 1;
        while (low < high)
        {
            ll sum = a[i].first + a[low].first + a[high].first;
            if (sum == x)
            {
                std::cout << ++a[i].second << ' ' << ++a[low].second << ' ' << ++a[high].second << '\n';
                return 0;
            }
            else if (sum > x)
            {
                high--;
            }
            else if (sum < x)
            {
                low++;
            }
        }
    }
    std::cout << "IMPOSSIBLE" << '\n';

    return 0;
}

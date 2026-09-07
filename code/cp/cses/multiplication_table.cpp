#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

ll check(ll mid, const ll n)
{
    ll count = 0;

    for (ll i = 1; i <= n; i++)
    {
        if (mid / i > n)
        {
            count += n;
        }
        else
        {
            count += mid / i;
        }

        if (mid < i)
        {
            return count;
        }
    }
    return count;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin >> n;

    ll right = n * n;
    ll left = 1;
    ll ans = 0;
    ll target = (n*n+1)/2;
    while (left <= right)
    {
        ll mid = (left + right) / 2;
        if (check(mid, n) >= target)
        {
            ans = mid;
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }

    std::cout << ans << '\n';

    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

bool check(ll mid, const vector<ll>& a, ll k){
    ll pieces = 1;
    ll current_sum = 0;

    for (ll x : a)
    {
        if (current_sum + x > mid)
        {
            pieces++;
            current_sum = x;
        }else{
            current_sum += x;
        }
        
    }
    return pieces <= k;    
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    ll k;
    cin >> n >> k;

    vector<ll> a(n);
    ll left = 0;
    ll right = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        left = max(left, a[i]);
        right += a[i];
    }

    ll ans = right;


    while (left <= right)
    {
        ll mid = (left + right) / 2;

        if (check(mid,a,k))
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
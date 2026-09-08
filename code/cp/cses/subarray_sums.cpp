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
    ll count = 0;
    ll sum = 0;
    ll left = 0;
    ll right = 0;
    while (right < n)
    {
        sum += a[right];
        while (sum > x && left <= right)
        {
            sum -= a[left];
            left++;
        }
        if (sum == x)
        {
            count++;
        }
        right++;
    }
    cout << count << '\n';

    return 0;
}

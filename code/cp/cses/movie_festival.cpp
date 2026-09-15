#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

struct Movie
{
    ll start;
    ll end;
};

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<Movie> x(n);
    for (int i = 0; i < n; i++)
    {
        ll a, b;
        cin >> a >> b;
        x[i].start = a;
        x[i].end = b;
    }

    sort(x.begin(), x.end(), [](const Movie &a, const Movie &b)
         { return a.end < b.end; });

    ll last_end = 0;
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (x[i].start >= last_end)
        {
            last_end = x[i].end;
            ans++;
        }
    }
    cout << ans << '\n';
    return 0;
}

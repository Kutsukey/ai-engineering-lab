#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

struct Task
{
    ll dur;
    ll end;
};

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<Task> x(n);
    for (int i = 0; i < n; i++)
    {
        ll a, b;
        cin >> a >> b;
        x[i].dur = a;
        x[i].end = b;
    }

    sort(x.begin(), x.end(), [](const Task &a, const Task &b)
         { return a.dur < b.dur; });


    ll f = 0;
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        f += x[i].dur;
        ans += x[i].end - f; 
    }
    cout << ans << '\n';
    
    return 0;
}

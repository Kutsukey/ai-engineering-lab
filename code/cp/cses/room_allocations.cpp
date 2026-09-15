#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
using ll = long long;
using ii = pair<int, int>;

struct Customer
{
    int start, end, id;
};

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<Customer> x(n);
    for (int i = 0; i < n; i++)
    {
        cin >> x[i].start >> x[i].end;
        x[i].id = i;
    }

    sort(x.begin(), x.end(), [](const Customer a, Customer b)
         { return a.start < b.start; });

    ll total_rooms = 0;
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    vector<ll> room_assigned(n);
    for (auto c : x)
    {
        if (!pq.empty() && pq.top().first < c.start)
        {
            int room = pq.top().second;
            pq.pop();
            room_assigned[c.id] = room;
            pq.push({c.end, room});
        }
        else
        {
            total_rooms++;
            room_assigned[c.id] = total_rooms;
            pq.push({c.end, total_rooms});
        }
    }
    cout << total_rooms << '\n';
    for (auto c : room_assigned)
    {
        cout << c << ' ';
    }
    cout << '\n';
    return 0;
}
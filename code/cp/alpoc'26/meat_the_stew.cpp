#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct Meat
{
    int arr, free;
    int piece = 0;
};

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<Meat> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].arr;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].free;
    }

    sort(a.begin(), a.end(), [](Meat a, Meat b)
         { return a.arr < b.arr; });

    int time = a[0].arr + a[0].free;
    int k = 0;
    while (k < m)
    {
        for (auto &&meat : a)
        {
            if (time = meat.arr + meat.free)
            {
                meat.piece++;
            }

            if (time > meat.arr + meat.free)
            {
                if (time - meat.arr % meat.free and meat.piece >= 1)
                {
                    meat.piece *= 2;
                    k += meat.piece;
                }
            }
        }
        time++;
    }

    if (k > m)
    {
        cout << -1 << endl;
        return 0;
    }

    cout << time - 1 << '\n';
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e6;
int divs[MAX + 1];

void precompute()
{
    for (int i = 1; i <= MAX; i++)
    {
        for (int j = i; j <= MAX; j += i)
        {
            divs[j]++;
        }
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    precompute();
    int n;
    cin >> n;
    while (n--)
    {
        int x;
        cin >> x;
        cout << divs[x] << '\n';
    }

    return 0;
}
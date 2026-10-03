#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll factorial(ll n)
{
    ll ans = 1;
    if (n == 1 or n == 0)
    {
        return 1;
    }
    for (ll i = 2; i < n; i++)
    {
        ans *= i;
    }
    return ans;
}

bool primeCheck(ll n)
{
    if (n == 2 or n == 3)
    {
        return true;
    }

    if (n % 2 == 0)
    {
        return false;
    }

    if (n % 3 == 0)
    {
        return false;
    }

    for (ll i = 5; i * i <= n; i = i + 6)
    {
        if (n % i == 0 or n % (i + 2) == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    ll n;
    cin >> n;
    bool prime = false;
    // check if n prime
    if (primeCheck(n))
    {
        prime = true;
    }

    // if rule 2 applies reverse
    if ((factorial(n - 1) + 1) % n != 0)
    {
        prime = !prime;
    }

    if (prime)
    {
        cout << "YES" << '\n';
    }
    else
    {
        cout << "NO" << '\n';
    }

    // Solution: All inputs are yes no need for check

    return 0;
}

#include <iostream>
#include <string>
#include <vector>

#define ll long long int
const ll mod = 1e9 + 7;

ll power(ll x, ll y, ll p)
{
    // (x^y) mod p
    ll res = 1;
    x %= p;
    while (y)
    {
        if (y & 1)
            res = (res * x) % p;
        y >>= 1;
        x = (x * x) % p;
    }
    return res;
}

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    int res = 0;
    int d = 5;
    while (n / d)
    {
        res += n / d;
        d *= 5;
    }
    cout << res << endl;
}
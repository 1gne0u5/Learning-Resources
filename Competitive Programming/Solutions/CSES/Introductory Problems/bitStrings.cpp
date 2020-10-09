//https://cses.fi/problemset/task/1617
#include <iostream>
#include <string>
#include <vector>

#define ll long long int

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll mod = 1e9 + 7;
    ll n;
    cin >> n;
    ll b = 2;
    ll a = 1;
    while (n)
    {
        if (n & 1)
        {
            a *= b;
            a %= mod;
        }
        b *= b;
        b %= mod;
        n >>= 1;
    }
    cout << a << endl;
}
//https://cses.fi/problemset/task/1754

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
void swap(int &a, int &b)
{
    int t = a;
    a = b;
    b = t;
}

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t)
    {
        int a, b;
        cin >> a >> b;
        if (a < b)
        {
            swap(a, b);
        }
        if (a > 2 * b)
        {
            cout << "NO" << endl;
        }
        else
        {
            if ((a + b) % 3 == 0)
            {
                cout << "YES" << endl;
            }
            else
            {
                cout << "NO" << endl;
            }
        }
        t--;
    }
}
//Great explanation of the problem
//https://discuss.codechef.com/t/coin-piles-problem-from-cses/28647/7

//if a > 2*b then a can not be reduced to a zero before b even after substracting 2 from it every time
// (a + b)%3 == 0
// 1x + 2y = a
// 1y + 2x = b
// 2a - b = 3x
// 2b - a = 3y
// a + b = 3(x + y)
// hence a + b have to be divisible by 3
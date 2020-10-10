// https://cses.fi/problemset/task/1092
#include <iostream>
#include <string>
#include <vector>
#define ll long long int

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //n(n+1)/2
    ll n;
    cin >> n;
    vector<ll> l1, l2;
    ll s = n * (n + 1) / 2;
    if (s % 2 == 0)
    {
        cout << "YES" << endl;
        ll su = s / 2;
        for (ll i = n; i > 0; i--)
        {
            if (su - i >= 0)
            {
                su -= i;
                l1.push_back(i);
            }
            else
            {
                l2.push_back(i);
            }
        }
        cout << l1.size() << endl;
        for (auto i : l1)
        {

            cout << i << " ";
        }
        cout << endl;
        cout << l2.size() << endl;
        for (auto i : l2)
        {
            cout << i << " ";
        }
    }
    else
    {
        cout << "NO" << endl;
    }
}
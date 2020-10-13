#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <utility>
using namespace std;




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
ll fact(ll n){
    ll ans=1;
    for(int i=1; i<=n;i++){
        ans*=i;
    }
    return ans;
}

ll m=1e9;

void diff(int i, int n, int l[], ll w1, ll w2){
    if (i==n){
         m=min(m,abs(w1-w2));
    }
    else{
        diff(i+1, n, l, w1+l[i], w2);
        diff(i+1, n, l, w1, w2+l[i]);
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    int l[n];
    for (int i=0; i<n; i++){
        cin>>l[i];
    }
    diff(0, n, l, 0, 0);
    cout<<m<<endl;
}
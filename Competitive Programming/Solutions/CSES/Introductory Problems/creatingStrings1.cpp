//https://cses.fi/problemset/task/1622
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

set<string> perms;


void permute(int l, int r, string s){
    if (l == r){
        perms.insert(s);
    }
    else{
        for (int i=l; i < r; i++){
            if (i==l){
                permute(l+1, r, s);
            }
            else{
                if (s[l] != s[i]){
                    swap(s[l], s[i]);
                    permute(l+1, r, s);
                    swap(s[i], s[l]);
                }

            }
            
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin>>s;
    int n= s.length();
    permute(0, n, s);
    
    
    cout<<perms.size()<<endl;
    for (auto i: perms){
        cout<<i<<endl;
    }
}
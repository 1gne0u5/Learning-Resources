//https://cses.fi/problemset/task/1755/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin>>s;
    
    int f=0;
    int l[26] ={0};
    for (int i=0; i<s.length();i++){
        l[s[i]-'A']++;
    }

    string s1, s2, t = "";
    for (int i=0; i<26; i++){
        if (l[i]%2==0){
            for (int j=0; j<l[i]/2; j++){
                    s1+=(i+'A');
                }
        }
        else{
            if (t==""){
                t=i+'A';
                for (int j=0; j<l[i]/2; j++){
                    s1+=(i+'A');
                }
                
            }
            else{
                f=1;
                break;
            }
        }
    }
    if (f==0){
        cout<<s1+t;
        reverse(s1.begin(), s1.end());
        cout<<s1<<endl;
    }
    else{
        cout<<"NO SOLUTION"<<endl;
    }

}
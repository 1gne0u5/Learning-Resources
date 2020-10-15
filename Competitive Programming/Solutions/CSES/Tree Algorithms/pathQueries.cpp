#include<bits/stdc++.h>
using namespace std;
 
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
 
/* // Ordered Set
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;
template<typename T>
typedef tree<T, null_type,less<T>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;
#define os_find(k) find_by_order(k)
#define os_order(k) order_of_key(k)
*/
 
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;
typedef vector<int> vi;
typedef vector<long long> vll;
#define f0(i,a,b) for(int i=a;i<b;i++)
#define f1(i,a,b) for(int i=a;i<=b;i++)
#define f2(i,a,b) for(int i=a;i>b;i--)
#define f3(i,a,b) for(int i=a;i>=b;i--)
#define all(a) a.begin(),a.end()
#define pb push_back
#define pii pair<int,int>
// #define int long long
#define fi first
#define se second
#define mod 1000000007
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define make_graph(k) int x,y; f0(i,0,k){cin>>x>>y; adj[x].pb(y); adj[y].pb(x);}
#define test int t;cin>>t;while(t--)
 
int binExp(int x,int n)
{
    int res=1;
    while(n)
    {
        if(n&1) res=(res*x)%mod;
        x=(x*x)%mod;
        n>>=1;
    }
    return res;
}
 
// int fact[100001];
// int modInv(int i) {return binExp(i,mod-2);}
// int ncr(int n,int r) {return (n>=r?(fact[n]*modInv(fact[r]))%mod*modInv(fact[n-r])%mod:0);}
 
int n,q;
vi adj[200001];
bool vis[200001];
int tim;
int tin[200001];
int tout[200001];
ll ftree[400001];
int v[200001];
ll bit[400001];
 
void update(int i, int val)
{
    while(i<=2*n)
    {
        bit[i] += val;
        i += i&(-i);
    }
}
 
ll sum(int i)
{
    ll ans = 0;
    while(i>0)
    {
        ans += bit[i];
        i -= i&(-i);
    }
    return ans;
}
 
void dfs(int u)
{
    vis[u] = 1;
    tin[u] = ++tim;
    ftree[tim] = v[u];
    for(auto x : adj[u])
    {
        if(!vis[x])
        {
            dfs(x);
        }
    }
    tout[u] = ++tim;
    ftree[tim] = -v[u];
}
 
signed main()
{
    // fast
 
    #ifndef ONLINE_JUDGE
        freopen("inputf.in","r",stdin);
        freopen("outputf.in","w",stdout);
    #endif
 
    cin>>n>>q;
 
    f1(i,1,n) cin>>v[i],vis[i] = 0;
    make_graph(n-1);
 
    tim = 0;
    ftree[0] = 0;
    dfs(1);
    f1(i,1,2*n)
    {
        update(i,ftree[i]);
    }
    // f1(i,1,2*n) cout<<ftree[i]<<' '; cout<<'\n';
    // f1(i,1,2*n) cout<<bit[i]<<' '; cout<<'\n';
 
    int type,s;
    while(q--)
    {
        cin>>type;
        if(type == 1)
        {
            cin>>s>>x;
            update(tin[s],x-v[s]);
            update(tout[s],v[s]-x);
            v[s] = x;
            ftree[tin[s]] = x;
            ftree[tout[s]] = -x;
        }
        else
        {
            cin>>s;
 
            cout<<sum(tin[s])<<'\n';
        }
    }
}
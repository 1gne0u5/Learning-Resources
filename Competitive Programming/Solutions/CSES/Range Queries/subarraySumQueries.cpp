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
#define int long long
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
 
int n,m;
int segbase[200001];
pair<pair<int,int>,pair<int,int> > segtree[800000]; // max subarray sum, total sum of range, max prefix, max suffix
 
pair<pair<int,int>,pair<int,int> > combine(pair<pair<int,int>,pair<int,int> > x, pair<pair<int,int>,pair<int,int> > y)
{
    pair<pair<int,int>,pair<int,int> > res;
    res.fi.se = x.fi.se+y.fi.se;
    res.se.fi = max(x.se.fi, x.fi.se+y.se.fi);
    res.se.se = max(y.se.se, y.fi.se+x.se.se);
    res.fi.fi = max({x.fi.fi, y.fi.fi, x.se.se+y.se.fi});
    return res;
}
 
void build(int node, int cl, int cr)
{
    if(cl == cr)
    {
        int k = segbase[cl];
        k = max(0ll,k);
        segtree[node] = {{k,segbase[cl]},{k,k}};
        return;
    }
 
    int cm = (cl+cr)/2;
    build(2*node, cl, cm);
    build(2*node+1, cm+1, cr);
    segtree[node] = combine(segtree[2*node], segtree[2*node+1]);
}
 
void update(int node, int cl, int cr, int idx, int val)
{
    if(idx < cl || cr < idx)
    {
        return;
    }
    if(cl==cr)
    {
        segbase[cl] = val;
        int k = segbase[cl];
        k = max(0ll,k);
        segtree[node] = {{k,segbase[cl]},{k,k}};
        return;
    }
 
    int cm = (cl+cr)/2;
    update(2*node, cl, cm, idx, val);
    update(2*node+1, cm+1, cr, idx, val);
    segtree[node] = combine(segtree[2*node], segtree[2*node+1]);
}
 
signed main()
{
    fast
 
    #ifndef ONLINE_JUDGE
        freopen("inputf.in","r",stdin);
        freopen("outputf.in","w",stdout);
    #endif
 
    cin>>n>>m;
 
    f0(i,0,n) cin>>segbase[i];
    build(1,0,n-1);
 
    int k,x;
    while(m--)
    {
        cin>>k>>x;
        update(1,0,n-1,k-1,x);
        cout<<segtree[1].fi.fi<<'\n';
    }
}
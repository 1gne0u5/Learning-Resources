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
 
int n,q;
map<int,int> coltoidx; // color to index
int x[200001];
int bit[200001];
int last_visit[200001];
 
void update(int i, int val)
{
    while(i <= n)
    {
        bit[i] += val;
        i += i&(-i);
    }
}
 
int sum(int i)
{
    int res = 0;
    while(i>0)
    {
        res += bit[i];
        i -= i&(-i);
    }
    return res;
}
 
signed main()
{
    fast
 
    #ifndef ONLINE_JUDGE
        freopen("inputf.in","r",stdin);
        freopen("outputf.in","w",stdout);
    #endif
 
    cin>>n>>q;
 
    memset(bit,0,sizeof(bit));
    memset(last_visit,0,sizeof(last_visit));
    map<int,int> m;
    f1(i,1,n) cin>>x[i], m[x[i]] = 0;
    int c = 0;
    for(auto &z : m)
    {
        z.se = ++c;
    }
    f1(i,1,n) x[i] = m[x[i]];
 
    int l,r;
    vector<pair<pii,int> > queries(q);
    f0(i,0,q)
    {
        cin>>l>>r;
        queries[i] = {{l,r}, i};
    }
 
    l = n+1;
    sort(all(queries), greater<pair<pii,int> >());
 
    int ans[q];
    for(auto qu : queries)
    {
        while(l > qu.fi.fi)
        {
            l--;
            if(last_visit[x[l]]!=0)
            {
                update(last_visit[x[l]],-1);
            }
            update(l,1);
            last_visit[x[l]] = l;
        }
        ans[qu.se] = sum(qu.fi.se);
 
        // f1(i,1,n) cout<<bit[i]<<' '; cout<<'\n';
    }
    f0(i,0,q) cout<<ans[i]<<'\n';
}
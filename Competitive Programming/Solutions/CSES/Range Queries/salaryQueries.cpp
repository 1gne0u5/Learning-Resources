#include<bits/stdc++.h>
using namespace std;
 
/* // Ordered Set
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;
typedef tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;
#define os_find(k) find_by_order(k)
#define os_order(k) order_of_key(k)
*/
 
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;
typedef vector<int> vi;
#define f0(i,a,b) for(int i=a;i<b;i++)
#define f1(i,a,b) for(int i=a;i<=b;i++)
#define f2(i,a,b) for(int i=a;i>b;i--)
#define f3(i,a,b) for(int i=a;i>=b;i--)
#define all(a) a.begin(),a.end()
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
// #define int long long
#define fi first
#define se second
#define mod 1000000007
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define make_graph(k) int x,y; f0(i,0,k){cin>>x>>y; adj[x].pb(y); adj[y].pb(x);}
#define test int t;cin>>t;while(t--)
// int ncr(int n,int r) {return (fact[n]*modInv(fact[r]))%mod*modInv(fact[n-r])%mod;}
// int modInv(int i) {return binExp(i,mod-2);}
 
int n,q;
map<int,int> m;
int a[10000001];
int bit[10000001];
 
void update(int,int);
int query(int);
 
signed main()
{
    fast
 
    #ifndef ONLINE_JUDGE
        freopen("inputf.in","r",stdin);
        freopen("outputf.in","w",stdout);
    #endif
 
    cin>>n>>q;
    a[0] = 0;
    memset(bit,0,sizeof(bit));
 
    int x;
    f1(i,1,n)
    {
    	cin>>x;
    	a[i] = x;
    	m[x]++;
    }
 
    for(auto x : m)
    {
    	int bucketNo = (x.fi-1)/100 + 1;
    	// cout<<bucketNo<<' '<<x.se<<"\n";
    	update(bucketNo, x.se);
    }
 
    char op;
    int y;
    while(q--)
    {
    	cin>>op>>x>>y;
    	if(op == '!')
    	{
    		int bucketNo = (a[x]-1)/100 + 1;
    		m[a[x]]--;
    		update(bucketNo, -1);
    		a[x] = y;
    		m[a[x]]++;
    		update((y-1)/100 + 1, 1);
    	}
    	else
    	{
    		int lbucket = (x-1)/100 + 1;
    		int rbucket = (y-1)/100 + 1;
 
    		int sum = 0;
    		if(lbucket != rbucket)
    		{
    			sum = query(rbucket-1) - query(lbucket);
	    		// cout<<lbucket<<' '<<rbucket<<' '<<sum<<'\n';
 
 				auto it1 = m.lower_bound(x);
 				for(; it1 != m.end() && it1->fi <= lbucket*100; it1++)
 				{
 					sum += it1->se;
 				}
 
 				auto it2 = m.lower_bound((rbucket-1)*100+1);
 				for(; it2 != m.end() && it2->fi <= y; it2++)
 				{
 					sum += it2->se;
 				}
    		}
    		else
    		{
    			f1(i,x,y)
    			{
    				sum += m[i];
    			}
    		}
 
    		cout<<sum<<'\n';
    	}
    }
}
 
void update(int i, int val)
{
	while(i <= 10000000)
	{
		bit[i] += val;
		i += (i & (-i));
	}
}
 
int query(int i)
{
	int sum = 0;
	while(i > 0)
	{
		sum += bit[i];
		i -= (i & (-i));
	}
 
	return sum;
}
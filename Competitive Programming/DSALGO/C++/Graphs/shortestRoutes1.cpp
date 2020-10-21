#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
 
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
 
#define mem(dp,a)           memset(dp,a,sizeof dp)
#define rep(i,a,b)          for(ll i=a;i<b;i++)
#define pb(x)               push_back(x)
#define mp(x,y)             make_pair(x,y)
#define fastio              ios_base::sync_with_stdio(false);cin.tie(NULL)
#define F                   first
#define S                   second
#define all(v)              (v).begin(),(v).end()
#define pi					3.14159265359
ll INF=1e18+10;
ll MOD=1000000007;
 
const int N=1e5+10;
vector<pair<ll,ll>> adj[N]; // adjaceny list
ll d[N]; // distance array

// Dijkstra Algorithm
void dijkstra(int s)
{
    d[s]=0;
    priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> pq;
    pq.push(mp(0,s));
    while(!pq.empty())
    {
        int v=pq.top().S;
        ll dist=pq.top().F;
        pq.pop();
 
        if(dist==INF)
            return;
        if(dist>d[v])
            continue;
        for(auto edge : adj[v])
        {
            int to=edge.F;
            ll len=edge.S;
            if((len+dist)<d[to])
            {
                d[to]=len+dist;
                pq.push(mp(d[to],to));
            }
        }
    }
}
 
 
int main()
{
	// take input
    int n,m;cin>>n>>m;
 
    rep(i,0,m)
    {
        int a,b;cin>>a>>b;
        ll c;cin>>c;
        adj[a].pb(mp(b,c));
    }
	
	// initialize distance array with a very large number (as per Dijkstra Algorithm)
    rep(i,0,N)
    d[i]=INF;
 
	// source is city index 1
    dijkstra(1);
	
	// print shortes routes from source to every other city
    rep(i,1,n+1)
    cout<<d[i]<<" ";
}
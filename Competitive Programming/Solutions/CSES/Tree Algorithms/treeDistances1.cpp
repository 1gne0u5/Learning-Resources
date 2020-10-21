#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<vector<int>> adj; // for storing the tree
int f_end = -1, s_end = -2; // stores the first and second end of diameter
int mx;
void dfs(int v, int p, int d) // finds the diameter
{
    if (d > mx)
    {
        mx = d;
        if (s_end == -2)
            f_end = v;
        else
            s_end = v;
    }
    for (auto to : adj[v])
        if (to != p)
            dfs(to, v, d + 1);
}
 
// calculates the distance for each node from the source node
void dfs(int v, int p, int d, vector<int> &dis)
{
    dis[v] = d;
    for (auto to : adj[v])
        if (to != p)
            dfs(to, v, d + 1, dis);
}
 
int main()
{
    int n;
    cin >> n;
    adj.assign(n + 1, vector<int>());
    rep(i, 0, n - 1)
    {
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    mx = 0;
    dfs(1, -1, 0);
    s_end = -1, mx = 0;
    dfs(f_end, -1, 0);
    vector<int> dis1(n + 1), dis2(n + 1);
    dfs(f_end, -1, 0, dis1);
    dfs(s_end, -1, 0, dis2);
    rep(i, 1, n + 1)
    cout << max(dis1[i], dis2[i]) << " ";
}
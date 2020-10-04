//Problem Link
//https://www.codechef.com/problems/REVERSE


#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while(t){
    int m, n;
    cin>>n>>m;
    vector<pair<int, int>> adj[n];
    for (int i=0; i<m; i++){
        int u,v;
        cin>>u>>v;
        u-=1;
        v-=1;
        if (u==v){
            continue;
        }
        adj[u].push_back({v,0});
        adj[v].push_back({u,1});
    }
    vector<int> dist(n, 1e8);
    dist[0] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({dist[0], 0});
    while(!pq.empty()){
        int node = pq.top().second;
        pq.pop();
        for (auto i: adj[node]){
            int v = i.first;
            int w = i.second;
            if (dist[v] > dist[node]+w){
                dist[v] = dist[node]+w;
                pq.push({dist[v], v});
            }
        }
    }
    if (dist[n-1]==1e8){
        cout<<"-1"<<endl;
    }
    else{
    cout<<dist[n-1]<<endl;
    }
    }

}
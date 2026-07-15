#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<pair<long long,long long>>>adj(n+1);
    for(int i=0;i<m;i++){
        int u,v,wt;
        cin>>u>>v>>wt;
        adj[u].push_back({v,wt});
    }
    vector<long long>dist(n+1,1e18);
    // vector<int>parent(n+1,-1);
    // parent[1]=1;
    priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>>q;
    q.push({0,1});
    dist[1]=0;
    while(!q.empty()){
        long long node=q.top().second;
        long long distance=q.top().first;
        q.pop();
        if(distance > dist[node]) continue;
        for(auto it:adj[node]){
            long long adjnode=it.first;
            long long weight=it.second;
            if(distance+weight<dist[adjnode]){
                q.push({distance+weight,adjnode});
                dist[adjnode]=distance+weight;
                // parent[adjnode]=node;
            }
        }

    }
    for(int i=1;i<=n;i++){
            cout<<dist[i];
            if(i<n)cout<<' ';
    }
    return 0;

}
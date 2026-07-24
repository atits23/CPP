#include<bits/stdc++.h>
using namespace std;
void dfs(int node,vector<int>&can_reach,vector<vector<long long>>adj){
    can_reach[node]=1;
    for(auto it:adj[node]){
        if(can_reach[it]==-1){
            dfs(it,can_reach,adj);
        }
    }
}
int main(){
    long long n,m;
    cin>>n>>m;
    vector<long long>dist(n+1,-1e18);
    vector<pair<long long,pair<long long,long long>>>edges;
    vector<vector<long long>>reverse_adj(n+1);
    for(int i=0;i<m;i++){
        long long u,v,wt;
        cin>>u>>v>>wt;
        edges.push_back({u,{v,wt}});
        reverse_adj[v].push_back(u);
    }
    vector<int>can_reach(n+1,-1);
    dfs(n,can_reach,reverse_adj);
    dist[1]=0;
    for(int j=0;j<n-1;j++){
        for(int i=0;i<edges.size();i++){
        long long u=edges[i].first;
        long long v=edges[i].second.first;
        long long score=edges[i].second.second;
        if(dist[u] != -1e18 && score+dist[u]>dist[v]){
            dist[v]=score+dist[u];
        }
    }
    }
    for(int i=0;i<edges.size();i++){
        long long u=edges[i].first;
        long long v=edges[i].second.first;
        long long score=edges[i].second.second;
        if(dist[u] != -1e18 && can_reach[v]!=-1 && score+dist[u]>dist[v]){
            cout<<-1;
            return 0;
        }
    }
    cout<<dist[n];
    return 0;

}
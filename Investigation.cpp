#include<bits/stdc++.h>
using namespace std;
int mod=1e9+7;
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<pair<int,int>>>adj(n+1);
    for(int i=0;i<m;i++){
        int u,v,wt;
        cin>>u>>v>>wt;
        adj[u].push_back({v,wt});
    }
    vector<long long>dist(n+1,1e18);
    dist[1]=0;
    vector<int>count_ways(n+1,0);
    count_ways[1]=1;
    vector<int>min_edges(n+1,1e9);
    vector<int>max_edges(n+1,-1e9);
    min_edges[1]=0;
    max_edges[1]=0;
    priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>pq;
    pq.push({0,1});
    while(!pq.empty()){
        long long distance=pq.top().first;
        int node=pq.top().second;
        int min_edge=min_edges[node];
        int max_edge=max_edges[node];
        pq.pop();
        if(distance > dist[node]) continue;
        for(auto it:adj[node]){
            int v=it.first;
            int wt=it.second;
            if(distance+wt<dist[v]){
                dist[v]=distance+wt;
                count_ways[v]=count_ways[node];
            
                min_edges[v]=min_edge+1;
               
                max_edges[v]=max_edge+1;
                pq.push({distance+wt,v});
            }
            else if(distance+wt==dist[v]){
                count_ways[v]=(count_ways[v]+count_ways[node])%mod;
                if(min_edge+1<min_edges[v]){
                    min_edges[v]=min_edge+1;
                }
                if(max_edge+1>max_edges[v]){
                    max_edges[v]=max_edge+1;
                }

            }
        } 
    }
    cout<<dist[n]<<" "<<count_ways[n]<<" "<<min_edges[n]<<" "<<max_edges[n]<<endl;

}
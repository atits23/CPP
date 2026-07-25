#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<pair<int,int>>>adj(n+1);
    for(int i=0;i<m;i++){
        int u,v,wt;
        cin>>u>>v>>wt;
        adj[u].push_back({v,wt});
    }
    // vector<pair<int,int>>parent(n+1,{-1,0});
    vector<vector<long long>>dist(n+1,vector<long long>(2,1e18));
    dist[1][0]=0;
    priority_queue<pair<long long,pair<int,int>>,vector<pair<long long,pair<int,int>>>,greater<pair<long long,pair<int,int>>>>pq;
    pq.push({0,{1,0}});
    while(!pq.empty()){
        int node=pq.top().second.first;
        long long distance=pq.top().first;
        int state=pq.top().second.second;
        pq.pop();
        if (distance > dist[node][state]) continue;
        for(auto it :adj[node]){
            int v=it.first;
            long long wt=it.second;
            if(state==0){
                if(distance+wt<dist[v][0]){
                    dist[v][0]=distance+wt;
                    pq.push({distance+wt,{v,0}});
                }
                if(distance+wt/2<dist[v][1]){
                    dist[v][1]=distance+wt/2;
                    pq.push({distance+wt/2,{v,1}});
                }
            }
            else{
                if(distance+wt<dist[v][1]){
                    dist[v][1]=distance+wt;
                    pq.push({distance+wt,{v,1}});
                }
            }
        }
        
    }
    cout<<dist[n][1];
    return 0;

}
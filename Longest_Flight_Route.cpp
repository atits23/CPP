#include<bits/stdc++.h>
using namespace std;
void dfs(int node,vector<int>&visited,vector<int>&distance,vector<int>&next,vector<vector<int>>&adj){
    visited[node]=1;
    for(auto it:adj[node]){
        if(!visited[it]){
            dfs(it,visited,distance,next,adj);
        }
        if(distance[it]!=-1e9 && distance[it]+1>distance[node]){
            distance[node]=distance[it]+1;
            next[node]=it;
        }
    }
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>adj(n+1);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    vector<int>city(n+1,-1e9);
    vector<int>next(n+1,-1);
    vector<int>visited(n+1,0);
    city[n]=1;
    visited[n]=1;
    dfs(1,visited,city,next,adj);
    // priority_queue<pair<int,int>>pq;
    // pq.push({0,1});
    // while(!pq.empty()){
    //     int node=pq.top().second;
    //     int num_of_cities=pq.top().first;
    //     pq.pop();
    //     for(auto it:adj[node]){
    //         if(num_of_cities+1>city[it]){
    //             pq.push({num_of_cities+1,it});
    //             parent[it]=node;
    //             city[it]=num_of_cities+1;
    //         }
    //     }
    // }
    if(city[1]==-1e9){
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }
    vector<int>path;
    cout<<city[1]<<endl;
    int x=1;
    while(x!=n){
        path.push_back(x);
        x=next[x];
    }
    path.push_back(x);
    int s=path.size();
    for(int i=0;i<s;i++){
        cout<<path[i];
        if(i!=s-1)cout<<" ";
    }
    return 0;
}
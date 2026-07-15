#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>adj(n+1);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int>dist(n+1,1e9);
    vector<int>parent(n+1,-1);
    for(int i=1;i<=n;i++){
        parent[i]=i;
    }
    queue<int>q;
    q.push(1);
    dist[1]=0;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        for(auto it:adj[node]){
            int adjnode=it;
            if(dist[node]+1<dist[adjnode]){
                dist[adjnode]=dist[node]+1;
                parent[adjnode]=node;
                q.push(adjnode);
            }
        }
    }
    if(dist[n]==1e9){
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }
    cout<<dist[n]+1<<endl;
    vector<int>path;
    int node=n;
    while(parent[node]!=node){
        path.push_back(node);
        node=parent[node];
    }
    path.push_back(1);
    reverse(path.begin(),path.end());
    for(auto it:path){
        cout<<it<<" ";
    }
    cout<<endl;
}
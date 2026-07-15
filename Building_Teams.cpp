#include<bits/stdc++.h>
using namespace std;
bool dfs(int node,int col,vector<vector<int>>&adj,vector<int>&color){
    color[node]=col;
    for(auto it:adj[node]){
        if(color[it]==-1){
            if(!dfs(it,!col,adj,color)){
                return false;
            }
        }
        else{
            if(color[it]==col){
                return false;
            }
        }
    }
    return true;
}
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
    vector<int>color(n+1,-1);
    for(int i=1;i<=n;i++){
        if(color[i]==-1){
            if(!dfs(i,0,adj,color)){
                cout<<"IMPOSSIBLE"<<endl;
                return 0;
            }
        }
    }
    for(int i=1;i<=n;i++){
        cout<<color[i]+1<<" ";
    }
    cout<<endl;
}
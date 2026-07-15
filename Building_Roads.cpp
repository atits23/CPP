#include<bits/stdc++.h>
using namespace std;
void dfs(int node,vector<vector<int>>&adj,vector<int>&visited){
    visited[node]=1;
    for(auto it:adj[node]){
        if(!visited[it]){
            dfs(it,adj,visited);
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
        adj[v].push_back(u);
    }
    vector<int>visited(n+1,0);
    vector<int>answer;
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            answer.push_back(i);
            dfs(i,adj,visited);
        }
    }
    cout<<answer.size()-1<<endl;
    if(answer.size()==1){
        return 0;
    }
    for(auto it=answer.begin();it!=answer.end()-1;it++){
        cout<<*it<<" "<<*(it+1)<<endl;
    }
    cout<<endl;
}
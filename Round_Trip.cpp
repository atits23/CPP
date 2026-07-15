#include<bits/stdc++.h>
using namespace std;
bool dfs(int node,int par,int col,vector<vector<int>>&adj,vector<int>&visited,vector<int>&path,vector<int>&parent){
   visited[node]=1;
   parent[node]=par;
   for(auto it:adj[node]){
    if(it==par){
        continue;
    }
        if(visited[it]==0){
            if(dfs(it,node,!col,adj,visited,path,parent)){
                return true;
            }
        }
        else if(it!=par){
            path.push_back(it);
            int cur = node;
            while(cur!=it){
                path.push_back(cur);
                cur=parent[cur];
            }
            path.push_back(it);   // close the cycle
            reverse(path.begin(), path.end());
            return true;
        }
   }
   return false;
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
    vector<int>path;
    vector<int>parent(n+1,-1);
    for(int i=1;i<=n;i++){
        parent[i]=i;
    }

    for(auto it=1;it<=n;it++){
        if(visited[it]==0){
            if(dfs(it,-1,0,adj,visited,path,parent)){
                cout<<path.size()<<endl;
                for(auto it:path){
                    cout<<it<<" ";
                }
                cout<<endl;
                return 0;
            }
            else{
                path.clear();
            }
        }
    }
    cout<<"IMPOSSIBLE"<<endl;
    return 0;    

}
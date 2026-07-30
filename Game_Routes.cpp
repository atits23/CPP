#include<bits/stdc++.h>
const int mod =1e9+7;
using namespace std;
void dfs(int node,vector<int>&visited,vector<vector<int>>&adj,vector<long long>&count_ways){
    visited[node]=1;
    for(auto it:adj[node]){
        if(!visited[it]){
            dfs(it,visited,adj,count_ways);
        }
        count_ways[node] = (count_ways[node] + count_ways[it]) % mod;
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
    vector<long long>count_ways(n+1,0);
    vector<int>visited(n+1,0);
    count_ways[n]=1;
    visited[n]=1;
    dfs(1,visited,adj,count_ways);
    cout<<count_ways[1]<<endl;
    return 0;
}
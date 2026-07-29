#include<bits/stdc++.h>
using namespace std;
// bool dfs(int node,int parent,vector<int>&visited,vector<vector<pair<int,int>>>&adj,vector<int>&path){
//     visited[node]=1;
//     path.push_back(node);
//     for(auto it:adj[node]){
//         if(parent==it.first)continue;
//         if(visited[it.first]==-1){
//             if(dfs(it.first,node,visited,adj,path)){
//                 return true;
//             }
//         }
//         else if(parent!=it.first){
//             path.push_back(it.first);
//             return true;
//         }
//     }
//     path.pop_back();
//     return false;
// }
int main(){
    int n,m;
    cin>>n>>m;
    vector<pair<int,pair<int,long long>>>edges;
    for(int i=0;i<m;i++){
        int u,v;
        long long wt;
        cin>>u>>v>>wt;
        edges.push_back({u,{v,wt}});
    }
    vector<long long >dist(n+1,0);
    vector<int>parent(n+1,-1);
    for(int i=1;i<=n;i++){
        parent[i]=i;
    }
    for(int i=0;i<n-1;i++){
        for(int i=0;i<m;i++){
            int u=edges[i].first;
            int v=edges[i].second.first;
            long long wt=edges[i].second.second;
            if(dist[u]!=1e18 && dist[u]+wt<dist[v]){
                dist[v]=dist[u]+wt;
                parent[v]=u;
            }
        }
    }
    for(int i=0;i<m;i++){
            int u=edges[i].first;
            int v=edges[i].second.first;
            long long wt=edges[i].second.second;
            if(dist[u]!=1e18 && dist[u]+wt<dist[v]){
                dist[v]=dist[u]+wt;
                parent[v]=u;
                cout<<"YES"<<endl;
                vector<int>path;
                int x=v;
                for(int i=0;i<n;i++){
                    x=parent[x];
                }
                int z=x;
                do{
                    path.push_back(x);
                    x =parent[x];
                }while(x != z);
                path.push_back(x);
                reverse(path.begin(),path.end());
                for(int i=0;i<path.size();i++){
                    cout<<path[i];
                    if(i!=path.size()-1)cout<<" ";
                }
                return 0;
            }
    }
    cout<<"NO"<<endl;
    return 0;
}
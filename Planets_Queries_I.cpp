#include<bits/stdc++.h>
using namespace std;
int dfs(int node,int k,vector<vector<int>>&adj){
    if(k==0)return node;
    for(auto it:adj[node]){
        return dfs(it,k-1,adj);
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,q;
    cin>>n>>q;
    vector<vector<int>>up(n+1,vector<int>(30));
    for(int i=1;i<=n;i++){
        int v;
        cin>>v;
        up[i][0]=v;
    }
    for(int k=1;k<30;k++){
        for(int i=1;i<=n;i++){
            up[i][k]=up[up[i][k-1]][k-1];
        }
    }
    for(int i=0;i<q;i++){
        int x,k;
        cin>>x>>k;
        int j=0;
        for(int j=0; j<30; j++){
            if(k & (1<<j)){
            x = up[x][j];
        }
}
        cout<<x<<"\n";
    }
}
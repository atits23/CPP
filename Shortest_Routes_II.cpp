#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m,q;
    cin>>n>>m>>q;
    vector<vector<long long>>adj(n+1,vector<long long>(n+1,1e18));
    for(int i=0;i<m;i++){
        int u,v;
        long long wt;
        cin>>u>>v>>wt;
        adj[u][v]=min(adj[u][v],wt);
        adj[v][u]=min(adj[v][u],wt);
    }
    for(int i=1;i<=n;i++)adj[i][i]=0;

    for(int via=1;via<=n;via++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(adj[i][via]==1e18 || adj[via][j]==1e18) continue;
                if(i==via || j==via)continue;
                if(adj[i][via]+adj[via][j]<adj[i][j]){
                    adj[i][j]=adj[i][via]+adj[via][j];
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(adj[i][j]==1e18)adj[i][j]=-1;
        }
    }
    for(int i=0;i<q;i++){
        int city_1,city_2;
        cin>>city_1>>city_2;
        cout<<adj[city_1][city_2]<<endl;
    }
    return 0;


}
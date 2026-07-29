#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m,k;
    cin>>n>>m>>k;
    vector<vector<pair<int,long long>>>adj(n+1);
    for(int i=0;i<m;i++){
        int u,v;
        long long wt;
        cin>>u>>v>>wt;
        adj[u].push_back({v,wt});
    }
    vector<int>count(n+1,0);
    priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>pq;
    pq.push({0,1});
    vector<long long>ans;
    while(!pq.empty()){
        long long distance=pq.top().first;
        int node=pq.top().second;
        pq.pop();
        if(count[node]>=k)continue;
        count[node]++;
        if (node==n) {
            cout<<distance<< " ";
        }
        for(auto it:adj[node]){
            int v=it.first;
            long long wt=it.second;
            if(count[v]<k){
            pq.push({distance+wt,v});
            }
        }
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<char>>grid(n,vector<char>(m));
    int start_i,start_j=0;
    int end_i,end_j=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
            if(grid[i][j]=='A'){
                start_i=i;
                start_j=j;
            }
            if(grid[i][j]=='B'){
                end_i=i;
                end_j=j;
            }
        }
    }
    vector<vector<int>>dist(n,vector<int>(m,INT_MAX));
    vector<vector<pair<int,int>>>parent(n,vector<pair<int,int>>(m,{-1,-1}));
    dist[start_i][start_j]=0;
    queue<pair<int,int>>q;
    q.push({start_i,start_j});
    vector<int>delrows={-1,0,1,0};
    vector<int>delcols={0,1,0,-1};
    while(!q.empty()){
        int i=q.front().first;
        int j=q.front().second;
        q.pop();
        for(int k=0;k<4;k++){
            int nrow=i+delrows[k];
            int ncol=j+delcols[k];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]!='#' && dist[nrow][ncol]>dist[i][j]+1){
                dist[nrow][ncol]=dist[i][j]+1;
                parent[nrow][ncol]={i,j};
                q.push({nrow,ncol});
            }
        }
    }
    if(dist[end_i][end_j]==INT_MAX){
        cout<<"NO"<<endl;
    }
    else{
        cout<<"YES"<<endl;
        string path="";
        cout<<dist[end_i][end_j]<<endl;
        

        int x = end_i;
        int y = end_j;

        while(!(x==start_i && y==start_j))
        {
        auto p = parent[x][y];

        if(p.first == x-1) path += 'D';
        else if(p.first == x+1) path += 'U';
        else if(p.second == y-1) path += 'R';
        else path += 'L';

        x = p.first;
        y = p.second;
}

        reverse(path.begin(), path.end());
        cout<<path<<endl;
    }

}
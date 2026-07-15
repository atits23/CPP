#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<char>>grid(n,vector<char>(m,-1));
    vector<vector<int>>vis(n,vector<int>(m,1e9));
    queue<pair<pair<int,int>,int>>q;
    pair<int,int>start;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
            if(grid[i][j]=='M'){
                q.push({{i,j},0});
                vis[i][j]=0;
            }
            else if(grid[i][j]=='A'){
                start.first=i;
                start.second=j;
            }
        }
    }
    
    int delrows[]={0,-1,0,1};
    int delcols[]={-1,0,1,0};
    while(!q.empty()){
        int x=q.front().first.first;
        int y=q.front().first.second;
        int time=q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int nrow=x+delrows[i];
            int ncol=y+delcols[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]!='#' && time+1<vis[nrow][ncol]){
                q.push({{nrow,ncol},time+1});
                vis[nrow][ncol]=time+1;
            }
        }
    }
    vector<vector<pair<int,int>>>parent(n,vector<pair<int,int>>(m,{-1,-1}));
    queue<pair<pair<int,int>,int>>p;
    p.push({start,0});
    parent[start.first][start.second]=start;
    while(!p.empty()){
        int x=p.front().first.first;
        int y=p.front().first.second;
        int time=p.front().second;
        if(x==0 || x==n-1 || y==m-1 || y==0){
            cout<<"YES"<<endl;
            cout<<time<<endl;
            string path="";
            int x1=x;
            int y1=y;
            while(make_pair(x1,y1)!=start){
            int i=parent[x1][y1].first;
            int j=parent[x1][y1].second;
            if(i==x1){
                if(j+1==y1)path+="R";
                else if(j-1==y1) path+="L";
            }
            else if(j==y1){
                if(i+1==x1)path+="D";
                else if(i-1==x1)path+="U";
            }
            x1=i;
            y1=j;
            }
            reverse(path.begin(),path.end());
            for(auto it:path){
                cout<<it;
            }
            return 0;
        }
        p.pop();
        for(int i=0;i<4;i++){
            int nrow=x+delrows[i];
            int ncol=y+delcols[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]!='#' && time+1<vis[nrow][ncol] && parent[nrow][ncol]==pair<int,int>{-1,-1}){
                p.push({{nrow,ncol},time+1});
                parent[nrow][ncol]={x,y};
            }
        }
    }
    cout<<"NO"<<endl;
    return 0;

    


}
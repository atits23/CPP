#include<bits/stdc++.h>
using namespace std;
void dfs(int i,int j,vector<vector<char>>&grid,vector<vector<int>>&vis,vector<int>&delrows,vector<int>&delcols){
    vis[i][j]=1;
    for(int k=0;k<4;k++){
        int nrow=i+delrows[k];
        int ncol=j+delcols[k];
        if(nrow>=0 && nrow<grid.size() && ncol>=0 && ncol<grid[0].size() && grid[nrow][ncol]=='.' && !vis[nrow][ncol]){
            dfs(nrow,ncol,grid,vis,delrows,delcols);
        }
    }

}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<char>>grid(n,vector<char>(m));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>grid[i][j];
        }
    }
    vector<vector<int>>vis(n,vector<int>(m,0));
    vector<int>delrows={-1,0,1,0};
    vector<int>delcols={0,1,0,-1};
    int count_rooms=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]=='.' && !vis[i][j]){
                dfs(i,j,grid,vis,delrows,delcols);
                count_rooms++;
            }
        }
    }
    cout<<count_rooms<<endl;

    return 0;
}
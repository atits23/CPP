#include<bits/stdc++.h>
using namespace std;
// int min_counter(int num,int target){
//     if(num<0) return 1e9;
//     if(num==target) return 0;
//     int path_1=1+min_counter(num-1,target);
//     int path_2=1e9;
//     if(num<target){
//     path_2=1+min_counter(num*2,target);
//     return min(path_1,path_2);
//     }

// }
int main(){
    int n,m;
    cin>>n>>m;
    vector<int>dist(max(n,m)*2+1,1e9);
    dist[n]=0;
    queue<int>q;
    q.push(n);
    while(!q.empty()){
        int node=q.front();
        int distance=dist[node];
        if(node==m){
            cout<<distance<<endl;
            return 0;
        }
        q.pop();
        if(node-1>=0 && distance+1<dist[node-1]){
            dist[node-1]=distance+1;
            q.push(node-1);
        }
        if(node<=m && node*2<=max(n,m)*2 && distance+1<dist[node*2]){
            dist[node*2]=distance+1;
            q.push(node*2);
        }
    }
    return 0;
}
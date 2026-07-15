#include<bits/stdc++.h>
using namespace std;
int min_coins(int index,int target,vector<int>&coins,vector<vector<int>>&dp){
    if(index==coins.size()){
        if(target==0){
            return 0;
        }
        return 1e9;
    }
    if(dp[index][target]!=-1){
        return dp[index][target];
    }
    int pick=1e9;
    if(coins[index]<=target){
        pick=1+min_coins(index,target-coins[index],coins,dp);
    }
    int not_pick=min_coins(index+1,target,coins,dp);
    return dp[index][target]=min(pick,not_pick);
}
int main(){
    int n,sum;
    cin>>n>>sum;
    vector<int>coins(n);
    vector<vector<int>>dp(n+1,vector<int>(sum+1,0));
    for(int i=0;i<n;i++){
        cin>>coins[i];
    }
    for(int i=0;i<=sum;i++){
        dp[n][i]=1e9;
    }
    dp[n][0]=0;
    for(int index=n-1;index>=0;index--){
        for(int target=1;target<=sum;target++){
            int pick=1e9;
            if(coins[index]<=target){
                pick=1+dp[index][target-coins[index]];
            }
            int not_pick=dp[index+1][target];
            dp[index][target]=min(pick,not_pick);
        }
    }
    int ans=dp[0][sum];
    if(ans>=1e9){
        cout<<-1<<endl;
    }
    else{
        cout<<ans<<endl;
    }
    return 0;

}